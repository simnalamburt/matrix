#pragma once
#include <vector>
#include <ncurses.h>
#include "rain.hpp"



struct range
{
  int start, end;
  range(int start, int end) : start(start), end(end) { }
};

class matrix
{
private:
  static const char* map;
  static const int mapLen;
  static constexpr char blank_char = ' ';
  static constexpr char escape_char = 'q';
  static constexpr int minTrail = 10;
  static constexpr int maxTrail = 20;
  static constexpr double newRainProb = 0.2;
  static constexpr int refreshRate = 30;
  
  WINDOW* w;
  int width;
  int height;
  int idx;
  std::vector<rain> rainList;

public:
  matrix();
  ~matrix();
  void run();

private:
  void refresh();
  void draw();
  void setColor(int color);
  char get_random_char();
  int get_random_range(range r);
  double get_random();
};
