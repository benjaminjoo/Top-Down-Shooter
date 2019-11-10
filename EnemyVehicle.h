#pragma once

#include <memory>

#include "Vehicle.h"

class EnemyVehicle: public Vehicle
{
private:

	void updatePosition();
	void actOnCollision();
	vect2 getVelocity();

public:
	EnemyVehicle();
	EnemyVehicle(const double& h, const vect2& pos, const double& rot, const vect2& vel);
	~EnemyVehicle();

	void update();
	void draw(std::shared_ptr<Canvas>);
};

