#pragma once

#include <memory>
#include <stack>
#include <vector>
#include <chrono>
#include <thread>


#include "Math.h"
#include "Canvas.h"
#include "Tile.h"


class Maze
{
private:

	int width	= 16;
	int height	= 16;
	int unit	= 16;
	int thck	= 2;
	int delay	= 100;

	Uint32 colour = 255;
	Uint32 marker = argbColour(0, 255, 0, 0);

	int nVisited = 0;

	int currentX = 0;
	int currentY = 0;

	std::unique_ptr<Tile[]> tiles{ new Tile[width * height] };
	std::stack<screenCoord> coordStack;

	std::shared_ptr<Canvas> Screen;

	unsigned int neighboursAvailable = 0;
	bool isNVacant = false;
	bool isSVacant = false;
	bool isWVacant = false;
	bool isEVacant = false;
	std::vector<unsigned int> neighbourIndex;

	bool validatePosition(int x, int y);
	bool checkNeighbour(int x, int y);
	bool isStuck();

	void markCurrent(const int& x, const int& y);
	void drawTile(const int& x, const int& y);

public:

	bool isComplete = false;

	Maze(std::shared_ptr<Canvas> S);
	Maze(std::shared_ptr<Canvas> S, unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s);
	Maze(std::shared_ptr<Canvas> S, unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s, unsigned int x, unsigned int y);
	~Maze();

	void setColour(Uint32);
	void construct();

};

