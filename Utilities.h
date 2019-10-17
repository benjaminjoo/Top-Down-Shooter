#pragma once

#include <SDL/SDL.h>
#include "Math.h"

Uint32 argbColour(unsigned char a, unsigned char r, unsigned char g, unsigned char b);


int sign(const double& a);


double distPoint2Line(vect2 P, edge L);


bool pointIsAroundLine(vect2 P, edge L);