#include <room.h>

Room::Room(Arduboy2 *ab, uint8_t pattern)
{
    this->pattern = pattern;
    if (pattern == 3 || pattern == 4 || pattern == 5 || pattern == 11 || pattern == 12 || pattern == 13 || pattern == 14 || pattern == 32 || pattern == 33 || pattern == 42 || pattern == 45 || pattern == 51 || pattern == 53 || pattern == 55 || pattern == 62 || pattern == 63 || pattern == 65)
    {
        this->flags |= ROOM_CORRIDOR_FLAG;
    }
    this->ab = ab;
}

void Room::drawDoorH(uint8_t x, uint8_t y)
{
    ab->drawRect(x * 8, y * 8 + 2, 8, 4);
}

void Room::drawWallH(uint8_t x, uint8_t y)
{
    ab->fillRect(x * 8, y * 8 + 1, 8, 6);
}

void Room::drawWallV(uint8_t x, uint8_t y)
{
    ab->fillRect(x * 8 + 1, y * 8, 6, 8);
}

void Room::drawCorner(uint8_t x, uint8_t y)
{
    ab->fillRoundRect(x * 8, y * 8, 8, 8, 1);
}

void Room::drawExit(uint8_t x, uint8_t y)
{
    ab->drawChar(x * 8 + 1, y * 8, 'e', 1, 0, 1);
}

void Room::draw()
{
    switch (pattern)
    {
    case 1:
    default:
        drawCorner(0, 2);
        drawDoorH(1, 2);
        drawWallH(2, 2);
        drawWallH(3, 2);
        drawWallH(4, 2);
        drawDoorH(5, 2);
        drawWallH(6, 2);
        drawWallH(7, 2);
        drawWallH(8, 2);
        drawDoorH(9, 2);
        drawCorner(10, 2);
        drawWallV(0, 3);
        drawWallV(10, 3);
        drawWallV(0, 4);
        drawWallV(10, 4);
        drawCorner(0, 5);
        drawWallH(1, 5);
        drawWallH(2, 5);
        drawWallH(3, 5);
        drawWallH(4, 5);
        drawExit(5, 5);
        drawWallH(6, 5);
        drawWallH(7, 5);
        drawWallH(8, 5);
        drawWallH(9, 5);
        drawCorner(10, 5);
        break;
    }
}

bool Room::isCorridor()
{
    return this->flags & ROOM_CORRIDOR_FLAG;
}