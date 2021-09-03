#include <setup.h>

Setup::Setup(Arduboy2 *ab, Player **team)
{
  this->ab = ab;
  this->team = team;
}

void Setup::selectTeams()
{
  boolean selected = false;
  uint8_t cursor = 0;
  uint8_t count = 0;
  uint16_t choicess[4];

  while (!selected)
  {
    while (!(ab->nextFrame()))
      ;
    ab->pollButtons();
    if (ab->justPressed(UP_BUTTON) && cursor > 0)
    {
      cursor--;
    }
    if (ab->justPressed(DOWN_BUTTON) && cursor < 7)
    {
      cursor++;
    }
    if (ab->justPressed(A_BUTTON) && count > 0)
    {
      count--;
      free(team[count]);
    }
    if (ab->justPressed(B_BUTTON) && count == TEAM_SIZE && cursor == 7)
    {
      selected = true;
    }
    if (ab->justPressed(B_BUTTON) && count < TEAM_SIZE)
    {
      team[count] = new Player(cursor);
      switch (cursor)
      {
      case WARRIOR:
        choicess[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choicess[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choicess[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choicess[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count]->addEquip(selectEquip(4, choicess));
        break;
      case CLERIC:
        choicess[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choicess[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choicess[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choicess[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count]->addEquip(selectEquip(4, choicess));
        break;
      case ROGUE:
        team[count]->addEquip(ARMOR_LIGHT | WEAPON_ONE_HANDED_LIGHT | WEAPON_SLASHING);
        break;
      case WIZARD:
        team[count]->addEquip(WEAPON_ONE_HANDED_LIGHT | WEAPON_CRUSHING);
        //TODO team[count].spellbook =
        break;
      case BARBARIAN:
        choicess[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choicess[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choicess[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choicess[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count]->addEquip(selectEquip(4, choicess));
        break;
      case ELF:
        choicess[0] = ARMOR_LIGHT | WEAPON_BOW | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choicess[1] = ARMOR_LIGHT | WEAPON_BOW | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        team[count]->addEquip(selectEquip(2, choicess));
        break;
      case DWARF:
        choicess[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choicess[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choicess[2] = ARMOR_HEAVY | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choicess[3] = ARMOR_HEAVY | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count]->addEquip(selectEquip(4, choicess));
        break;
      }
      count++;
      if (count == TEAM_SIZE)
      {
        cursor = 7;
      }
    }

    ab->clear();
    ab->setCursor(0, cursor * 8);
    ab->print(">");
    for (uint8_t i = 0; i < 7; i++)
    {
      ab->setCursor(8, i * 8);
      ab->print(className(i));
    }
    if (count == 4)
    {
      ab->setCursor(8, 56);
      ab->print(F("Ok"));
    }
    for (uint8_t i = 0; i < count; i++)
    {
      ab->setCursor(64, i * 8);
      ab->print(team[i]->getFullClassName());
    }

    ab->display();
  }
};

uint16_t Setup::selectEquip(uint8_t count, uint16_t *choices)
{
  boolean selected = false;
  uint8_t cursor = 0;
  while (!selected)
  {
    while (!(ab->nextFrame()))
      ;

    ab->pollButtons();
    if (ab->justPressed(UP_BUTTON) && cursor > 0)
    {
      cursor--;
    }
    if (ab->justPressed(DOWN_BUTTON) && cursor < count - 1)
    {
      cursor++;
    }
    if (ab->justPressed(B_BUTTON))
    {
      selected = true;
    }

    ab->clear();
    ab->setCursor(0, cursor * 8);
    ab->print(">");

    for (uint8_t i = 0; i < count; i++)
    {
      ab->setCursor(8, i * 8);
      if (choices[i] & ARMOR_LIGHT)
      {
        ab->print(F("LtArm "));
      }
      if (choices[i] & ARMOR_HEAVY)
      {
        ab->print(F("HvArm "));
      }
      if (choices[i] & WEAPON_BOW)
      {
        ab->print(F("Bow "));
      }
      if (choices[i] & ARMOR_SHIELD)
      {
        ab->print(F("Shield "));
      }
      if (choices[i] & WEAPON_ONE_HANDED)
      {
        ab->print(F("1H "));
      }
      if (choices[i] & WEAPON_TWO_HANDED)
      {
        ab->print(F("2H "));
      }
      if (choices[i] & WEAPON_SLASHING)
      {
        ab->print(F("Slash"));
      }
      if (choices[i] & WEAPON_CRUSHING)
      {
        ab->print(F("Crush"));
      }
    }
    ab->display();
  }
  return choices[cursor];
}
