#ifndef __ROOM_H__
#define __ROOM_H__

#include <Arduboy2.h>

#define ROOM_START_FLAG 0b0000001
#define ROOM_CORRIDOR_FLAG 0b0000010

// rien  00
// mur   01
// porte 10
// entee 11

const uint8_t room_data[] PROGMEM = {
    1, 9, 4, 0b01100101, 0b10010110, 0b01010000, 0b00000000, 0b00010100, 0b00000000, 0b00000101, 0b01010111, 0b01010101};

class Room
{
public:
    Room(Arduboy2 *ab, uint8_t pattern);
    void draw();
    bool isCorridor();

private:
    Arduboy2 *ab;
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