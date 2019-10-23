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


double distPoint2Point(vect2 A, vect2 B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
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


int power(int number, unsigned int p)
{
	int result = 1;
	for (unsigned int i = 0; i < p; i++)
	{
		result *= number;
	}
	return result;
}


double pow10(int n)
{
	double result = 1.0;
	if (n > 0)
		for (int i = 0; i < n; i++)
			result *= 10;
	else if (n < 0)
		for (int i = 0; i > n; i--)
			result /= 10;
	return result;
}


std::shared_ptr<int[]> getFractionals(double number, int nDecimals)
{
	int dec;
	if (number > 0)
	{
		dec = int((number - (int)(number)) * pow10(nDecimals));
	}
	else dec = 0;
	std::shared_ptr<int[]> decimalDigits(new int[nDecimals]);
	for (int i = 0; i < nDecimals; i++)
	{
		if (i < nDecimals)
		{
			decimalDigits[i] = (int)(dec / pow10(nDecimals - 1 - i));
			int rem = dec % (int)(pow10(nDecimals - 1 - i));
			dec = rem;
		}
	}
	return decimalDigits;
}


std::shared_ptr<int[]> getIntegers(double number, int* n)
{
	int rawInt = (int)(number);
	int nDigits = 0;
	while (rawInt > 0)
	{
		rawInt /= 10;
		nDigits++;
	}
	std::shared_ptr<int[]> intDigits(new int[nDigits]);
	rawInt = (int)(number);
	for (int i = nDigits - 1; i >= 0; i--)
	{
		intDigits[i] = rawInt % 10;
		rawInt /= 10;
	}
	*n = nDigits;
	return intDigits;
}