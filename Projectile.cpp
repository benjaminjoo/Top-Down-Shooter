#include <iostream>

#include "Projectile.h"


Projectile::Projectile(const int& id, const vect2& pos, const double& rot, const vect2& vel, const vect2& acc, const double& d)
{
	ID				= id;

	position		= pos;
	rotation		= rot;
	velocity		= vel;
	acceleration	= acc;

	diameter		= d;
	density			= 1.0f;
	//mass;
	//momentum;

	unitMove		= 2.0f;
	kineticEnergy	= this->getKineticEnergy();
	
}


Projectile::~Projectile()
{

}


double Projectile::getMass()
{
	double radius = diameter * 0.5f;

	return 4.0f / 3.0f * radius * radius * radius * PI * density;
}


double Projectile::getMomentum()
{
	return this->getMass() * velocity.len();
}


double Projectile::getKineticEnergy()
{
	return 0.5f * this->getMass() * velocity.lenSquared();
}


void Projectile::draw(Canvas* screen)
{
	screen->drawCircle(position.onScreen(screen->getScale()), (int)(diameter * 0.5f), 255);
}

/*
void Projectile::update(std::vector<edge> walls, std::vector<Projectile> bullets, Canvas* screen)
{
	//vect2 v = this->velocity;

	int nCycles = (int)(velocity.len() / unitMove) + 1;
	vect2 v = velocity * (1.0f / nCycles);

	vect2* speed = &v;

	vect2 oldPos = position;
	vect2 newPos = position + *speed;

	vect2 change;

	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		double oldDistWall = distPoint2Line(oldPos, *i);
		double newDistWall = distPoint2Line(newPos, *i);

		bool wallIsRelevant = pointIsAroundLine(position, *i);

		bool bulletFacingWall = *speed * i->normal < 0.0f ? true : false;

		if (abs(newDistWall) <= diameter && wallIsRelevant && bulletFacingWall)
		{
			double x = abs(oldDistWall) - diameter;
			double speedProjectedToWallNormal = abs(*speed * i->normal);
			double percentage = x / speedProjectedToWallNormal;

			change += *speed * percentage;

			position += change;

			vect2 remainder = *speed * (1.0f - percentage);

			vect2 bounceBack = remainder - (i->normal * 2.0f * (remainder * i->normal));

			position += bounceBack;

			*speed = *speed - (i->normal * 2.0f * (*speed * i->normal));
		}
	}

	position += *speed;
}
*/

void Projectile::update(std::vector<edge> walls, std::vector<Projectile> bullets, Canvas* screen)
{
	vect2 oldPos = position;
	vect2 newPos = position + velocity;

	vect2 change;

	for (auto i = walls.begin(); i != walls.end(); ++i)
	{
		double oldDistWall = distPoint2Line(oldPos, *i);
		double newDistWall = distPoint2Line(newPos, *i);

		bool wallIsRelevant = pointIsAroundLine(position, *i);

		bool bulletFacingWall = velocity * i->normal < 0.0f ? true : false;

		if (abs(newDistWall) <= diameter && wallIsRelevant && bulletFacingWall)
		{
			double x = abs(oldDistWall) - diameter;
			double velocityProjectedToWallNormal = abs(velocity * i->normal);
			double percentage = x / velocityProjectedToWallNormal;

			change += velocity * percentage;

			position += change;

			vect2 remainder = velocity * (1.0f - percentage);

			vect2 bounceBack = remainder - (i->normal * 2.0f * (remainder * i->normal));

			position += bounceBack;

			velocity = velocity - (i->normal * 2.0f * (velocity * i->normal));
		}
	}

	position += velocity;
}
