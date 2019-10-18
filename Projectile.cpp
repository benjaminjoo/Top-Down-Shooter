#include <iostream>

#include "Projectile.h"


Projectile::Projectile(const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& d)
{
	position		= pos;
	rotation		= rot;
	velocity		= vel;
	acceleration	= acc;

	size			= d;
	kineticEnergy	= this->getKineticEnergy();
}


Projectile::~Projectile()
{

}


void Projectile::updateVelocity()
{
	velocity *= BULLET_DRAG;
}


void Projectile::updatePosition()
{
	position += velocity;
}


void Projectile::checkForCollision(std::vector<edge> walls, Canvas* screen)
{
	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		double distanceToWall = abs(distPoint2Line(position, *i));
		bool wallIsRelevant = pointIsAroundLine(position, *i);
		double velocityProjectedToWallNormal = abs(velocity * i->normal);
		if (wallIsRelevant && (distanceToWall <= velocityProjectedToWallNormal))
		{
			velocity -= (i->normal * (2 * (velocity * i->normal)));
		}
	}
}


void Projectile::actOnCollision()
{

}


double Projectile::getKineticEnergy()
{
	return 0.5f * size * velocity.lenSquared();
}


void Projectile::draw(Canvas* screen)
{
	if (getKineticEnergy() >= BULLET_KINETIC_ENERGY_CUTOFF)
	{
		screen->drawCircle(position.onScreen(screen->getScale()), (int)(BULLET_DIAMETER * 0.5f), 255);
	}	
}


void Projectile::update()
{
	this->updateVelocity();
	this->updatePosition();
}
