#pragma once

#include <vector>
#include <memory>

#include "Math.h"
#include "Canvas.h"
#include "Texture.h"
#include "Projectile.h"

class Vehicle
{
protected:
	double	width;
	double	length;
	double	health;
	double	bbRadius;

	vect2	position;
	double	rotation;
	vect2	velocity;

	vect2	topL;
	vect2	topR;
	vect2	botL;
	vect2	botR;

	int		textureID;

public:
	Vehicle();
	~Vehicle();

	virtual void updatePosition()	= 0;
	virtual void actOnCollision()	= 0;

	int getTextureID();
	void getRectangle(vect2 offset);
	vect2 getDirection();
	
	void shoot(std::vector<Projectile>& bullets);
	void draw(std::shared_ptr<Canvas> screen);
	void draw(std::shared_ptr<Canvas> screen, std::shared_ptr<Texture> texture);
};

