#include "PongBall.h"



PongBall::PongBall()
{
	srand(time(NULL));
	vect2 pos;
	pos.x = 50.0f;
	pos.y = 250.0f + (double)(rand() % 100);
	double ang = (double)((-30 + rand() % 60) / 180.0f * PI);
	double speed = 6.0f;
	vect2 vel(speed * cos(ang), speed * sin(ang));

	position	= pos;
	velocity	= vel;
	diameter	= 10.0f;
	colour		= argbColour(0, 0, 0, 255);
}


PongBall::~PongBall()
{

}


void PongBall::setPosition(vect2 p)
{
	position = p;
}


void PongBall::setVelocity(vect2 v)
{
	velocity = v;
}


void PongBall::reset()
{
	srand(time(NULL));
	vect2 pos;
	pos.x = 50.0f;
	pos.y = 250.0f + (double)(rand() % 100);
	double ang = (double)((-30 + rand() % 60) / 180.0f * PI);
	double speed = 10.0f;
	vect2 vel(speed * cos(ang), speed * sin(ang));

	position = pos;
	velocity = vel;
}


vect2 PongBall::getPosition()
{
	return position;
}


void PongBall::update(std::vector<edge> edges, Canvas* screen)
{
	vect2 oldPos = position;
	vect2 newPos = position + velocity;

	vect2 change;

	for (auto i = edges.begin(); i != edges.end(); ++i)
	{
		double oldDistWall = distPoint2Line(oldPos, *i);
		double newDistWall = distPoint2Line(newPos, *i);
	
		bool wallIsRelevant = pointIsAroundLine(position, *i);
	
		bool bulletFacingWall = velocity * i->normal < 0.0f ? true : false;
	
		if (abs(newDistWall) <= diameter * 0.5f && wallIsRelevant && bulletFacingWall)
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

void PongBall::draw(Canvas* screen)
{
	screen->drawCircle(position.onScreen(screen->getScale()), (int)(diameter * 0.5f), 255);
}
