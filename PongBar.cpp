#include "PongBar.h"



PongBar::PongBar()
{
	position	= vect2(0.0f, 0.0f);
	colour		= argbColour(0, 0, 255, 0);
}


PongBar::~PongBar()
{

}


void PongBar::addEdge(edge e)
{
	e.startP	+= position;
	e.endP		+= position;
	edgeList.push_back(e);
}


void PongBar::update(vect2 translation)
{
	for (auto i = edgeList.begin(); i != edgeList.end(); ++i)
	{
		i->move(translation);
	}
}


void PongBar::draw(std::shared_ptr<Canvas> screen)
{
	double s = screen->getScale();
	for (auto i : edgeList)
	{
		screen->drawLine(i.startP.onScreen(s), i.endP.onScreen(s), colour);
	}
}
