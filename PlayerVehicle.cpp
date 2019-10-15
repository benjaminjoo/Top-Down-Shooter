#include "PlayerVehicle.h"



PlayerVehicle::PlayerVehicle()
{
	position = vect2(0.0f, 0.0f);
	rotation = 0.0f;
	velocity = vect2(0.0f, 0.0f);
}


PlayerVehicle::PlayerVehicle(const vect2& pos, const double& rot, const vect2& vel)
{
	position = pos;
	rotation = rot;
	velocity = vel;
}


PlayerVehicle::~PlayerVehicle()
{

}


void PlayerVehicle::updatePosition()
{

}


void PlayerVehicle::actOnCollision()
{

}


void PlayerVehicle::draw()
{

}
