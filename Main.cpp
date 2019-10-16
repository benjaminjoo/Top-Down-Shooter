#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Canvas.h"
#include "EventHandler.h"
#include "Math.h"
#include "Projectile.h"

int main(int argc, char** argv)
{

	Canvas Screen(800, 600, 1.0f, "Top Down Shooter");
	Screen.setClearColour(0, 255, 255, 255);
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

	Projectile bullet(vect2(0.0f, 0.0f), 0.0f, vect2(3.0f, 4.0f), vect2(0.0f, 0.0f), 5.0f);
	std::cout << "Kinetic energy of bullet: " << bullet.getKineticEnergy() << std::endl;


	int x = 100, y = 200;
	std::cout << "x: " << x << "\ty: " << y << std::endl;
	swap(x, y);
	std::cout << "x: " << x << "\ty: " << y << std::endl;

	vect2 P( 50.0f, 100.0f);
	vect2 Q(500.0f, 250.0f);

	

	while (!Controls.quit)
	{
		boundingBoxScreen bb1(P.onScreen(1.0), Q.onScreen(1.0));

		Controls.HandleUserEvents();

		Screen.clear();
		
		Screen.drawBoundingBox(bb1, 255);
		//Screen.drawLine(P.onScreen(1.0), Q.onScreen(1.0), 255);

		Screen.update();

		P.x += 0.5f;
		Q.y += 1.0f;
	}

	return 0;
}