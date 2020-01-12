#pragma once

#include "Math.h"	//vect2, colour32
#include "Canvas.h" //Canvas

#include <memory>

#define GRAVITY		0.01f

class Particle
{
private:
	vect2 position		= vect2(0.0f, 0.0f);
	vect2 velocity		= vect2(0.0f, 0.0f);
	vect2 acceleration	= vect2(0.0f, 0.0f);

	double size			= 0.0f;
	unsigned age		= 0;
	unsigned lifetime	= 0;
	Uint32 colour		= 0x00000000;

	bool active			= false;
	
	void updatePosition();
	void reset();

public:
	Particle();
	Particle(const double& s, const unsigned& l, Uint32 col);
	~Particle();

	bool isActive();

	void activate(const vect2& p, const vect2& v, const vect2& a);
	void update();
	void updateVelocity();
	void render(std::shared_ptr<Canvas> screen);
};