#ifndef RAIN_H
#define RAIN_H
struct rain
{
	int y;
	int x;
	int trailLength;
	int invVelocity;
	int tick;

public:
	rain(int y, int x, int trailLength, int invVelocity)
	{
		this->y = y;
		this->x = x;
		this->trailLength = trailLength;
		this->invVelocity = invVelocity;
		this->tick = 0;
	}

	void refresh();
	bool isDrawable();
};
#endif
