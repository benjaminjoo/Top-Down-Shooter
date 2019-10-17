#include <iostream>

#include "World.h"

/*
World::World()
{
	mapName = "Untitled";
	//Screen	= nullptr;
	colour	= 0;
}
*/
/*
World::World(Canvas* S, const std::string& fileName)
{
	mapName = fileName;
	Screen	= S;
	colour	= argbColour(0, 255, 255, 255);
}
*/

World::World(const std::string& fileName)
{
	mapName = fileName;
	//Screen = S;
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

}

/*
void World::draw()
{
	double s = Screen->getScale();
	for (auto i : edgeList)
	{
		//edge tempEdge = i;
		//std::cout << "Start x: " << i.startP.x << " y: " << i.startP.y << "\tx: " << i.endP.x << " y: " << i.endP.y << std::endl;
		Screen->drawLine(i.startP.onScreen(s), i.endP.onScreen(s), colour);
	}
}
*/

void World::draw(Canvas* screen)
{
	double s = screen->getScale();
	for (auto i : edgeList)
	{
		screen->drawLine(i.startP.onScreen(s), i.endP.onScreen(s), colour);
	}
}
