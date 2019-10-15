#pragma once

#include <cmath>

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
	inline vect2 norm() { return *this / this->len(); }

	inline vect2 rot(const vect2& c, const double& a) { ; }

};