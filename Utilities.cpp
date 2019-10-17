#include "Utilities.h"

Uint32 argbColour(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return ((a << 24) | (r << 16) | (g << 8) | (b << 0));
}