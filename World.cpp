#include <iostream>

#include "World.h"


World::World(const std::string& fileName)
{
	mapName = fileName;
	colour = argbColour(0, 255, 255, 255);

	std::cout << "World created sussecfully..." << std::endl;
}


World::~World()
{
	std::cout << "World destroyed sussecfully..." << std::endl;
}


void World::addEdge(const edge& e)
{
	edgeList.push_back(e);
}


void World::turnInsideOut()
{
	for (auto i = edgeList.begin(); i != edgeList.end(); ++i)
	{
		i->flip();
	}
}


void World::update()
{

}


void World::draw(Canvas* screen)
{
	double s = screen->getScale();
	for (auto i : edgeList)
	{
		screen->drawLine(i.startP.onScreen(s), i.endP.onScreen(s), colour);
	}
}
