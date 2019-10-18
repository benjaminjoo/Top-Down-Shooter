#include <iostream>

#include "Vehicle.h"


Vehicle::Vehicle()
{
	width			= 20.0f;
	length			= 20.0f;
	health			= 100.0f;

	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);

	this->getRectangle();

	textureID		= 0;
}


Vehicle::~Vehicle()
{

}


int Vehicle::getTextureID()
{
	return textureID;
}


void Vehicle::getRectangle()
{
	topL = ((vect2(-width * 0.5f,  length * 0.5f)).rot(rotation + PI * 0.5f)) + position;
	topR = ((vect2( width * 0.5f,  length * 0.5f)).rot(rotation + PI * 0.5f)) + position;
	botL = ((vect2(-width * 0.5f, -length * 0.5f)).rot(rotation + PI * 0.5f)) + position;
	botR = ((vect2( width * 0.5f, -length * 0.5f)).rot(rotation + PI * 0.5f)) + position;
}


vect2 Vehicle::getDirection()
{
	return vect2(cos(rotation), sin(rotation));
}


void Vehicle::checkForCollision()
{

}


void Vehicle::shoot(std::vector<Projectile>& bullets)
{
	vect2 vel = this->getDirection() * BULLET_MUZZLE_VELOCITY;
	bullets.push_back(Projectile(position, 0.0f, vel, vect2(0.0f, 0.0f), BULLET_DIAMETER));
}


void Vehicle::draw(Canvas* screen, Texture* texture)
{
	double scale = screen->getScale();
	//screen->drawCircle(position.onScreen(scale), 25, 255);

	triangle2 poly_1, poly_2;
	
	poly_1.a = botL.onScreen(scale);
	poly_1.b = topL.onScreen(scale);
	poly_1.c = topR.onScreen(scale);
	
	poly_2.a = topR.onScreen(scale);
	poly_2.b = botR.onScreen(scale);
	poly_2.c = botL.onScreen(scale);

	//vect2 u = (topR - topL).norm();
	//vect2 v = (botL - topL).norm();
	//
	//screen->renderTriangle(botL, topL, topR, u, v, width, length, scale, texture);
	//screen->renderTriangle(topR, botR, botL, u, v, width, length, scale, texture);

	screen->renderTriangle(poly_1, botL, topL, topR, scale, texture);
	screen->renderTriangle(poly_2, botL, topL, topR, scale, texture);

}
