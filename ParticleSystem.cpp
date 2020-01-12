#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(const vect2& p, const vect2& dir, const double& sp, const unsigned& n, const unsigned& dens) :
	origin(p), direction(dir), speed(sp), num(n), density(dens)
{
	loadParticles();
	srand(unsigned(time(NULL)));
}


ParticleSystem::~ParticleSystem()
{
}


vect2 ParticleSystem::randomDir(double s)
{
	double ang = (double)(rand() % 360 / 180.0f * PI);
	return vect2(s * cos(ang), s * sin(ang));
}


void ParticleSystem::loadParticles()
{
	for (unsigned i = 0; i < num; i++)
		particles.push_back(Particle(1.0f, 255, 0x000000ff));
}


void ParticleSystem::setDispersion(const double& disp)
{
	dispersion = disp;
}


void ParticleSystem::setGravity(bool g)
{
	gravity = g;
}


void ParticleSystem::activate()
{
	active = true;
}


void ParticleSystem::deactivate()
{
	active = false;
}


void ParticleSystem::update(std::shared_ptr<Canvas> screen, std::shared_ptr<EventHandler> controls)
{
	if (controls != nullptr)
		origin += vect2(controls->strafe, controls->move);

	if (active)
	{
		vect2 velocity = direction.norm()* speed;
		unsigned nEmitted = 0;
		for (auto i = particles.begin(); i != particles.end(); ++i)
		{
			if (!i->isActive() && nEmitted <= density)
			{
				velocity += randomDir(speed * dispersion);
				i->activate(origin, velocity, vect2(0.0f, GRAVITY));
				nEmitted++;
			}
			else
			{
				i->update();
				if (gravity)
					i->updateVelocity();
				i->render(screen);
			}
		}		
	}
}
