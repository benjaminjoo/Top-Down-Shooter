#include "Projectile.h"


Projectile::Projectile()
{
	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);
	acceleration	= vect2(0.0f, 0.0f);
}


Projectile::Projectile(const vect2& pos, const double& rot, const vect2& vel, const vect2& acc)
{
	position		= pos;
	rotation		= rot;
	velocity		= vel;
	acceleration	= acc;
}


Projectile::~Projectile()
{

}


void Projectile::updateVelocity()
{

}


void Projectile::updatePosition()
{

}


void Projectile::draw()
{

}


void Projectile::update()
{
	this->updateVelocity();
	this->updatePosition();
}
