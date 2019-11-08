#pragma once

#include <vector> 

#include "Math.h"
#include "Canvas.h"
#include "World.h"


class Projectile
{
private:

	int		ID;

	vect2	position;
	double	rotation;
	vect2	velocity;
	double	unitMove;
	vect2	acceleration;

	double	diameter;
	double  density;
	//double	mass;
	//double	momentum;
	double  kineticEnergy;

public:


	Projectile(const int& id, const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& d);
	~Projectile();

	double getMass();
	double getMomentum();
	double getKineticEnergy();
	void update(std::vector<edge> walls, std::vector<Projectile> bullets, Canvas* screen);
	void draw(Canvas* screen);
};

