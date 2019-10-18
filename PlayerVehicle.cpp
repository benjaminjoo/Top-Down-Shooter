#include <iostream>

#include "PlayerVehicle.h"


PlayerVehicle::PlayerVehicle(const double& w, const double& l, const double& h, const vect2& pos, const double& rot, const vect2& vel)
{
	width		= w;
	length		= l;
	health		= h;

	position	= pos;
	rotation	= rot;
	velocity	= vel;

	textureID	= 1;

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


void PlayerVehicle::update(EventHandler* controls, std::vector<Projectile>& bullets)
{
	rotation	= controls->turn * PI / 180.0f;
	position.x += controls->move * cos(rotation) + controls->strafe * cos(rotation + PI * 0.5f);
	position.y += controls->move * sin(rotation) + controls->strafe * sin(rotation + PI * 0.5f);

	this->getRectangle();

	if (controls->firing)
	{
		this->shoot(bullets);
	}
}