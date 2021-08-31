#include <Arduboy2.h>

#define WARRIOR 0
#define CLERIC 1
#define ROGUE 2
#define WIZARD 3
#define BARBARIAN 4
#define ELF 5
#define DWARF 6

#define ARMOR_LIGHT 0b0000000000000001
#define ARMOR_HEAVY 0b0000000000000010
#define ARMOR_SHIELD 0b0000000000000100

#define WEAPON_ONE_HANDED 0b0000000100000000
#define WEAPON_TWO_HANDED 0b0000001000000000
#define WEAPON_ONE_HANDED_LIGHT 0b0000010000000000
#define WEAPON_CRUSHING 0b0000100000000000
#define WEAPON_SLASHING 0b0001000000000000
#define WEAPON_BOW 0b0010000000000000
#define WEAPON_SLING 0b0100000000000000

#define BAG_BANDAGE 0b00000001
#define BAG_HOLY_WATER_VIAL 0b00000010
#define BAG_POTION_OF_HEALING 0b00000100
#define BAG_LANTERN 0b00001000
#define BAG_ROPE 0b00010000
#define BAG_LOCK_PICKS 0b00100000
#define BAG_SPELL_BOOK 0b01000000

#define SPELL_BLESSING 0b00000001

Arduboy2 arduboy;

typedef struct
{
  uint8_t clazz;
  uint8_t lvl;
  uint8_t gold;
  uint8_t pv;
  uint16_t equip;
  uint8_t bag;
  uint8_t spellbook;
  uint8_t spellcount;
} Player;

Player team[4];

uint8_t D6(boolean ex = false)
{
  uint8_t r = random(1, 6);
  while (!(r % 6) && ex)
  {
    r += random(1, 6);
  }
  return r;
}

uint8_t D66()
{
  return D6() * 10 + D6();
}

uint8_t XD6(uint8_t x)
{
  uint8_t r = 0;
  for (uint8_t i = 0; i < x; i++)
  {
    r += D6();
  }
  return r;
}

uint8_t D6Lvl(Player p)
{
  return D6(true) + p.lvl;
}

uint8_t D6HalfLvl(Player p)
{
  return D6(true) + p.lvl << 1;
}

String className(uint8_t clazz)
{
  switch (clazz)
  {
  case WARRIOR:
    return F("Warrior");
  case CLERIC:
    return F("Cleric");
  case ROGUE:
    return F("Rogue");
  case WIZARD:
    return F("Wizard");
  case BARBARIAN:
    return F("Barbarian");
  case ELF:
    return F("Elf");
  case DWARF:
    return F("Dwarf");
  }
}

uint16_t selectEquip(uint8_t count, uint16_t choice[])
{
  boolean selected = false;
  uint8_t cursor = 0;
  while (!selected)
  {
    while (!(arduboy.nextFrame()))
      ;

    arduboy.pollButtons();
    if (arduboy.justPressed(UP_BUTTON) && cursor > 0)
    {
      cursor--;
    }
    if (arduboy.justPressed(DOWN_BUTTON) && cursor < count - 1)
    {
      cursor++;
    }
    if (arduboy.justPressed(B_BUTTON))
    {
      selected = true;
    }

    arduboy.clear();
    arduboy.setCursor(0, cursor * 8);
    arduboy.print(">");

    for (uint8_t i = 0; i < count; i++)
    {
      arduboy.setCursor(8, i * 8);
      if (choice[i] & ARMOR_LIGHT)
      {
        arduboy.print(F("LtArm "));
      }
      if (choice[i] & ARMOR_HEAVY)
      {
        arduboy.print(F("HvArm "));
      }
      if (choice[i] & WEAPON_BOW)
      {
        arduboy.print(F("Bow "));
      }
      if (choice[i] & ARMOR_SHIELD)
      {
        arduboy.print(F("Shield "));
      }
      if (choice[i] & WEAPON_ONE_HANDED)
      {
        arduboy.print(F("1H "));
      }
      if (choice[i] & WEAPON_TWO_HANDED)
      {
        arduboy.print(F("2H "));
      }
      if (choice[i] & WEAPON_SLASHING)
      {
        arduboy.print(F("Slash"));
      }
      if (choice[i] & WEAPON_CRUSHING)
      {
        arduboy.print(F("Crush"));
      }
    }
    arduboy.display();
  }
  return choice[cursor];
}

bool selectTeams()
{
  boolean selected = false;
  uint8_t cursor = 0;
  uint8_t count = 0;
  uint16_t choices[4];
  while (!selected)
  {
    while (!(arduboy.nextFrame()))
      ;
    arduboy.pollButtons();
    if (arduboy.justPressed(UP_BUTTON) && cursor > 0)
    {
      cursor--;
    }
    if (arduboy.justPressed(DOWN_BUTTON) && cursor < 7)
    {
      cursor++;
    }
    if (arduboy.justPressed(A_BUTTON) && count > 0)
    {
      count--;
    }
    if (arduboy.justPressed(B_BUTTON) && count == 4 && cursor == 7)
    {
      selected = true;
    }
    if (arduboy.justPressed(B_BUTTON) && count < 4)
    {
      team[count].clazz = cursor;
      team[count].lvl = 1;
      switch (cursor)
      {
      case WARRIOR:
        team[count].gold = XD6(2);
        team[count].pv = 7;
        choices[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choices[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choices[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choices[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count].equip = selectEquip(4, choices);
        break;
      case CLERIC:
        team[count].gold = D6();
        team[count].pv = 5;
        choices[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choices[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choices[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choices[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count].equip = selectEquip(4, choices);
        team[count].spellbook = SPELL_BLESSING;
        team[count].spellcount = 3;
        break;
      case ROGUE:
        team[count].gold = XD6(3);
        team[count].pv = 4;
        team[count].equip = ARMOR_LIGHT | WEAPON_ONE_HANDED_LIGHT | WEAPON_SLASHING;
        team[count].bag = BAG_ROPE | BAG_LOCK_PICKS;
        break;
      case WIZARD:
        team[count].gold = XD6(4);
        team[count].pv = 3;
        team[count].equip = WEAPON_ONE_HANDED_LIGHT | WEAPON_CRUSHING;
        team[count].bag = BAG_SPELL_BOOK;
        team[count].spellcount = 3;
        //TODO team[count].spellbook =
        break;
      case BARBARIAN:
        team[count].gold = D6();
        team[count].pv = 8;
        choices[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choices[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choices[2] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choices[3] = ARMOR_LIGHT | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count].equip = selectEquip(4, choices);
        break;
      case ELF:
        team[count].gold = XD6(2);
        team[count].pv = 5;
        team[count].equip = ARMOR_LIGHT;
        choices[0] = ARMOR_LIGHT | WEAPON_BOW | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choices[1] = ARMOR_LIGHT | WEAPON_BOW | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        team[count].equip = selectEquip(2, choices);
        break;
      case DWARF:
        team[count].gold = XD6(3);
        team[count].pv = 6;
        choices[0] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_SLASHING;
        choices[1] = ARMOR_LIGHT | ARMOR_SHIELD | WEAPON_ONE_HANDED | WEAPON_CRUSHING;
        choices[2] = ARMOR_HEAVY | WEAPON_TWO_HANDED | WEAPON_SLASHING;
        choices[3] = ARMOR_HEAVY | WEAPON_TWO_HANDED | WEAPON_CRUSHING;
        team[count].equip = selectEquip(4, choices);
        break;
      }
      count++;
    }

    arduboy.clear();
    arduboy.setCursor(0, cursor * 8);
    arduboy.print(">");
    for (uint8_t i = 0; i < 7; i++)
    {
      arduboy.setCursor(8, i * 8);
      arduboy.print(className(i));
    }
    if (count == 4)
    {
      arduboy.setCursor(8, 56);
      arduboy.print(F("Ok"));
    }
    for (uint8_t i = 0; i < count; i++)
    {
      arduboy.setCursor(64, i * 8);
      arduboy.print(className(team[i].clazz));
    }

    arduboy.display();
  }
}

void setup()
{
  arduboy.begin();
  arduboy.initRandomSeed();
  arduboy.setFrameRate(25);
  arduboy.setTextSize(1);

  selectTeams();
  //buyequip
}

int x = 20, y = 10; // initial text position

void loop()
{

  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  if (arduboy.pressed(UP_BUTTON))
  {
    y -= 1;
  }
  else if (arduboy.pressed(DOWN_BUTTON))
  {
    y += 1;
  }
  else if (arduboy.pressed(LEFT_BUTTON))
  {
    x -= 1;
  }
  else if (arduboy.pressed(RIGHT_BUTTON))
  {
    x += 1;
  }

  if (arduboy.pressed(A_BUTTON))
  {
    arduboy.invert(true);
  }
  else if (arduboy.pressed(B_BUTTON))
  {
    arduboy.invert(false);
  }

  arduboy.clear();
  arduboy.setCursor(x, y);
  arduboy.print("Music");
  arduboy.setCursor(x + 8, y + 24);
  arduboy.print("Demo");
  arduboy.display();
}