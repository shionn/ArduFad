#include <dungeon.h>

Dungeon::Dungeon(Arduboy2 *ab)
{
    this->size = 0;
    this->ab = ab;
};

void Dungeon::initialize()
{
    this->rooms[0] = new Room(ab, D6());
    this->size = 1;
    this->currentRoom = 0;
};

void Dungeon::draw() {
    rooms[currentRoom]->draw();
};