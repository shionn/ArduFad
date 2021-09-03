
#include <player.h>

const PlayerData_t playerDatas[7] PROGMEM = {
    {"Warrior", 'W', 6, 2},
    {"Cleric", 'C', 4, 1},
    {"Rogue", 'R', 3, 3},
    {"Wizard", 'Z', 2, 4},
    {"Barbarian", 'B', 7, 1},
    {"Elf", 'E', 4, 2},
    {"Dwarf", 'D', 5, 3}};

Player::Player(uint8_t type)
{
    this->type = type;
    lvl = 1;
    hp = getMaxHp();
    gold = XD6(getPlayerData().baseGold);
    if (type == CLERIC)
    {
        spellbook = SPELL_BLESSING;
        spellcount = 3;
    }
    else if (type == ROGUE)
        bag = BAG_ROPE | BAG_LOCK_PICKS;
    else if (type == WIZARD)
    {
        bag = BAG_SPELL_BOOK;
        spellcount = 3;
    }
}

void Player::addEquip(uint16_t equip) { this->equip |= equip; }

uint8_t Player::getHp() { return hp; }
uint8_t Player::getMaxHp() { return getPlayerData().baseHp + lvl; }
String Player::getFullClassName() { return getPlayerData().fullName; }
char Player::getShortClassName() { return getPlayerData().shortName; }

PlayerData_t Player::getPlayerData()
{
    PlayerData_t out;
    memcpy_P(&out, &playerDatas[type], sizeof(PlayerData_t));
    return out;
}

String className(uint8_t clazz)
{
    PlayerData_t out;
    memcpy_P(&out, &playerDatas[clazz], sizeof(PlayerData_t));
    return out.fullName;
    /*switch (clazz)
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
    }*/
}
