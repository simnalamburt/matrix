#include "rain.hpp"



void rain::refresh()
{
  tick %= invVelocity;
  tick++;
  if (tick == invVelocity) y++;
}

bool rain::isDrawable() const
{
  return tick == invVelocity;
}
