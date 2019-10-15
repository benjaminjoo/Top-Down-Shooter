#include "Vehicle.h"



Vehicle::Vehicle()
{
	health			= 100.0f;

	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);
}


Vehicle::~Vehicle()
{

}


void Vehicle::checkForCollision()
{

}
