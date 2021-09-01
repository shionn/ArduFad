#include <dices.h>

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