#pragma once

#include "Vehicle.h"

class EnemyVehicle: public Vehicle
{
private:

	void updatePosition();
	void actOnCollision();

public:
	EnemyVehicle();
	EnemyVehicle(const double& h, const vect2& pos, const double& rot, const vect2& vel);
	~EnemyVehicle();

	void update();
	void draw(Canvas*);
};

