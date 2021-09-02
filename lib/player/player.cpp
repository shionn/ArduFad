
#include <player.h>

void Player::initialize(uint8_t clazz)
{
    this->clazz = clazz;
    this->lvl = 1;
    this->hp = getMaxHp();
    switch (clazz)
    {
    case WARRIOR:
        gold = XD6(2);
        break;
    case CLERIC:
        gold = D6();
        spellbook = SPELL_BLESSING;
        spellcount = 3;
        break;
    case ROGUE:
        gold = XD6(3);
        bag = BAG_ROPE | BAG_LOCK_PICKS;
        break;
    case WIZARD:
        gold = XD6(4);
        bag = BAG_SPELL_BOOK;
        spellcount = 3;
        break;
    case BARBARIAN:
        gold = D6();
        break;
    case ELF:
        gold = XD6(2);
        break;
    case DWARF:
        gold = XD6(3);
        break;
    }
}

uint8_t Player::getHp()
{
    return hp;
}

uint8_t Player::getMaxHp()
{
    switch (clazz)
    {
    case WIZARD:
        return 2 + lvl;
    case ROGUE:
        return 3 + lvl;
    case CLERIC:
    case ELF:
        return 4 + lvl;
    case DWARF:
        return 5 + lvl;
    case WARRIOR:
        return 6 + lvl;
    case BARBARIAN:
    default:
        return 7 + lvl;
    }
}

void Player::addEquip(uint16_t equip)
{
    this->equip |= equip;
}

String Player::fullClassName()
{
    return className(clazz);
}

String Player::shortClassName()
{
    switch (clazz)
    {
    case WARRIOR:
        return F("W");
    case CLERIC:
        return F("C");
    case ROGUE:
        return F("R");
    case WIZARD:
        return F("Z");
    case BARBARIAN:
        return F("B");
    case ELF:
        return F("E");
    case DWARF:
    default:
        return F("D");
    }
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
    default:
        return F("Dwarf");
    }
}