#pragma once

#include "Math.h"
#include "Canvas.h"

class Vehicle
{
protected:

	double	health;

	vect2	position;
	double	rotation;
	vect2	velocity;

public:
	Vehicle();
	~Vehicle();

	virtual void updatePosition()	= 0;
	virtual void actOnCollision()	= 0;
	virtual void update()			= 0;
	virtual void draw(Canvas*)		= 0;

	void checkForCollision();
	void shoot();
};

