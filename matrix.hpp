#pragma once
#include <string>
#include <random>
#include <vector>
#include <ncurses.h>
#include "rain.hpp"



class matrix
{
private:
  static const std::string map;
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
  std::default_random_engine engine;

public:
  matrix();
  ~matrix();
  void run();

private:
  void refresh();
  void draw();
  void setColor(int color);
};
