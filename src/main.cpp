#include <Arduboy2.h>
#include <Tinyfont.h>

#include <constants.h>
#include <setup.h>

#include <dungeon.h>

Arduboy2 ab;
Tinyfont tinyfont = Tinyfont(ab.sBuffer, Arduboy2::width(), Arduboy2::height());

Player team[TEAM_SIZE];
Dungeon dungeon(&ab);

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
  dungeon.initialize();
}

void loop()
{

  // pause render until it's time for the next frame
  if (!(ab.nextFrame()))
    return;

  ab.clear();
  dungeon.draw();
  ab.drawFastHLine(0, 53, 127);
  tinyfont.setCursor(0, 55);
  tinyfont.print("Attaque");
  tinyfont.setTextColor(1);
  tinyfont.setCursor(63, 55);
  tinyfont.print("Fuir");
  tinyfont.setCursor(0, 60);
  tinyfont.print("Explorer");
  tinyfont.setCursor(63, 60);
  tinyfont.print("W 21/34");

  ab.drawFastVLine(96, 0, 53);
  tinyfont.setCursor(98, 0);
  tinyfont.print("W");
  tinyfont.setCursor(98+6, 0);
  tinyfont.print("21/34");
  tinyfont.setCursor(98, 5);
  tinyfont.print("W21/34");
  tinyfont.setCursor(98, 10);
  tinyfont.print("W21/34");
  tinyfont.setCursor(98, 15);
  tinyfont.print("W21/34");


  ab.display();
}