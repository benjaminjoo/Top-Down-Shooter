#pragma once

#include <vector>
#include <SDL/SDL.h>
#include <string>
#include "Math.h"
#include "Utilities.h"
#include "Canvas.h"

class World
{
private:

	std::string			mapName;
	std::vector<edge>	edgeList;
	Uint32				colour;


public:

	//World();
	World(const std::string& fileName);
	~World();

	void addEdge(const edge& e);
	void turnInsideOut();
	//void draw();
	void draw(Canvas* screen);

};

