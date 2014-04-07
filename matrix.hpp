#include <vector>
#include <ncurses.h>
#include "rain.hpp"



#ifndef MATRIX_HPP
#define MATRIX_HPP
struct range
{
  int start;
  int end;
  public:
  range(int start, int end)
  {
    this->start = start;
    this->end = end;
  }
};

class matrix
{
  public:
    matrix();
    ~matrix();
    int run();

  private:
    WINDOW * w;
    int width;
    int height;
    int idx;
    std::vector<rain> rainList;
    static const char * map;
    static const int mapLen;
    static const char blank_char;
    static const int minTrail;
    static const int maxTrail;
    static const double newRainProb;
    static const int refreshRate;
    void refresh();
    void draw();
    inline void setColor(int color);
    inline char get_random_char();
    inline int get_random_range(range r);
    inline double get_random();
};
#endif
