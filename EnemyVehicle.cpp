#include "EnemyVehicle.h"



EnemyVehicle::EnemyVehicle()
{
	position = vect2(0.0f, 0.0f);
	rotation = 0.0f;
	velocity = vect2(0.0f, 0.0f);
}


EnemyVehicle::EnemyVehicle(const vect2& pos, const double& rot, const vect2& vel)
{
	position = pos;
	rotation = rot;
	velocity = vel;
}


EnemyVehicle::~EnemyVehicle()
{

}


void EnemyVehicle::updatePosition()
{

}


void EnemyVehicle::actOnCollision()
{

}


void EnemyVehicle::draw()
{

}
