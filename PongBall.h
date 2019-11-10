#pragma once

#include <vector> 
#include <memory>
#include <ctime>

#include "Math.h"
#include "Canvas.h"
#include "Utilities.h"

class PongBall
{
private:

	double	speed;
	vect2	position;
	vect2	velocity;
	double	diameter;
	Uint32	colour;

public:

	PongBall();
	PongBall(double v);
	~PongBall();

	void setPosition(vect2 p);
	void setVelocity(vect2 v);

	void reset();

	vect2 getPosition();

	void update(std::vector<edge> edges, std::shared_ptr<Canvas> screen);
	void draw(std::shared_ptr<Canvas> screen);
};

