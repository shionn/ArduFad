#ifndef __ROOM_H__
#define __ROOM_H__

#include <Arduboy2.h>

#define ROOM_START_FLAG 0b0000001
#define ROOM_CORRIDOR_FLAG 0b0000010

class Room
{
public:
    Room(Arduboy2* ab, uint8_t pattern);
    void draw();
    bool isCorridor();
private:
    Arduboy2* ab;
    uint8_t pattern;
    uint8_t flags;

    void drawDoorH(uint8_t x, uint8_t y);
    void drawDoorV(uint8_t x, uint8_t y);
    void drawCorner(uint8_t x, uint8_t y);
    void drawWallH(uint8_t x, uint8_t y);
    void drawWallV(uint8_t x, uint8_t y);
    void drawExit(uint8_t x, uint8_t y);

};

#endif