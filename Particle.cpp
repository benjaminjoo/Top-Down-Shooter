#include "Particle.h"


Particle::Particle()
{
}


Particle::Particle(const double& s, const unsigned& l, Uint32 col) :
	size(s), age(0), lifetime(l), colour(col)
{
}


Particle::~Particle()
{
}


bool Particle::isActive()
{
	return active;
}


void Particle::updatePosition()
{
	position += velocity;	
}


void Particle::updateVelocity()
{
	velocity += acceleration;	
}


void Particle::reset()
{
	age = 0;
	active = false;
	position = vect2(0.0f, 0.0f);
	position = vect2(0.0f, 0.0f);
	position = vect2(0.0f, 0.0f);
}


void Particle::activate(const vect2& p, const vect2& v, const vect2& a)
{
	active = true;
	position = p;
	velocity = v;
	acceleration = a;
}


void Particle::update()
{
	if (active)
	{
		updatePosition();
		age++;
		if (age >= lifetime)
			reset();
	}
}


void Particle::render(std::shared_ptr<Canvas> screen)
{
	int w = screen->getWidth();
	int h = screen->getHeight();
	double s = screen->getScale();

	int x = position.onScreen(s).x;
	int y = position.onScreen(s).y;
	double r = static_cast<int>(size * s);

	colour32 cl;

	cl.c[2] = (255 - age);
	cl.c[1] = (255 - age);
	cl.c[0] = (255 - age);

	screen->putPixel(x, y, cl.argb);
}
