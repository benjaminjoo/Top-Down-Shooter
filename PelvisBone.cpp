#include "PelvisBone.h"



PelvisBone::PelvisBone()
{
	std::cout << "PelvisBone constructor called" << std::endl;
}


PelvisBone::PelvisBone(std::string n):
	name(n)
{
	std::cout << "PelvisBone constructor called" << std::endl;
}


PelvisBone::~PelvisBone()
{
}


void PelvisBone::setLowerJointPosition(vect2 p)
{
	leftJointPosition	= p;
	rightJointPosition	= p;
}


void PelvisBone::attachBoneLeft(std::shared_ptr<LongBone> b)
{
	if (leftLimb == nullptr)
	{
		leftLimb = b;
		leftLimb->setUpperJointPosition(this->leftJointPosition);
	}
	else
	{
		leftLimb->attachChild(b);
	}
}


void PelvisBone::attachBoneRight(std::shared_ptr<LongBone> b)
{
	if (rightLimb == nullptr)
	{
		rightLimb = b;
		rightLimb->setUpperJointPosition(this->rightJointPosition);
	}
	else
	{
		rightLimb->attachChild(b);
	}
}


void PelvisBone::updateLeftLimb(std::shared_ptr<double[]> rotation)
{
	if (leftLimb != nullptr)
	{
		auto n = std::make_shared<int>(0);
		leftLimb->updateBone(leftJointPosition, n, rotation);
	}
}


void PelvisBone::updateRightLimb(std::shared_ptr<double[]> rotation)
{
	if (rightLimb != nullptr)
	{
		auto n = std::make_shared<int>(0);
		rightLimb->updateBone(rightJointPosition, n, rotation);
	}
}


void PelvisBone::draw(std::shared_ptr<Canvas> screen)
{
	screen->drawCircle(leftJointPosition.onScreen(1.0f), 5, 0x00ffff00);
	screen->drawCircle(rightJointPosition.onScreen(1.0f), 10, 0x00ffff00);

	if (leftLimb != nullptr)
		leftLimb->draw(screen);

	if (rightLimb != nullptr)
		rightLimb->draw(screen);
}
