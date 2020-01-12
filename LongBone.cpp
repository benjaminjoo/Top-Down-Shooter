#include "LongBone.h"



LongBone::LongBone()
{
	std::cout << "LongBone constructor called" << std::endl;
}


LongBone::LongBone(std::string n, laterality s, double l):
	name(n), side(s), length(l)
{
	std::cout << "LongBone constructor called" << std::endl;

	vect2 lowerJointPosition	= { length * cos(currentRotation / 180.0f * PI), length * sin(currentRotation / 180.0f * PI) };
}


LongBone::~LongBone()
{
}


vect2 LongBone::calculateLowerJointPosition()
{
	vect2 newPos;

	newPos.x = upperJointPosition.x + length * cos(currentRotation / 180.0f * PI);
	newPos.y = upperJointPosition.y + length * sin(currentRotation / 180.0f * PI);

	return newPos;
}


void LongBone::setUpperJointPosition(vect2 p)
{
	upperJointPosition = p;
}


void LongBone::attachChild(std::shared_ptr<LongBone> ch)
{
	if (child == nullptr)
	{
		child = ch;
		child->setUpperJointPosition(this->lowerJointPosition);
	}
	else
		child->attachChild(ch);
}


void LongBone::draw(std::shared_ptr<Canvas> screen)
{
	screen->drawLine(upperJointPosition.onScreen(1.0f), lowerJointPosition.onScreen(1.0f), 0x00ffff00);
	screen->drawCircle(upperJointPosition.onScreen(1.0f), 5, 0x00ffff00);
	screen->drawCircle(lowerJointPosition.onScreen(1.0f), 5, 0x00ffff00);

	if (child != nullptr)
		child->draw(screen);
}


void LongBone::countChildren(int* n)
{
	if (child != nullptr)
	{
		(*n)++;
		child->countChildren(n);
	}
}


void LongBone::updateBone(vect2 pos, std::shared_ptr<int> n, std::shared_ptr<double[]> rotation)
{
	currentRotation = rotation[*n];
	(*n)++;

	upperJointPosition = pos;

	lowerJointPosition = this->calculateLowerJointPosition();

	if (child != nullptr)
	{
		child->updateBone(lowerJointPosition, n, rotation);
	}
}
