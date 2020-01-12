#include "Walker.h"



Walker::Walker()
{
	std::cout << "Walker constructor called" << std::endl;
}


Walker::Walker(vect2 pos, std::shared_ptr<PelvisBone> s) :
	position(pos), skeleton(s)
{
	std::cout << "Walker constructor called" << std::endl;
}


Walker::~Walker()
{
}


int Walker::getNJoint(const laterality& side)
{
	int n = 0;

	if (side == LEFT)
	{
		if (skeleton->leftLimb != nullptr)
		{
			n++;
			skeleton->leftLimb->countChildren(&n);
		}
	}

	if (side == RIGHT)
	{
		if (skeleton->rightLimb != nullptr)
		{
			n++;
			skeleton->rightLimb->countChildren(&n);
		}
	}

	return n;
}


void Walker::addRotationKey(const laterality& side, const double& timing, const std::vector<double>& rotation)
{
	if (side == LEFT)
	{
		int nJoint = getNJoint(LEFT);

		std::vector<double> rotKey;
		int nInput = rotation.size();
		if (nInput == nJoint)
		{
			rotKey.push_back(timing);
			for (int i = 0; i < nJoint; i++)
			{
				rotKey.push_back(rotation[i]);
			}
			leftLimbKeyRot.push_back(rotKey);
		}
	}
	if (side == RIGHT)
	{
		int nJoint = getNJoint(RIGHT);

		std::vector<double> rotKey;
		int nInput = rotation.size();
		if (nInput == nJoint)
		{
			rotKey.push_back(timing);
			for (int i = 0; i < nJoint; i++)
			{
				rotKey.push_back(rotation[i]);
			}
			rightLimbKeyRot.push_back(rotKey);
		}
	}
}


void Walker::getCurrentRotation(laterality side, int n, double phase, std::shared_ptr<double[]> rotation)
{
	if (side == LEFT && skeleton->leftLimb != nullptr && phase <= 1.0f)
	{
		for (unsigned i = 0; i < leftLimbKeyRot.size(); i++)	//Number of keyframes
		{
			if (i < leftLimbKeyRot.size() - 1)
			{
				if (phase >= leftLimbKeyRot[i][0] && phase < leftLimbKeyRot[i + 1][0])
				{
					double dPhase = phase - leftLimbKeyRot[i][0];
					double dTime = leftLimbKeyRot[i + 1][0] - leftLimbKeyRot[i][0];
					for (int j = 1; j < n + 1; j++)				//Number of Joints
					{
						double dRot = leftLimbKeyRot[i + 1][j] - leftLimbKeyRot[i][j];
						rotation[j - 1] = leftLimbKeyRot[i][j] + (dRot / dTime) * dPhase;
					}					
				}
			}
			else
			{
				if (phase >= leftLimbKeyRot[i][0] && phase < 1.0f)
				{
					double dPhase = phase - leftLimbKeyRot[i][0];
					double dTime = 1.0f - leftLimbKeyRot[i][0];
					for (int j = 1; j < n + 1; j++)
					{
						double dRot = leftLimbKeyRot[0][j] - leftLimbKeyRot[i][j];
						rotation[j - 1] = leftLimbKeyRot[i][j] + (dRot / dTime) * dPhase;
					}
				}
			}
		}
	}
	if (side == RIGHT && skeleton->rightLimb != nullptr && phase <= 1.0f)
	{
		for (unsigned i = 0; i < rightLimbKeyRot.size(); i++)
		{
			if (i < rightLimbKeyRot.size() - 1)
			{
				if (phase >= rightLimbKeyRot[i][0] && phase < rightLimbKeyRot[i + 1][0])
				{
					double dPhase = phase - rightLimbKeyRot[i][0];
					double dTime = rightLimbKeyRot[i + 1][0] - rightLimbKeyRot[i][0];
					for (int j = 1; j < n + 1; j++)
					{
						double dRot = rightLimbKeyRot[i + 1][j] - rightLimbKeyRot[i][j];
						rotation[j - 1] = rightLimbKeyRot[i][j] + (dRot / dTime) * dPhase;
					}
				}
			}
			else
			{
				if (phase >= rightLimbKeyRot[i][0] && phase < 1.0f)
				{
					double dPhase = phase - rightLimbKeyRot[i][0];
					double dTime = 1.0f - rightLimbKeyRot[i][0];
					for (int j = 1; j < n + 1; j++)
					{
						double dRot = rightLimbKeyRot[0][j] - rightLimbKeyRot[i][j];
						rotation[j - 1] = rightLimbKeyRot[i][j] + (dRot / dTime) * dPhase;
					}
				}
			}
		}
	}
}


void Walker::logRotKeys(laterality side)
{
	if (side == LEFT)
	{
		for (unsigned i = 0; i < leftLimbKeyRot.size(); i++)
		{
			for (unsigned j = 0; j < leftLimbKeyRot[i].size(); j++)
			{
				std::cout << leftLimbKeyRot[i][j] << ", " << std::flush;
			}
			std::cout << std::endl;
		}		
	}
	if (side == RIGHT)
	{
		for (unsigned i = 0; i < rightLimbKeyRot.size(); i++)
		{
			for (unsigned j = 0; j < rightLimbKeyRot[i].size(); j++)
			{
				std::cout << rightLimbKeyRot[i][j] << ", " << std::flush;
			}
			std::cout << std::endl;
		}		
	}
}


void Walker::logCurrentRotation(laterality side)
{
	int nJoint = getNJoint(side);
	std::shared_ptr<double[]> currentRot(new double[nJoint]);
	getCurrentRotation(side, nJoint, currentPhase, currentRot);
	for (int i = 0; i < nJoint; i++)
		std::cout << " #" << i << ": " << currentRot[i] << std::flush;
	std::cout << std::endl;
}


void Walker::plotRotation(laterality side, std::shared_ptr<Canvas> screen)
{
	screen->drawLine(vect2{ 0.0f, 100.0f }.onScreenFlipped(1.0f, screen->getHeight()), vect2{ graphScaleX, 100.0f }.onScreenFlipped(1.0f, screen->getHeight()), 0x00ffff00);
	if (side == LEFT)
		for (unsigned i = 0; i < leftLimbKeyRot.size(); i++) //Number of keyframes
		{
			if (i < leftLimbKeyRot.size() - 1)
			{
				for (int j = 1; j <= getNJoint(side); j++)	//Number of joints - keyframe rotation entries
				{
					vect2 currentPoint = vect2(leftLimbKeyRot[i][0] * graphScaleX, leftLimbKeyRot[i][j] * graphScaleY + 100.0f);
					vect2 nextPoint = vect2(leftLimbKeyRot[i + 1][0] * graphScaleX, leftLimbKeyRot[i + 1][j] * graphScaleY + 100.0f);
					screen->drawLine(currentPoint.onScreenFlipped(1.0f, screen->getHeight()), nextPoint.onScreenFlipped(1.0f, screen->getHeight()), 0x0000ff00);
				}				
			}
			else
			{
				for (int j = 1; j <= getNJoint(side); j++)
				{
					vect2 currentPoint = vect2(leftLimbKeyRot[i][0] * graphScaleX, leftLimbKeyRot[i][j] * graphScaleY + 100.0f);
					vect2 nextPoint = vect2(graphScaleX, leftLimbKeyRot[0][j] * graphScaleY + 100.0f);
					screen->drawLine(currentPoint.onScreenFlipped(1.0f, screen->getHeight()), nextPoint.onScreenFlipped(1.0f, screen->getHeight()), 0x0000ff00);
				}
			}			
		}
	if (side == RIGHT)
		for (unsigned i = 0; i < rightLimbKeyRot.size(); i++)
		{
			if (i < rightLimbKeyRot.size() - 1)
			{
				for (int j = 1; j <= getNJoint(side); j++)
				{
					vect2 currentPoint = vect2(rightLimbKeyRot[i][0] * graphScaleX, rightLimbKeyRot[i][j] * graphScaleY + 100.0f);
					vect2 nextPoint = vect2(rightLimbKeyRot[i + 1][0] * graphScaleX, rightLimbKeyRot[i + 1][j] * graphScaleY + 100.0f);
					screen->drawLine(currentPoint.onScreenFlipped(1.0f, screen->getHeight()), nextPoint.onScreenFlipped(1.0f, screen->getHeight()), 0x0000ff00);
				}
			}
			else
			{
				for (int j = 1; j <= getNJoint(side); j++)
				{
					vect2 currentPoint = vect2(rightLimbKeyRot[i][0] * graphScaleX, rightLimbKeyRot[i][j] * graphScaleY + 100.0f);
					vect2 nextPoint = vect2(graphScaleX, rightLimbKeyRot[0][j] * graphScaleY + 100.0f);
					screen->drawLine(currentPoint.onScreenFlipped(1.0f, screen->getHeight()), nextPoint.onScreenFlipped(1.0f, screen->getHeight()), 0x0000ff00);
				}
			}
		}	
}


void Walker::plotCurrentRotation(laterality side, std::shared_ptr<Canvas> screen)
{
	int nJoint = getNJoint(side);
	std::shared_ptr<double[]> currentRot(new double[nJoint]);
	getCurrentRotation(side, nJoint, currentPhase, currentRot);

	for (int i = 0; i < nJoint; i++)
	{
		vect2 c = { currentPhase * graphScaleX, currentRot[i] * graphScaleY + 100.0f };
		screen->drawCircle(c.onScreenFlipped(1.0f, screen->getHeight()), 3, 0x00ffffff);
	}
}


void Walker::updateSkeleton()
{
	incrementWalkPhase();

	int nLeft = getNJoint(LEFT);
	int nRight = getNJoint(RIGHT);
	std::shared_ptr<double[]> currentRotLeft(new double[nLeft]);
	std::shared_ptr<double[]> currentRotRight(new double[nRight]);
	getCurrentRotation(LEFT, nLeft, currentPhase, currentRotLeft);
	getCurrentRotation(RIGHT, nRight, currentPhase, currentRotRight);

	skeleton->setLowerJointPosition(position);
	skeleton->updateLeftLimb(currentRotLeft);
	skeleton->updateRightLimb(currentRotRight);
}


void Walker::incrementWalkPhase()
{
	currentPhase += walkingSpeed;
	if (currentPhase >= 1.0f)
		currentPhase = 0.0f;
}


void Walker::drawSkeleton(std::shared_ptr<Canvas> screen)
{
	if (skeleton != nullptr)
		skeleton->draw(screen);
}
