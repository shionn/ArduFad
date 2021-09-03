#include <room.h>

const uint8_t room_data[] PROGMEM = {
    1, 9, 4, 0, 0b11101111, 0b10111110, 0b11110000, 0b00000000, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111,                          //
    2, 7, 6, 0, 0b00001101, 0b11000011, 0b11110011, 0b11111000, 0b00000000, 0b11110000, 0b00000010, 0b11000000, 0b00001111, 0b11110011, 0b11110000,  //
    3, 9, 4, 1, 0b11011111, 0b01111101, 0b11110011, 0b11001111, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111,                          //
    4, 7, 4, 1, 0b11011111, 0b11011111, 0b00111111, 0b00111100, 0b00000000, 0b11111100, 0b00001111,                                                  //
    5, 5, 5, 1, 0b11110111, 0b11111100, 0b11110100, 0b00000111, 0b11001111, 0b11110011, 0b11000000,                                                  //
    6, 7, 7, 0, 0b11111111, 0b11111101, 0b00000000, 0b00011111, 0b11000011, 0b11111100, 0b00001111, 0b11110000, 0b00111111, 0b11110000, 0b11110000,  //
    11, 3, 5, 1, 0b11111111, 0b00101100, 0b11100011, 0b11011100,                                                                                     //
    12, 3, 5, 1, 0b11101111, 0b00111100, 0b11110011, 0b11101100,                                                                                     //
    13, 6, 7, 1, 0b11111110, 0b11111000, 0b00000011, 0b11111111, 0b00111100, 0b00000011, 0b11001111, 0b11111100, 0b00000001, 0b11111111, 0b11110000, //
    14, 3, 7, 1, 0b11111101, 0b00101100, 0b11110011, 0b11001101, 0b00101111, 0b11000000,                                                             //
    15, 6, 5, 0, 0b11101111, 0b11111100, 0b00111111, 0b11000000, 0b00111000, 0b00000011, 0b11111111, 0b10110000,                                     //
    16, 5, 5, 0, 0b11111011, 0b11110000, 0b00111100, 0b00001111, 0b11001111, 0b11110111, 0b11000000,                                                 //
    21, 5, 5, 0, 0b11111111, 0b11110000, 0b00111100, 0b00001111, 0b00000011, 0b11111011, 0b11000000,                                                 //
    22, 5, 5, 0, 0b11111011, 0b11110000, 0b00111000, 0b00001111, 0b00000011, 0b11110111, 0b11000000,                                                 //
    23, 7, 6, 0, 0b11111111, 0b11111111, 0b11110000, 0b00111000, 0b00000000, 0b10111111, 0b00000011, 0b11111100, 0b00001111, 0b11111111, 0b11110000, //
    24, 5, 6, 0, 0b11111011, 0b11111100, 0b11111000, 0b00001111, 0b00000011, 0b11110011, 0b11111110, 0b11110000,                                     //
    25, 6, 6, 0, 0b11111111, 0b11111111, 0b00000011, 0b11110000, 0b00110100, 0b00000010, 0b11110000, 0b00111111, 0b11111111,                         //
    26, 3, 4, 1, 0b11111110, 0b00111100, 0b10111111,                                                                                                 //
};

Door::Door(uint8_t x, uint8_t y)
{
    this->x = x;
    this->y = y;
}

Room::Room(Arduboy2 *ab, uint8_t pattern)
{
    i_data = 0;
    while (pgm_read_byte(room_data + i_data) != pattern)
    {
        uint8_t w = width();
        uint8_t h = height();
        i_data += (w * h) / 4 + ((w * h) % 4 ? 1 : 0) + 4;
    }
    flags = pgm_read_byte(room_data + i_data + 3);
    this->ab = ab;
}

void Room::initDoors()
{
    uint8_t w = width();
    uint8_t h = height();
    for (int x = 0; x < w; x++)
    {
        if (isDoor(x, 0))
        {
            flags |= ROOM_DOOR_N_FLAG;
            door[doorCount++] = new Door(x, 0);
        }
        if (isDoor(x, h - 1))
        {
            flags |= ROOM_DOOR_S_FLAG;
            door[doorCount++] = new Door(x, h - 1);
        }
    }
    for (int y = 0; y < h; y++)
    {
        if (isDoor(0, y))
        {
            flags |= ROOM_DOOR_W_FLAG;
            door[doorCount++] = new Door(0, y);
        }
        if (isDoor(w - 1, y))
        {
            flags |= ROOM_DOOR_E_FLAG;
            door[doorCount++] = new Door(w - 1, y);
        }
    }
}

void Room::drawDoorH(uint8_t x, uint8_t y) { ab->drawRect(48 - width() * 4 + x * 8, 24 - height() * 4 + y * 8 + 2, 8, 4); }
void Room::drawDoorV(uint8_t x, uint8_t y) { ab->drawRect(48 - width() * 4 + x * 8 + 2, 24 - height() * 4 + y * 8, 4, 8); }
void Room::drawWall(uint8_t x, uint8_t y) { ab->fillRect(48 - width() * 4 + x * 8, 24 - height() * 4 + y * 8, 8, 8); }

void Room::draw()
{
    for (uint8_t y = 0; y < height(); y++)
        for (uint8_t x = 0; x < width(); x++)
        {
            uint8_t c = data(x, y);
            if (c == ROOM_DOOR)
                if (x == 0 || x == width() - 1)
                    drawDoorV(x, y);
                else
                    drawDoorH(x, y);
            else if (c == ROOM_WALL)
                drawWall(x, y);
        }
}

uint8_t Room::data(uint8_t x, uint8_t y)
{
    uint8_t i = y * width() + x;
    uint8_t c = pgm_read_byte(room_data + i_data + 4 + i / 4);
    c = c >> (3 - (i % 4)) * 2;
    return c & 0b00000011;
}

uint8_t Room::width() { return pgm_read_byte(room_data + i_data + 1); }

uint8_t Room::height() { return pgm_read_byte(room_data + i_data + 2); }
bool Room::isCorridor() { return this->flags & ROOM_CORRIDOR_FLAG; }