#include <Arduboy2.h>

#include <constants.h>
#include <setup.h>

#include <dungeon.h>

Arduboy2 ab;

Player team[4];
Dungeon dungeon(&ab);

void setup()
{
  ab.begin();
  ab.initRandomSeed();
  ab.setFrameRate(25);
  ab.setTextSize(1);


  Setup* setup = new Setup(&ab, team);
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
  
  ab.display();
}