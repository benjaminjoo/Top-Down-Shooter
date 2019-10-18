#include "Utilities.h"


Uint32 argbColour(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return ((a << 24) | (r << 16) | (g << 8) | (b << 0));
}


int sign(const double& a)
{
	int t;
	if (a > 0) { t = 1; }
	else if (a == 0) { t = 0; }
	else { t = -1; }

	return t;
}


double distPoint2Line(vect2 P, edge L)
{
	return abs((L.startP - P) * L.normal);
}


bool pointIsAroundLine(vect2 P, edge L)
{
	double sA = (L.endP - L.startP) * (L.startP - P);
	double sB = (L.endP - L.startP) * (L.endP - P);

	return (sign(sA) != sign(sB)) ? true : false;
}


int GetYMax3(screenCoord* p)
{
	int yMax = p[0].y;
	for (int i = 1; i < 3; i++)
	{
		if (p[i].y > yMax) { yMax = p[i].y; }
	}
	return yMax;
}


int GetYMin3(screenCoord* p)
{
	int yMin = p[0].y;
	for (int i = 1; i < 3; i++)
	{
		if (p[i].y < yMin) { yMin = p[i].y; }
	}
	return yMin;
}