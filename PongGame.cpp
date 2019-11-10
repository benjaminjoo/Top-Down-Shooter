#include "PongGame.h"


PongGame::PongGame(	std::shared_ptr<World>			L,
					std::shared_ptr<Canvas>			S,
					std::shared_ptr<EventHandler>	C,
					std::shared_ptr<PongBall>		B,
					std::shared_ptr<PongBar>		P)
{
	Level		= L;
	Screen		= S;
	Controls	= C;
	Ball		= B;
	Player		= P;
	
	oldTime		= 0;
	newTime		= 0;
	frameTime	= 0;
	frameCount	= 0;
}


PongGame::~PongGame()
{

}


void PongGame::updateWorld()
{
	Level->update();
}


void PongGame::updatePlayer()
{
	Player->update(vect2(Controls->strafe, -Controls->move));
}


void PongGame::updateBall()
{
	std::vector<edge> edgeListFull;

	for (auto i = Level->edgeList.begin(); i != Level->edgeList.end(); ++i)
		edgeListFull.push_back(*i);
	for (auto i = Player->edgeList.begin(); i != Player->edgeList.end(); ++i)
		edgeListFull.push_back(*i);

	Ball->update(edgeListFull, Screen);
}


void PongGame::drawWorld()
{
	Level->draw(Screen);
}


void PongGame::drawPlayer()
{
	Player->draw(Screen);
}


void PongGame::drawBall()
{
	Ball->draw(Screen);
}


void PongGame::updateAll()
{
	Controls->HandleUserEvents();
	if (!Controls->paused)
	{
		this->updateWorld();
		this->updatePlayer();
		this->updateBall();
	}
	Controls->ceaseMotion();
}


void PongGame::drawAll()
{
	Screen->clear();
	this->drawWorld();
	this->drawPlayer();
	this->drawBall();
	if (Controls->showStats) { Screen->displayValue((double)(30000.0 / frameTime), 1, 10, 10, 255); }
	Screen->update();
}


void PongGame::updateFrameCount()
{
	frameCount++;
}


void PongGame::calculateFrametime()
{
	if (frameCount == 30)
	{
		oldTime = newTime;
		newTime = clock();
		frameTime = newTime - oldTime;
		frameCount = 0;
	}
}
