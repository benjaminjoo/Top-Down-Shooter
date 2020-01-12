#include <iostream>


#include "Maze.h"


Maze::Maze(std::shared_ptr<Canvas> S):
	Screen(S)
{
	coordStack.push({ currentX, currentY });
}


Maze::Maze(std::shared_ptr<Canvas> S, unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s) :
	Screen(S), width(w), height(h), unit(u), thck(t), delay(s)
{
	coordStack.push({ currentX, currentY });
}


Maze::Maze(std::shared_ptr<Canvas> S, unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s, unsigned int x, unsigned int y) :
	Screen(S), width(w), height(h), unit(u), thck(t), delay(s), currentX(x), currentY(y)
{
	coordStack.push({ currentX, currentY });
}


Maze::~Maze()
{
}


bool Maze::validatePosition(int x, int y)
{
	bool result = false;

	if (x >= 0 && x < width &&
		y >= 0 && y < height)
	{
		result = true;
	}

	return result;
}


bool Maze::checkNeighbour(int x, int y)
{
	bool result = false;

	if (validatePosition(x, y) && !tiles[y * width + x].isVisited())
	{
		result = true;
	}

	return result;
}


bool Maze::isStuck()
{
	bool result = true;

	//Northern neighbour

	if (checkNeighbour(currentX, currentY + 1))
	{
		result = false;	
		isNVacant = true;
		neighbourIndex.push_back(1);
		neighboursAvailable++;

	}

	//Southern neighbour

	if (checkNeighbour(currentX, currentY - 1))
	{
		result = false;		
		isSVacant = true;
		neighbourIndex.push_back(2);
		neighboursAvailable++;
	}

	//Western neighbour

	if (checkNeighbour(currentX - 1, currentY))
	{
		result = false;		
		isWVacant = true;
		neighbourIndex.push_back(3);
		neighboursAvailable++;
	}

	//Eastern neighbour

	if (checkNeighbour(currentX + 1, currentY))
	{
		result = false;		
		isEVacant = true;
		neighbourIndex.push_back(4);
		neighboursAvailable++;
	}

	return result;
}


void Maze::construct()
{
	if (nVisited < width * height)
	{
		if (!isStuck())
		{
			if(delay)
				std::this_thread::sleep_for(std::chrono::milliseconds(delay));

			unsigned int nIndex = neighbourIndex[rand() % neighboursAvailable];
			neighbourIndex.clear();
			nVisited++;

			//std::cout << "Tile " << currentX << " " << currentY << " visited..." << width * height - nVisited << " to go" << std::endl;

			switch (nIndex)
			{
				case 1:
				{
					tiles[currentY * width + currentX].connectS();
					drawTile(currentX, currentY);
					currentY++;
					tiles[currentY * width + currentX].connectN();
				}
				break;
				case 2:
				{
					tiles[currentY * width + currentX].connectN();
					drawTile(currentX, currentY);
					currentY--;
					tiles[currentY * width + currentX].connectS();
				}
				break;
				case 3:
				{
					tiles[currentY * width + currentX].connectW();
					drawTile(currentX, currentY);
					currentX--;
					tiles[currentY * width + currentX].connectE();
				}
				break;
				case 4:
				{
					tiles[currentY * width + currentX].connectE();
					drawTile(currentX, currentY);
					currentX++;
					tiles[currentY * width + currentX].connectW();
				}
				break;
			}		

			tiles[currentY * width + currentX].visit();		
			neighboursAvailable = 0;
			coordStack.push({ currentX, currentY });
			std::cout << "Elements on stack: (+) " << coordStack.size() << std::endl;
		
			drawTile(currentX, currentY);
		}
		else
		{
			coordStack.pop();
			std::cout << "Elements on stack: (-) " << coordStack.size() << std::endl;

			currentX = coordStack.top().x;
			currentY = coordStack.top().y;
		}		
	}
	else
	{
		isComplete = true;
	}
}


void Maze::markCurrent(const int& x, const int& y)
{
	int xCurr, yCurr;
	for (int j = 0; j < unit; j++)
	{
		for (int i = 0; i < unit; i++)
		{
			xCurr = x * unit + i;
			yCurr = y * unit + j;
			Screen->putPixel(xCurr, yCurr, marker);
		}
	}
}


void Maze::drawTile(const int& x, const int& y)
{
	int xCurr, yCurr;
	for (int j = thck; j < unit - thck; j++)
	{
		for (int i = thck; i < unit - thck; i++)
		{
			xCurr = x * unit + i;
			yCurr = y * unit + j;
			Screen->putPixel(xCurr, yCurr, colour);
		}
	}
	if (tiles[y * width + x].isConnectedN())
	{
		for (int j = 0; j < thck; j++)
		{
			for (int i = thck; i < unit - thck; i++)
			{
				xCurr = x * unit + i;
				yCurr = y * unit + j;
				Screen->putPixel(xCurr, yCurr, colour);
			}
		}
	}
	if (tiles[y * width + x].isConnectedS())
	{
		for (int j = unit - thck; j < unit; j++)
		{
			for (int i = thck; i < unit - thck; i++)
			{
				xCurr = x * unit + i;
				yCurr = y * unit + j;
				Screen->putPixel(xCurr, yCurr, colour);
			}
		}
	}
	if (tiles[y * width + x].isConnectedW())
	{
		for (int j = thck; j < unit - thck; j++)
		{
			for (int i = 0; i < thck; i++)
			{
				xCurr = x * unit + i;
				yCurr = y * unit + j;
				Screen->putPixel(xCurr, yCurr, colour);
			}
		}
	}
	if (tiles[y * width + x].isConnectedE())
	{
		for (int j = thck; j < unit - thck; j++)
		{
			for (int i = unit - thck; i < unit; i++)
			{
				xCurr = x * unit + i;
				yCurr = y * unit + j;
				Screen->putPixel(xCurr, yCurr, colour);
			}
		}
	}
}


void Maze::setColour(Uint32 c)
{
	colour = c;
}
