#include "Vehicle.h"



Vehicle::Vehicle()
{
	position		= vect2(0.0f, 0.0f);
	rotation		= 0.0f;
	velocity		= vect2(0.0f, 0.0f);
}

/*
Vehicle::Vehicle(const vect2& pos, const double& rot, const vect2& vel)
{
	position		= pos;
	rotation		= rot;
	velocity		= vel;
}
*/

Vehicle::~Vehicle()
{

}
