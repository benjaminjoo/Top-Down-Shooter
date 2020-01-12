#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "Math.h"
#include "Canvas.h"
#include "Bone.h"
#include "PelvisBone.h"
#include "LongBone.h"

class Walker
{
private:

	vect2 position		= { 0.0f, 0.0f };

	std::shared_ptr<PelvisBone> skeleton = nullptr;

	double	currentPhase = 0.0f;
	double	walkingSpeed = 0.005f;

	double graphScaleX	= 500.0f;
	double graphScaleY	= 1.0f;

	std::vector<std::vector<double>> leftLimbKeyRot;
	std::vector<std::vector<double>> rightLimbKeyRot;

public:
	Walker();
	Walker(vect2, std::shared_ptr<PelvisBone>);
	~Walker();

	int getNJoint(const laterality&);

	void addRotationKey(const laterality&, const double&, const std::vector<double>&);
	void getCurrentRotation(laterality, int, double, std::shared_ptr<double[]>);
	void logRotKeys(laterality);
	void logCurrentRotation(laterality);
	void plotRotation(laterality, std::shared_ptr<Canvas>);
	void plotCurrentRotation(laterality, std::shared_ptr<Canvas>);

	void updateSkeleton();
	void incrementWalkPhase();

	void drawSkeleton(std::shared_ptr<Canvas>);
};

