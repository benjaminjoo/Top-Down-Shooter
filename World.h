#pragma once

#include <vector>
#include <string>
#include "Math.h"

class World
{
private:

	std::string mapName;

	std::vector<edge> edgeList;

public:

	World(const std::string& fileName);
	~World();

	void draw();
};

