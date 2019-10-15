#pragma once

#include "Math.h"

class Vehicle
{
private:

	vect2	position;
	double	rotation;
	vect2	velocity;

public:
	Vehicle();
	//Vehicle(const vect2& pos, const double& rot, const vect2& vel);
	~Vehicle();


};

