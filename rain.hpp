#pragma once
struct rain
{
  int x, y;
  int trailLength;
  int invVelocity;
  int tick;

  rain(int y, int x, int trailLength, int invVelocity) :
    y(y), x(x), trailLength(trailLength), invVelocity(invVelocity), tick(0) { }

  void refresh();
  bool isDrawable();
};
