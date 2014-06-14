#pragma once

struct rain
{
  int x, y;
  int trailLength;
  int invVelocity;
  int tick;

  rain(int x, int y, int trailLength, int invVelocity) :
    x(x), y(y), trailLength(trailLength), invVelocity(invVelocity), tick(0) { }

  void refresh()
  {
    tick %= invVelocity;
    ++tick;
    if (tick == invVelocity) ++y;
  }

  bool isDrawable() const
  {
    return tick == invVelocity;
  }
};
