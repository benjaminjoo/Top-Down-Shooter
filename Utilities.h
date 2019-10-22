#pragma once

#include <SDL/SDL.h>
#include <memory>
#include "Math.h"

Uint32 argbColour(unsigned char a, unsigned char r, unsigned char g, unsigned char b);


int sign(const double& a);


double distPoint2Line(vect2 P, edge L);


double distPoint2Point(vect2 A, vect2 B);


bool pointIsAroundLine(vect2 P, edge L);


int GetYMax3(screenCoord* p);


int GetYMin3(screenCoord* p);


double pow10(int n);


std::shared_ptr<int[]> getFractionals(double number, int nDecimals);


std::shared_ptr<int[]> getIntegers(double number, int* n);
