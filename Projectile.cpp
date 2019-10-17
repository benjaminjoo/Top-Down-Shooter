#include "Projectile.h"


Projectile::Projectile(Canvas* screen)
{
	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);
	acceleration	= vect2(0.0f, 0.0f);

	mass			= 1.0f;
	kineticEnergy	= this->getKineticEnergy();

	Screen			= screen;
}


Projectile::Projectile(Canvas* screen, const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& m)
{
	position		= pos;
	rotation		= rot;
	velocity		= vel;
	acceleration	= acc;

	mass			= m;
	kineticEnergy	= this->getKineticEnergy();

	Screen			= screen;
}


Projectile::~Projectile()
{

}


void Projectile::updateVelocity()
{
	velocity += acceleration;
}


void Projectile::updatePosition()
{
	position += velocity;
}


double Projectile::getKineticEnergy()
{
	return 0.5f * mass * velocity.lenSquared();
}


void Projectile::draw(Canvas* screen)
{
	if (kineticEnergy >= 0.0f)
	{

	}
	screen->drawCircle(position.onScreen(screen->getScale()), (int)mass, 255);
}


void Projectile::update()
{
	this->updateVelocity();
	this->updatePosition();
}
