#pragma once

#include "Math.h"

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

public:

	Projectile();
	Projectile(const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& m);
	~Projectile();

	double getKineticEnergy();
	void draw();
	void update();
};

