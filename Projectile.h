#pragma once

#include "Math.h"
#include "Canvas.h"

class Projectile
{
private:

	vect2	position;
	double	rotation;
	vect2	velocity;
	vect2	acceleration;

	double	mass;
	double  kineticEnergy;

	void updateVelocity();	
	void updatePosition();

	Canvas*	Screen;

public:

	Projectile(Canvas* screen);
	Projectile(Canvas* screen,const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& m);
	~Projectile();

	double getKineticEnergy();
	void draw(Canvas* screen);
	void update();
};

