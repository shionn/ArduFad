#include <Arduboy2.h>
// #include <Tinyfont.h>
#include <Font3x5.h>

#include <constants.h>
#include <setup.h>

#include <room.h>
#include <player.h>
#include <menu.h>

Arduboy2 ab;
Font3x5 font = Font3x5();

Player *team[TEAM_SIZE];
Room *room;
Menu menu(&ab, team, &font);

void setup()
{
#ifdef DEBUG
  Serial.begin(9600);
#endif

  ab.begin();
  ab.initRandomSeed();
  ab.setFrameRate(25);
  ab.setTextSize(1);

  Setup *setup = new Setup(&ab, team);
  setup->selectTeams();
  //setup->buyequip
  free(setup);
  room = new Room(&ab, D6());
#ifdef DEBUG
  Serial.println("== end init ==");
#endif
}

void loop()
{
  if (!(ab.nextFrame()))
    return;

  ab.pollButtons();
  room = menu.updade(room);

  ab.clear();
  ab.drawFastHLine(0, 49, 127);
  ab.drawFastVLine(27, 0, 49);
  ab.drawFastVLine(LEFT_PANE_X, 0, 49);
  room->draw();
  menu.draw(room);
  ab.display();
}