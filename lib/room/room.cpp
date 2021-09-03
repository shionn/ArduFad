#include <room.h>

const uint8_t room_data[] PROGMEM = {
    1, 9, 4, 0, 0b11101111, 0b10111110, 0b11110000, 0b00000000, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111,                          //
    2, 7, 6, 0, 0b00001101, 0b11000011, 0b11110011, 0b11111000, 0b00000000, 0b11110000, 0b00000010, 0b11000000, 0b00001111, 0b11110011, 0b11110000,  //
    3, 9, 4, 1, 0b11011111, 0b01111101, 0b11110011, 0b11001111, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111,                          //
    4, 7, 4, 1, 0b11011111, 0b11011111, 0b00111111, 0b00111100, 0b00000000, 0b11111100, 0b00001111,                                                  //
    5, 5, 5, 1, 0b11110111, 0b11111100, 0b11110100, 0b00000111, 0b11001111, 0b11110011, 0b11000000,                                                  //
    6, 7, 6, 0, 0b11111111, 0b11111101, 0b00000000, 0b00011111, 0b11000011, 0b11111100, 0b00001111, 0b11110000, 0b00111111, 0b11110000, 0b11110000,  //
    11, 3, 5, 1, 0b11111111, 0b00101100, 0b11100011, 0b11011100,                                                                                     //
    12, 3, 5, 1, 0b11101111, 0b00111100, 0b11110011, 0b11101100,                                                                                     //
    13, 6, 6, 0, 0b11111110, 0b11111000, 0b00000011, 0b11111111, 0b00111100, 0b00000011, 0b11000000, 0b00011111, 0b11111111,                         //
    14, 3, 6, 1, 0b11111101, 0b00101100, 0b11110011, 0b01001011, 0b11110000,                                                                         //
    15, 6, 5, 0, 0b11101111, 0b11111100, 0b00111111, 0b11000000, 0b00111000, 0b00000011, 0b11111111, 0b10110000,                                     //
    16, 5, 5, 0, 0b11111011, 0b11110000, 0b00111100, 0b00001111, 0b11001111, 0b11110111, 0b11000000,                                                 //
    21, 5, 5, 0, 0b11111111, 0b11110000, 0b00111100, 0b00001111, 0b00000011, 0b11111011, 0b11000000,                                                 //
    22, 5, 5, 0, 0b11111011, 0b11110000, 0b00111000, 0b00001111, 0b00000011, 0b11110111, 0b11000000,                                                 //
    23, 7, 6, 0, 0b11111111, 0b11111111, 0b11110000, 0b00111000, 0b00000000, 0b10111111, 0b00000011, 0b11111100, 0b00001111, 0b11111111, 0b11110000, //
    24, 5, 6, 0, 0b11111011, 0b11111100, 0b11111000, 0b00001111, 0b00000011, 0b11110011, 0b11111110, 0b11110000,                                     //
    25, 6, 6, 0, 0b11111111, 0b11111111, 0b00000011, 0b11110000, 0b00110100, 0b00000010, 0b11110000, 0b00111111, 0b11111111,                         //
    26, 3, 4, 1, 0b11111110, 0b00111100, 0b10111111,                                                                                                 //
    31, 5, 5, 0, 0b11111110, 0b11111100, 0b00111111, 0b00001111, 0b00000011, 0b11101111, 0b11000000,                                                 //
    32, 5, 6, 1, 0b11111111, 0b11111100, 0b00101111, 0b00111111, 0b11001111, 0b10000000, 0b10111111, 0b11110000,                                     //
    33, 3, 5, 1, 0b11101111, 0b00111000, 0b11110011, 0b11111100,                                                                                     //
    34, 7, 5, 0, 0b11111110, 0b11111111, 0b11000000, 0b11111100, 0b00000000, 0b11111100, 0b00001111, 0b11111110, 0b11111100,                         //
    35, 7, 5, 0, 0b11011111, 0b11111111, 0b00000000, 0b00111111, 0b00000000, 0b11111100, 0b00000011, 0b11111111, 0b11111100,                         //
    36, 5, 6, 0, 0b11111111, 0b11111100, 0b00101000, 0b00001111, 0b00000011, 0b10000011, 0b11111111, 0b11110000,                                     //
    41, 5, 6, 0, 0b11101111, 0b11110011, 0b11111100, 0b00001111, 0b00000011, 0b11000000, 0b11111110, 0b11110000,                                     //
    42, 5, 4, 1, 0b11111101, 0b11110000, 0b00111100, 0b11111111, 0b01111111,                                                                         //
    43, 5, 5, 0, 0b11111110, 0b11110000, 0b00111100, 0b00001111, 0b00000011, 0b11110111, 0b11000000,                                                 //
    44, 6, 6, 0, 0b11111111, 0b11111111, 0b11000010, 0b11000000, 0b00111100, 0b00000011, 0b11110011, 0b11111111, 0b10111111,                         //
    45, 6, 5, 1, 0b11111101, 0b11111111, 0b11001111, 0b01000000, 0b00011111, 0b11001111, 0b11111101, 0b11110000,                                     //
    46, 5, 6, 0, 0b11111011, 0b11110000, 0b00111100, 0b00001111, 0b00000011, 0b11110011, 0b11111101, 0b11110000,                                     //
    51, 5, 5, 1, 0b11101110, 0b11110011, 0b00111100, 0b00001111, 0b11001111, 0b11111011, 0b11000000,                                                 //
    52, 6, 6, 0, 0b11111011, 0b11111111, 0b00111111, 0b11000000, 0b11111000, 0b00000001, 0b11000000, 0b11111111, 0b01111111,                         //
    53, 3, 3, 1, 0b11111110, 0b00011101, 0b11000000,                                                                                                 //
    54, 6, 5, 0, 0b11111111, 0b11111100, 0b00001111, 0b11000000, 0b00011100, 0b00001111, 0b11111011, 0b11110000,                                     //
    55, 6, 3, 1, 0b11111111, 0b10111100, 0b00000001, 0b11011111, 0b11110000,                                                                         //
    56, 7, 6, 0, 0b11111111, 0b10111111, 0b11110000, 0b00111100, 0b00000000, 0b11100000, 0b00000011, 0b11000000, 0b00001111, 0b11111011, 0b11110000, //
    61, 5, 5, 0, 0b11101111, 0b11110000, 0b00111100, 0b00001011, 0b00000011, 0b11111011, 0b11000000,                                                 //
    62, 5, 5, 1, 0b11110111, 0b11111100, 0b11110100, 0b00000111, 0b11001111, 0b11110111, 0b11000000,                                                 //
    63, 3, 5, 1, 0b11011111, 0b00111000, 0b10110011, 0b11011100,                                                                                     //
    64, 5, 5, 0, 0b11111011, 0b11110000, 0b00111100, 0b00001111, 0b11001111, 0b11110111, 0b11000000,                                                 //
    65, 5, 5, 1, 0b11101111, 0b11110011, 0b11111100, 0b00001111, 0b11110011, 0b11111110, 0b11000000,                                                 //
    66, 6, 5, 0, 0b11111110, 0b11111111, 0b00000011, 0b10000000, 0b00111111, 0b00000011, 0b11111110, 0b11110000};

Door::Door(uint8_t x, uint8_t y, uint8_t flag)
{
    this->x = x;
    this->y = y;
    this->flag = flag;
}

bool Door::isDir(uint8_t dir)
{
    return getDir() == dir;
}

uint8_t Door::getDir()
{
    return this->flag & 0b00000011;
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
    initDoors();
    this->ab = ab;
}

Room::~Room()
{
    for (uint8_t d = 0; d < doorCount; d++)
        delete door[d];
}

void Room::initDoors()
{
    uint8_t w = width();
    uint8_t h = height();
    for (int8_t x = 1; x < w; x++)
        if (isDoor(x, h - 1))
        {
            flags |= ROOM_DOOR_S_FLAG;
            door[doorCount++] = new Door(x, h - 1, DOOR_S);
        }
    for (int8_t y = h - 1; y > 0; y--)
        if (isDoor(0, y))
        {
            flags |= ROOM_DOOR_W_FLAG;
            door[doorCount++] = new Door(0, y, DOOR_W);
        }
    for (int8_t y = h - 1; y > 0; y--)
        if (isDoor(w - 1, y))
        {
            flags |= ROOM_DOOR_E_FLAG;
            door[doorCount++] = new Door(w - 1, y, DOOR_E);
        }
    for (int8_t x = 1; x < w; x++)
        if (isDoor(x, 0))
        {
            flags |= ROOM_DOOR_N_FLAG;
            door[doorCount++] = new Door(x, 0, DOOR_N);
        }
}

Room *Room::open(uint8_t d)
{
    if (door[d]->room)
        return door[d]->room;
    uint8_t s = ROOM_DOOR_N_FLAG << (door[d]->getDir() ^ 0b00000011);
    door[d]->room = new Room(ab, D66());
    while (!door[d]->room->is(s))
    {
        delete door[d]->room;
        door[d]->room = new Room(ab, D66());
    }
    uint8_t destDoor = door[d]->room->getFirstDoorIndex(door[d]->getDir() ^ 0b00000011);
    door[d]->room->door[destDoor]->room = this;
    return door[d]->room;
}

void Room::drawDoorH(uint8_t x, uint8_t y) { ab->drawRect(getDrawStartX() + x * 8, getDrawStartY() + y * 8 + 2, 8, 4); }
void Room::drawDoorV(uint8_t x, uint8_t y) { ab->drawRect(getDrawStartX() + x * 8 + 2, getDrawStartY() + y * 8, 4, 8); }
void Room::drawWall(uint8_t x, uint8_t y) { ab->fillRect(getDrawStartX() + x * 8, getDrawStartY() + y * 8, 8, 8); }

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
uint8_t Room::getNextDoorIndex(uint8_t dir, uint8_t start, uint8_t def)
{
    for (uint8_t i = start + 1; i < doorCount; i++)
        if (door[i]->isDir(dir))
            return i;
    if (def == 255)
        return start;
    return def;
}

uint8_t Room::getPrevDoorIndex(uint8_t dir, uint8_t start, uint8_t def)
{
    if (start > 0)
        for (int8_t i = start - 1; i >= 0; i--)
            if (door[i]->isDir(dir))
                return i;
    if (def == 255)
        return start;
    return def;
}

uint8_t Room::getFirstDoorIndex(uint8_t dir, uint8_t def)
{
    for (uint8_t i = 0; i < doorCount; i++)
        if (door[i]->isDir(dir))
            return i;
    return def;
}

uint8_t Room::getDrawStartX() { return MAP_ZONE_CENTER_X - width() * 4; }
uint8_t Room::getDrawStartY() { return MAP_ZONE_CENTER_Y - height() * 4; }
uint8_t Room::pattern() { return pgm_read_byte(room_data + i_data); }
uint8_t Room::width() { return pgm_read_byte(room_data + i_data + 1); }
uint8_t Room::height() { return pgm_read_byte(room_data + i_data + 2); }
bool Room::isCorridor() { return this->flags & ROOM_CORRIDOR_FLAG; }
bool Room::is(uint8_t f) { return this->flags & f; }
bool Room::isDoor(uint8_t x, uint8_t y)
{
    uint8_t d = data(x, y);
    return d == ROOM_DOOR || d == ROOM_GATHEWAY;
}