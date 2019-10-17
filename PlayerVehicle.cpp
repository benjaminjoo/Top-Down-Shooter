#include <iostream>

#include "PlayerVehicle.h"



/*
PlayerVehicle::PlayerVehicle()
{
	health		= 100.0f;

	position	= vect2(0.0f, 0.0f);
	rotation	= 0.0f;
	velocity	= vect2(0.0f, 0.0f);
}
*/

PlayerVehicle::PlayerVehicle(const double& h, const vect2& pos, const double& rot, const vect2& vel)
{
	health		= h;

	position	= pos;
	rotation	= rot;
	velocity	= vel;

	std::cout << "PlayerVehicle created sussecfully..." << std::endl;
}


PlayerVehicle::~PlayerVehicle()
{
	std::cout << "PlayerVehicle created sussecfully..." << std::endl;
}


void PlayerVehicle::updatePosition()
{
	position += velocity;
}


void PlayerVehicle::actOnCollision()
{

}


void PlayerVehicle::update()
{
	this->updatePosition();
	this->actOnCollision();
}


void PlayerVehicle::draw(Canvas* screen)
{
	screen->drawCircle(position.onScreen(screen->getScale()), 25, 255);
}
