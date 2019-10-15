#pragma once

#include "Vehicle.h"

class EnemyVehicle: public Vehicle
{
public:
	EnemyVehicle();
	EnemyVehicle(const double& h, const vect2& pos, const double& rot, const vect2& vel);
	~EnemyVehicle();

	void updatePosition();
	void actOnCollision();
	void draw();
};

