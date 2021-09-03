#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <Arduboy2.h>
#include <dices.h>

#define WARRIOR 0
#define CLERIC 1
#define ROGUE 2
#define WIZARD 3
#define BARBARIAN 4
#define ELF 5
#define DWARF 6

struct PlayerData_t
{
    char fullName[10];
    char shortName;
    uint8_t baseHp;
    uint8_t baseGold;
};

class Player
{
public:
    Player(uint8_t type);
    void addEquip(uint16_t equip);
    String getFullClassName();
    char getShortClassName();

    uint8_t getHp();
    uint8_t getMaxHp();

private:
    PlayerData_t getPlayerData();
    uint8_t type;
    uint8_t lvl;
    uint8_t gold;
    uint8_t hp;
    uint16_t equip;
    uint8_t bag;
    uint8_t spellbook;
    uint8_t spellcount;
};

String className(uint8_t clazz);

#endif