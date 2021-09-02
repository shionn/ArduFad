#ifndef __SETUP_H__
#define __SETUP_H__

#include <Arduboy2.h>

#include <constants.h>
#include <dices.h>
#include <player.h>

class Setup
{
public:
    Setup(Arduboy2 *ab, Player *team);
    void selectTeams();

private:
    Arduboy2 *ab;
    Player *team;

    uint16_t selectEquip(uint8_t count, uint16_t *choices);
};

#endif