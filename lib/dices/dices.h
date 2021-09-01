#ifndef __DICES_H__
#define __DICES_H__

#include <Arduboy2.h>
#include <constants.h>

uint8_t D6(boolean ex = false);
uint8_t D66();
uint8_t XD6(uint8_t x);
uint8_t D6Lvl(Player p);
uint8_t D6HalfLvl(Player p);
String className(uint8_t clazz);

#endif