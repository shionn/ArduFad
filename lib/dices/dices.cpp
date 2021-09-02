#include <dices.h>

uint8_t D6(boolean ex)
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
