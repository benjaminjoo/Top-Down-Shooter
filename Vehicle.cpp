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

	triangle2 poly_1, poly_2;
	
	poly_1.a = botL.onScreen(scale);
	poly_1.b = topL.onScreen(scale);
	poly_1.c = topR.onScreen(scale);
	
	poly_2.a = topR.onScreen(scale);
	poly_2.b = botR.onScreen(scale);
	poly_2.c = botL.onScreen(scale);

	screen->renderTriangle(poly_1, botL, topL, topR, scale, texture);
	screen->renderTriangle(poly_2, botL, topL, topR, scale, texture);



	/***********************************************************
	**********										  **********
	***********************************************************/


	int nP = 5;
	double radius = 250.0f;
	double inner_radius = 225.0f;
	vect2 centre(1200.0f, 600.0f);
	vect2* polyPoints = new vect2[nP];
	screenCoord* points = new screenCoord[nP];
	for (int i = 0; i < nP; i++)
	{
		vect2 temp(centre.x + radius * cos(2 * PI / nP * i), centre.y + radius * sin(2 * PI / nP * i));
		points[i] = temp.onScreen(scale);
		polyPoints[i] = temp;
	}
	

	edge keel(position, position + this->getDirection());

	screen->solidFillConvexPoly(nP, points, argbColour(0, 0, 255, 0));

	if (screen->checkPolygonForSplitting(nP, polyPoints, keel))
	{
		for (int i = 0; i < nP; i++)
		{
			edge temp;
			if (i < nP - 1)
			{
				temp.startP = polyPoints[i];
				temp.endP	= polyPoints[i + 1];
			}
			else
			{
				temp.startP = polyPoints[i];
				temp.endP	= polyPoints[0];
			}
			vect2 hit;
			if (screen->iSect2dLine(temp.startP, temp.endP, keel, &hit))
			{
				screen->drawCircle(hit.onScreen(scale), 5, argbColour(0, 255, 0, 0));
			}
		}
	}


	delete[] points, polyPoints;
}
