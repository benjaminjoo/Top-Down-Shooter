#pragma once

#include "Vehicle.h"
#include "Canvas.h"

class PlayerVehicle: public Vehicle
{
private:

	void updatePosition();
	void actOnCollision();

public:
	//PlayerVehicle();
	PlayerVehicle(const double& h, const vect2& pos, const double& rot, const vect2& vel);
	~PlayerVehicle();



	void update();
	void draw(Canvas* screen);
};

