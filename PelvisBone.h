#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "Canvas.h"
#include "Math.h"
#include "Bone.h"
#include "LongBone.h"

class Walker;

class PelvisBone: public Bone
{
	friend class Walker;

private:

	std::string name			= "Unnamed";

	double jointDiameter		= 0.1f;

	vect2 leftJointPosition		= { 0.0f, 0.0f };
	vect2 rightJointPosition	= { 0.0f, 0.0f };

	std::shared_ptr<LongBone> leftLimb	= nullptr;
	std::shared_ptr<LongBone> rightLimb = nullptr;

	void setLowerJointPosition(vect2);

public:
	PelvisBone();
	PelvisBone(std::string);
	~PelvisBone();

	void attachBoneLeft(std::shared_ptr<LongBone>);
	void attachBoneRight(std::shared_ptr<LongBone>);

	void updateLeftLimb(std::shared_ptr<double[]>);
	void updateRightLimb(std::shared_ptr<double[]>);

	void draw(std::shared_ptr<Canvas>);
};

