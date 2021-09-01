#ifndef __DUNGEON_H__
#define __DUNGEON_H__

#include <Arduboy2.h>

#include <constants.h>
#include <dices.h>

#include <room.h>

class Dungeon
{
public:
    Dungeon(Arduboy2* ab);
    void initialize();
    void draw();
private:
    Arduboy2* ab;
    uint8_t size;
    uint8_t currentRoom;
    Room* rooms[MAX_DUNGEON_SIZE];
};

#endif