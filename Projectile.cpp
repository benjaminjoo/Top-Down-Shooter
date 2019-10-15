#include "Projectile.h"


Projectile::Projectile()
{
	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);
	acceleration	= vect2(0.0f, 0.0f);

	mass			= 1.0f;
	kineticEnergy	= this->getKineticEnergy();
}


Projectile::Projectile(const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& m)
{
	position		= pos;
	rotation		= rot;
	velocity		= vel;
	acceleration	= acc;

	mass			= m;
	kineticEnergy	= this->getKineticEnergy();
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


double Projectile::getKineticEnergy()
{
	return 0.5f * mass * velocity.lenSquared();
}


void Projectile::draw()
{
	if (kineticEnergy >= 0.0f)
	{

	}
}


void Projectile::update()
{
	this->updateVelocity();
	this->updatePosition();
}
