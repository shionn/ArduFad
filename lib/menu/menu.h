#ifndef __MENU_H__
#define __MENU_H__

#include <Arduboy2.h>
#include <Font3x5.h>

#include <room.h>
#include <player.h>

class Menu
{
public:
    Menu(Arduboy2 *ab, Player **team, Font3x5 *font);
    void draw(Room *room);
    Room *updade(Room *room);

private:
    Arduboy2 *ab;
    Player **team;
    uint8_t cursor;
    Font3x5 *font;

    void drawButton(uint8_t x, uint8_t y, String text, bool selected = false);
};

#endif