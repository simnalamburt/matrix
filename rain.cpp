#include "rain.hpp"



void rain::refresh()
{
  tick %= invVelocity;
  tick++;
  if (tick == invVelocity) y++;
}

bool rain::isDrawable()
{
  return tick == invVelocity;
}
