#ifndef __ROOM_H__
#define __ROOM_H__

#include <Arduboy2.h>
#include <constants.h>

#define ROOM_CORRIDOR_FLAG 0b0000001

#define ROOM_NOTHING 0b00000000
#define ROOM_GATHEWAY 0b00000001
#define ROOM_DOOR 0b00000010
#define ROOM_WALL 0b00000011

// rien      00
// Passage   01
// porte H/V 10
// mur       11

const uint8_t room_data[] PROGMEM = {
	1, 9, 4, 0b11101111, 0b10111110, 0b11110000, 0b00000000, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111, 
	2, 7, 6, 0b00001101, 0b11000011, 0b11110011, 0b11111000, 0b00000000, 0b0000, 0b00000010, 0b000000, 0b000011, 0b11110011, 0b11110000, 
	3, 9, 4, 0b11011111, 0b01111101, 0b11110011, 0b11001111, 0b00111100, 0b00000000, 0b00001111, 0b11111100, 0b11111111, 
	4, 7, 4, 0b11011111, 0b11011111, 0b00111111, 0b00111100, 0b00000000, 0b11111100, 0b00001111, 
	5, 5, 5, 0b11110111, 0b11111100, 0b11110100, 0b00000111, 0b11001111, 0b11110011, 0b11000000, 
	6, 7, 7, 0b11111111, 0b11111101, 0b00000000, 0b00011111, 0b11000011, 0b11111100, 0b00001111, 0b11110000, 0b00111111, 0b11110000, 0b11110000 };

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
    uint16_t i_data;

    void drawDoorH(uint8_t x, uint8_t y);
    void drawDoorV(uint8_t x, uint8_t y);
    void drawWall(uint8_t x, uint8_t y);

    uint8_t data(uint8_t x, uint8_t y);
    uint8_t width();
    uint8_t height();
};

#endif