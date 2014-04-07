#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "matrix.hpp"

const char * matrix::map = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]asdfghjkl;'zxcvbnm,./\\QWERTYUIOP{}|ASDFGHJKL:\":ZXCVBNM<>?";
const int matrix::mapLen = strlen(matrix::map);
const char matrix::blank_char = ' ' ;
const int matrix::minTrail = 10;
const int matrix::maxTrail = 20;
const double matrix::newRainProb = 1 / 5.0;
const int matrix::refreshRate = 30;

matrix::matrix()
{
	w = initscr();
	noecho();
	raw();
	nodelay(w, true);
	srand((int)time(NULL));
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

int matrix::run()
{
	while(true)
	{
		char input = getch();
		if (input == 'q')
			break;
		refresh();
		draw();
		usleep(1000000 / matrix::refreshRate);
	}
	return 0;
}

void matrix::refresh()
{
	for(std::vector<rain>::iterator it = rainList.begin();
			it != rainList.end();
			it++)
	{
		it->refresh();
		if (it->y - it->trailLength >= height)
			rainList.erase(it);
	}
	if (get_random() < matrix::newRainProb)
	{
		rainList.push_back(
			rain(0, 
				rand() % width, 
				get_random_range(range(minTrail, maxTrail)),
				get_random_range(range(3, 6))));
	}
	idx++;
	idx %= 10;
}

void matrix::draw()
{
	for(std::vector<rain>::iterator it = rainList.begin();
			it != rainList.end();
			it++)
	{
		if (it->isDrawable())
		{
			int y = it->y;
			int x = it->x;
			int trailLength = it->trailLength;
			setColor(1);
			mvaddch(y, x, get_random_char());
			setColor(2);
			for (int i = 1; i < trailLength; i++)
				mvaddch(y - i, x, get_random_char());
			mvaddch(y - trailLength, x, blank_char);
		}
	}
	mvaddch(0, 0, idx + '0');
}

inline char matrix::get_random_char()
{
	return matrix::map[rand() % matrix::mapLen];
}

inline void matrix::setColor(int color)
{
	if(color >= 0 && color < COLORS);
		wattron(w, COLOR_PAIR(color));
	return;
}

inline int matrix::get_random_range(range r)
{
	return rand() % (r.end - r.start) + r.start;
}

inline double matrix::get_random()
{
	return static_cast<double>(rand()) / RAND_MAX;
}
