#include <iostream>

#include "PlayerVehicle.h"


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


void PlayerVehicle::update(EventHandler* controls)
{
	rotation	= controls->turn * PI / 180.0f;
	position.x += controls->move * cos(rotation) + controls->strafe * cos(rotation + PI * 0.5f);
	position.y += controls->move * sin(rotation) + controls->strafe * sin(rotation + PI * 0.5f);
}


void PlayerVehicle::draw(Canvas* screen)
{
	double scale = screen->getScale();
	screen->drawCircle(position.onScreen(scale), 25, 255);
	vect2 C = position;
	vect2 P;
	double lg = 50.0;
	P.x = C.x + lg * cos(rotation);
	P.y = C.y + lg * sin(rotation);
	screen->drawLine(C.onScreen(scale), P.onScreen(scale), argbColour(0, 0, 255, 0));
}
