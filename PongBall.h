#pragma once

#include <vector> 
#include <ctime>

#include "Math.h"
#include "Canvas.h"
#include "Utilities.h"

class PongBall
{
private:

	vect2	position;
	vect2	velocity;
	double	diameter;
	Uint32	colour;

public:

	PongBall();
	~PongBall();

	void setPosition(vect2 p);
	void setVelocity(vect2 v);

	void reset();

	vect2 getPosition();

	//void update(std::vector<edge> walls, std::vector<edge> player, Canvas* screen);
	void update(std::vector<edge> edges, Canvas* screen);
	void draw(Canvas* screen);
};

