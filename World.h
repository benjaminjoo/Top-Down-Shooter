#pragma once

#include <vector>
#include <SDL/SDL.h>
#include <string>
#include "Math.h"
#include "Utilities.h"
#include "Canvas.h"
#include "EventHandler.h"
#include "Projectile.h"


class World	
{

private:

	std::string			mapName;
	Uint32				colour;

public:

	std::vector<edge>	edgeList;

	World(const std::string& fileName);
	~World();

	void addEdge(const edge& e);
	void turnInsideOut();

	void update();
	void draw(Canvas* screen);

};

