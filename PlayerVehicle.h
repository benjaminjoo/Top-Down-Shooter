#pragma once

#include <memory>

#include "Vehicle.h"
#include "Canvas.h"
#include "EventHandler.h"

class PlayerVehicle: public Vehicle
{
private:

	void updatePosition();
	void actOnCollision();
	vect2 getVelocity(std::shared_ptr<EventHandler> controls);
	

public:

	PlayerVehicle(const double& w, const double& l, const double& h, const vect2& pos, const double& rot, const vect2& vel);
	~PlayerVehicle();
	
	void handleCollision(std::shared_ptr<EventHandler> controls, std::vector<edge> walls);
	void update(std::shared_ptr<EventHandler> controls, std::vector<Projectile>& bullets);
};

