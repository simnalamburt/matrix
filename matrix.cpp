#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "matrix.hpp"

using namespace std;
using random_real = uniform_real_distribution<>;
using random_int  = uniform_int_distribution<>;



const char* matrix::map =
  "`1234567890-=~!@#$%^&*()_+"
  "qwertyuiop[]asdfghjkl;'zxcvbnm,./"
  "\\QWERTYUIOP{}|ASDFGHJKL:\":ZXCVBNM<>?";
const int matrix::mapLen = strlen(matrix::map);



matrix::matrix()
{
  w = initscr();
  noecho();
  raw();
  nodelay(w, true);
  width = COLS;
  height = LINES;
  idx = 0;
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
}

matrix::~matrix()
{
  nodelay(w, false);
  cbreak();
  echo();
  endwin();
}

void matrix::run()
{
  while(true)
  {
    char input = getch();
    if (input == escape_char) break;
    refresh();
    draw();
    usleep(1000000.0 / matrix::refreshRate);
  }
}

void matrix::refresh()
{
  for (auto& rain : rainList) rain.refresh();
  remove_if(rainList.begin(), rainList.end(),
      [&](const auto& rain) { return rain.y - rain.trailLength >= height; });

  if (random_real{0, 1}(engine) < matrix::newRainProb)
  {
    rainList.emplace_back(rand() % width, 0,
        random_int{minTrail, maxTrail}(engine),
        random_int{3, 6}(engine) );
  }
  ++idx;
  idx %= 10;
}

void matrix::draw()
{
  for (const auto& rain : rainList)
  {
    if (rain.isDrawable())
    {
      int x = rain.x, y = rain.y;
      int trailLength = rain.trailLength;

      setColor(1);
      auto c = map[random_int{0, mapLen-1}(engine)];
      mvaddch(y, x, c);
      setColor(2);
      for (int i = 1; i < trailLength; ++i)
      {
        auto c = map[random_int{0, mapLen-1}(engine)];
        mvaddch(y - i, x, c);
      }
      mvaddch(y - trailLength, x, blank_char);
    }
  }
  mvaddch(0, 0, idx + '0');
}

void matrix::setColor(int color)
{
  if(color >= 0 && color < COLORS)
    wattron(w, COLOR_PAIR(color));
}
