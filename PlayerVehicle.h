#pragma once

#include "Vehicle.h"

class PlayerVehicle: public Vehicle
{
public:
	PlayerVehicle();
	PlayerVehicle(const vect2& pos, const double& rot, const vect2& vel);
	~PlayerVehicle();

	void updatePosition();
	void actOnCollision();
	void draw();
};

