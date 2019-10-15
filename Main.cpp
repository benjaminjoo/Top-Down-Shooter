#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Canvas.h"
#include "EventHandler.h"
#include "Math.h"

int main(int argc, char** argv)
{

	Canvas Screen(800, 600, "Top Down Shooter");
	EventHandler Controls;

	vect2 A(1.0f, 2.0f);
	vect2 B(3.0f, 4.0f);
	vect2 C = A + B;
	vect2 D = B - A;
	vect2 E = B * 3.0f;
	vect2 Bn = B.norm();

	std::cout << "C.x: " << C.x << "\tC.y: " << C.y << std::endl;
	std::cout << "D.x: " << D.x << "\tD.y: " << D.y << std::endl;
	std::cout << "E.x: " << E.x << "\tE.y: " << E.y << std::endl;
	std::cout << "Dot product of A and B: " << A * B << std::endl;
	std::cout << "Length of B: " << B.len() << std::endl;
	std::cout << "Bn.x: " << Bn.x << "\tBn.y: " << Bn.y << std::endl;

	while (!Controls.quit)
	{
		Controls.HandleUserEvents();
		Screen.update();
	}

	return 0;
}