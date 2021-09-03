#ifndef __ROOM_H__
#define __ROOM_H__

#include <Arduboy2.h>
#include <constants.h>

#define ROOM_CORRIDOR_FLAG 0b0000001
#define ROOM_DOOR_N_FLAG 0b0000010
#define ROOM_DOOR_E_FLAG 0b0000100
#define ROOM_DOOR_S_FLAG 0b0001000
#define ROOM_DOOR_W_FLAG 0b0010000
#define ROOM_ENTRANCE_FLAG 0b01000000

#define ROOM_NOTHING 0b00000000
#define ROOM_GATHEWAY 0b00000001
#define ROOM_DOOR 0b00000010
#define ROOM_WALL 0b00000011

class Room;

class Door
{
public:
    Door(uint8_t x, uint8_t y);

public:
    uint8_t x, y;

private:
    Room *room;
};

class Room
{
public:
    Room(Arduboy2 *ab, uint8_t pattern);
    void draw();
    bool isCorridor();
    uint8_t getDrawStartX();
    uint8_t getDrawStartY();

public:
    uint8_t doorCount;
    Door *door[4];

private:
    Arduboy2 *ab;
    uint8_t flags;
    uint16_t i_data;

    void initDoors();

    void drawDoorH(uint8_t x, uint8_t y);
    void drawDoorV(uint8_t x, uint8_t y);
    void drawWall(uint8_t x, uint8_t y);

    uint8_t data(uint8_t x, uint8_t y);
    bool isDoor(uint8_t x, uint8_t y);
    uint8_t width();
    uint8_t height();
};

#endif