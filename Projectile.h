#pragma once

#include <vector> 

#include "Math.h"
#include "Canvas.h"
#include "World.h"


class Projectile
{
private:

	vect2	position;
	double	rotation;
	vect2	velocity;
	vect2	acceleration;

	double	size;
	double  kineticEnergy;

	void actOnCollision();

public:

	Projectile(const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& d);
	~Projectile();

	double getKineticEnergy();
	void update();
	void updateVelocity();
	void updatePosition();
	void checkForCollision(std::vector<edge> walls, Canvas* screen);
	void draw(Canvas* screen);
};

