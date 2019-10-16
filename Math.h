#pragma once

#include <cmath>


template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


struct screenCoord
{
	int x;
	int y;

	screenCoord()
	{
		x = 0;
		y = 0;
	}

	screenCoord(int x_, int y_)
	{
		x = x_;
		y = y_;
	}
};


struct boundingBoxScreen
{
	screenCoord topLeft;
	screenCoord bottomRight;

	boundingBoxScreen()
	{
		topLeft.x		= 0;
		topLeft.y		= 0;
		bottomRight.x	= 0;
		bottomRight.y	= 0;
	}

	boundingBoxScreen(const int& x1, const int& y1, const int& x2, const int& y2)
	{
		topLeft.x		= x1;
		topLeft.y		= y1;
		bottomRight.x	= x2;
		bottomRight.y	= y2;

		if (bottomRight.x < topLeft.x) { swap(topLeft.x, bottomRight.x); }
		if (bottomRight.y < topLeft.y) { swap(topLeft.y, bottomRight.y); }
	}

	boundingBoxScreen(const screenCoord& tl, const screenCoord& br)
	{
		topLeft		= tl;
		bottomRight = br;

		if (bottomRight.x < topLeft.x) { swap(topLeft.x, bottomRight.x); }
		if (bottomRight.y < topLeft.y) { swap(topLeft.y, bottomRight.y); }
	}

	inline void clipToScreen(const int& w, const int& h)
	{
		if (topLeft.x < 0) { topLeft.x = 0; }
		if (topLeft.y < 0) { topLeft.y = 0; }
		if (bottomRight.x >= w) { bottomRight.x = w - 1; }
		if (bottomRight.y >= h) { bottomRight.y = h - 1; }
		if ((topLeft.x < 0 && bottomRight.x < 0)	||
			(topLeft.y < 0 && bottomRight.y < 0)	||
			(topLeft.x >= w && bottomRight.x >= w)	||
			(topLeft.y >= h && bottomRight.y >= h)		)
		{
			topLeft.x		= 0;
			topLeft.y		= 0;
			bottomRight.x	= 0;
			bottomRight.y	= 0;
		}
	}
};


struct vect2
{
	double x;
	double y;

	vect2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vect2(double x_, double y_)
	{
		x = x_;
		y = y_;
	}

	inline vect2	operator + (const vect2& v)	{ return vect2(this->x + v.x, this->y + v.y); }
	inline vect2	operator - (const vect2& v) { return vect2(this->x - v.x, this->y - v.y); }
	inline double	operator * (const vect2& v) { return this->x* v.x + this->y * v.y; }
	inline vect2	operator * (const double& s) { return vect2(this->x * s, this->y * s); }
	inline vect2	operator / (const double& s) { return vect2(this->x / s, this->y / s); }
	
	inline double len() { return sqrt(this->x * this->x + this->y * this->y); }
	inline double lenSquared() { return this->x * this->x + this->y * this->y; }
	inline vect2 norm() { return *this / this->len(); }

	inline vect2 rot(const vect2& c, const double& a) { ; }

	inline screenCoord onScreen(const double& s) { return screenCoord( (int)(this->x * s), (int)(this->y * s)); }

};


struct edge
{
	vect2 startP;
	vect2 endP;

	vect2 normal;
};