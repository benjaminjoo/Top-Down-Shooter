#pragma once

#include "Math.h"			//vect2, colour32
#include "Particle.h"		//Particle
#include "Canvas.h"			//Canvas
#include "EventHandler.h"	//EventHandler

#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>


class ParticleSystem
{
private:
	vect2 origin		= vect2(0.0f, 0.0f);
	vect2 direction		= vect2(0.0f, 0.0f);
	double speed		= 0.0f;
	unsigned num		= 0;
	unsigned density	= 0;
	double dispersion	= 0;

	bool active			= false;
	bool gravity		= false;

	std::vector<Particle> particles;

	vect2 randomDir(double s);

public:
	ParticleSystem(const vect2& p, const vect2& dir, const double& sp, const unsigned& n, const unsigned& dens);
	~ParticleSystem();

	void loadParticles();
	void setDispersion(const double& disp);
	void setGravity(bool g);
	void activate();
	void deactivate();
	void update(std::shared_ptr<Canvas> screen, std::shared_ptr<EventHandler> controls);
};