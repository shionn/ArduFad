#ifndef __ROOM_H__
#define __ROOM_H__

#include <Arduboy2.h>
#include <constants.h>
#include <dices.h>

#define ROOM_CORRIDOR_FLAG 0b0000001
#define ROOM_DOOR_N_FLAG 0b0000010
#define ROOM_DOOR_W_FLAG 0b0000100
#define ROOM_DOOR_E_FLAG 0b0001000
#define ROOM_DOOR_S_FLAG 0b0010000
#define ROOM_ENTRANCE_FLAG 0b01000000

#define ROOM_NOTHING 0b00000000
#define ROOM_GATHEWAY 0b00000001
#define ROOM_DOOR 0b00000010
#define ROOM_WALL 0b00000011

#define DOOR_N 0b00000000
#define DOOR_W 0b00000001
#define DOOR_E 0b00000010
#define DOOR_S 0b00000011

class Room;

class Door
{
public:
    Door(uint8_t x, uint8_t y, uint8_t flag);
    bool isDir(uint8_t dir);
    uint8_t getDir();
    uint8_t x, y;
    Room *room = NULL;

private:
    uint8_t flag;
};

class Room
{
public:
    Room(Arduboy2 *ab, uint8_t pattern);
    ~Room();
    void draw();
    bool isCorridor();
    bool is(uint8_t f);
    uint8_t pattern();
    Room *open(uint8_t x);

    uint8_t getDrawStartX();
    uint8_t getDrawStartY();
    uint8_t getNextDoorIndex(uint8_t dir, uint8_t start = 0, uint8_t def = 255);
    uint8_t getPrevDoorIndex(uint8_t dir, uint8_t start = 0, uint8_t def = 255);
    uint8_t getFirstDoorIndex(uint8_t dir, uint8_t def = 255);

public:
    uint8_t doorCount = 0;
    Door *door[4] = {NULL, NULL, NULL, NULL};

private:
    Arduboy2 *ab;
    uint8_t flags;
    uint16_t i_data;

    void initDoors();
    void initContent();

    void drawDoorH(uint8_t x, uint8_t y);
    void drawDoorV(uint8_t x, uint8_t y);
    void drawWall(uint8_t x, uint8_t y);

    uint8_t data(uint8_t x, uint8_t y);
    bool isDoor(uint8_t x, uint8_t y);
    uint8_t width();
    uint8_t height();
};

#endif