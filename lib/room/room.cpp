#include <room.h>

Room::Room(Arduboy2 *ab, uint8_t pattern)
{
#ifdef DEBUG
    Serial.print("pattern " + pattern);
    Serial.println(pattern);
#endif
    this->i_data = 0;
    while (pgm_read_byte(room_data + i_data) != pattern)
    {
        uint8_t w = pgm_read_byte(room_data + i_data + 1);
        uint8_t h = pgm_read_byte(room_data + i_data + 2);
#ifdef DEBUG
        Serial.print(i_data);
        Serial.print(" W ");
        Serial.print(w);
        Serial.print(" H ");
        Serial.println(h);
#endif
        this->i_data += (w * h) / 4 + ((w * h) % 4 ? 1 : 0) + 3;
    }
    if (pattern == 3 || pattern == 4 || pattern == 5 || pattern >= 11 && pattern <= 14 || pattern == 26 || pattern == 32 || pattern == 33 || pattern == 42 || pattern == 45 || pattern == 51 || pattern == 53 || pattern == 55 || pattern == 62 || pattern == 63 || pattern == 65)
    {
        this->flags |= ROOM_CORRIDOR_FLAG;
    }
    this->ab = ab;
}

void Room::drawDoorH(uint8_t x, uint8_t y)
{
    ab->drawRect(x * 8, y * 8 + 2, 8, 4);
}

void Room::drawDoorV(uint8_t x, uint8_t y)
{
    ab->drawRect(x * 8 + 2, y * 8, 4, 8);
}

void Room::drawWall(uint8_t x, uint8_t y)
{
    ab->fillRect(x * 8, y * 8, 8, 8);
}

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
    uint8_t c = pgm_read_byte(room_data + i_data + 3 + i / 4);
    c = c >> (3 - (i % 4)) * 2;
    return c & 0b00000011;
}

uint8_t Room::width()
{
    return pgm_read_byte(room_data + i_data + 1);
}

uint8_t Room::height()
{
    return pgm_read_byte(room_data + i_data + 2);
}

bool Room::isCorridor()
{
    return this->flags & ROOM_CORRIDOR_FLAG;
}