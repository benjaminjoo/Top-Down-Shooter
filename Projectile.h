#pragma once

#include <vector> 
#include <memory>

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
	double  kineticEnergy;

public:


	Projectile(const int& id, const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& d);
	~Projectile();

	double getMass();
	double getMomentum();
	double getKineticEnergy();
	void update(std::vector<edge> walls, std::vector<Projectile> bullets, std::shared_ptr<Canvas> screen);
	void draw(std::shared_ptr<Canvas> screen);
};

