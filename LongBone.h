#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "Canvas.h"
#include "Math.h"
#include "Bone.h"

class Walker;

class LongBone: public Bone
{
	friend class PelvisBone;
	friend class Walker;

private:

	std::string name			= "Unnamed";
	laterality side				= LEFT;

	double length				= 1.0f;
	double jointDiameter		= 0.1f;

	vect2 upperJointPosition	= { 0.0f, 0.0f };
	vect2 lowerJointPosition	= { 0.0f, 0.0f };

	double currentRotation		= 0.0f;

	std::shared_ptr<LongBone> child = nullptr;

	vect2 calculateLowerJointPosition();

	void setUpperJointPosition(vect2);

	void countChildren(int*);

	void updateBone(vect2, std::shared_ptr<int>, std::shared_ptr<double[]>);

public:
	LongBone();
	LongBone(std::string, laterality, double);
	~LongBone();

	void attachChild(std::shared_ptr<LongBone>);

	void draw(std::shared_ptr<Canvas>);
};

