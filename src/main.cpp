#include <Arduboy2.h>
// #include <Tinyfont.h>
#include <Font3x5.h>

#include <constants.h>
#include <setup.h>

#include <room.h>

Arduboy2 ab;
// Tinyfont tinyfont = Tinyfont(ab.sBuffer, Arduboy2::width(), Arduboy2::height());
Font3x5 font = Font3x5();

Player *team[TEAM_SIZE];
Room *room;

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
}

void loop()
{
  if (!(ab.nextFrame()))
    return;

  ab.clear();
  room->draw();
  ab.drawFastHLine(0, 49, 127);
  ab.drawFastVLine(96, 0, 49);

  // affichage de l'equipe
  for (uint8_t i = 0; i < TEAM_SIZE; i++)
  {
    font.setCursor(98, i * 6);
    font.print(team[i]->getShortClassName());
    font.setCursor(104, i * 6);
    font.print(team[i]->getHp());
    font.print('/');
    font.print(team[i]->getMaxHp());
  }

  font.setCursor(1, 50);
  ab.fillRect(0, 50, 7 * 4 + 1, 7);
  font.setTextColor(0);
  font.print("Attaque");
  font.setTextColor(1);

  font.setCursor(64, 50);
  font.print("Fuir");

  font.setCursor(1, 57);
  font.print("Explorer");

  font.setTextColor(0);
  ab.fillRect(63, 57, 6 * 4 + 1, 7);
  font.setCursor(64, 57);
  font.print("Sortir");
  font.setTextColor(1);

  ab.display();
}