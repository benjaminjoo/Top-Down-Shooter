#include <iostream>
#include <memory>

#include "PlayerVehicle.h"


PlayerVehicle::PlayerVehicle(const double& w, const double& l, const double& h, const vect2& pos, const double& rot, const vect2& vel)
{
	width		= w;
	length		= l;
	health		= h;
	bbRadius	= w;

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


vect2 PlayerVehicle::getVelocity(EventHandler* controls)
{
	vect2 temp;
	rotation = controls->turn * PI / 180.0f;
	temp.x = controls->move * cos(rotation) + controls->strafe * cos(rotation + PI * 0.5f);
	temp.y = controls->move * sin(rotation) + controls->strafe * sin(rotation + PI * 0.5f);
	return temp;
}


void PlayerVehicle::handleCollision(EventHandler* controls, std::vector<edge> walls)
{
	vect2 speed = this->getVelocity(controls);

	vect2 oldPos = position;
	vect2 newPos = position + speed;

	double oldDistWall;
	double newDistWall;

	bool wallIsRelevant = false;

	bool playerFacingWall = false;

	int wallsInTheWay = 0;

	int p = 0;
	for (auto i = walls.begin(); i != walls.end(); ++i, ++p)
	{
		oldDistWall = distPoint2Line(oldPos, *i);
		newDistWall = distPoint2Line(newPos, *i);

		wallIsRelevant = pointIsAroundLine(position, *i);

		playerFacingWall = speed.norm() * i->normal <= 0.0f ? true : false;

		if ((abs(oldDistWall) <= bbRadius || abs(newDistWall) <= bbRadius) && wallIsRelevant && playerFacingWall)
		//playerFacingWall CAUSES THE FUCKING PROBLEM!!! It's wrong to assume it always evaluates true in corners with an angle of less then 90.0f
		{
			wallsInTheWay++;
		}
	}

	switch (wallsInTheWay)
	{
		case 0:
		{
			position += speed;
		}		
		break;
		case 1:
		{
			vect2 change;

			for (auto i = walls.begin(); i != walls.end(); ++i)
			{
				oldDistWall = distPoint2Line(oldPos, *i);
				newDistWall = distPoint2Line(newPos, *i);

				wallIsRelevant = pointIsAroundLine(position, *i);

				playerFacingWall = speed * i->normal < 0.0f ? true : false;

				if (abs(newDistWall) <= bbRadius && wallIsRelevant && playerFacingWall)
				{
					double x = abs(oldDistWall) - bbRadius;
					double speedProjectedToWallNormal = abs(speed * i->normal);
					double percentage = x / speedProjectedToWallNormal;

					change += speed * percentage;

					vect2 remainder = speed * (1.0f - percentage);

					vect2 sliding = remainder - (i->normal * (remainder * i->normal));

					change += sliding;
				}
			}
			position += change;		
		}	
		break;
		case 2:

		break;
		default:
		{
			position += speed;
		}
		break;
	}
}


void PlayerVehicle::update(EventHandler* controls, std::vector<Projectile>& bullets)
{
	this->getRectangle(vect2(0.0f, -20.0f));

	if (controls->firing)
	{
		this->shoot(bullets);
	}
}