#include <iostream>
#include <cmath>
#include "Triangle.h"

int main()
{
	setlocale(0, "");
	Triangle triangleA(3, 5, 33);
	std::cout << triangleA.getBC() << std::endl;
	std::cout << triangleA.getAngleC() << std::endl;
	std::cout << triangleA.getSquare() << std::endl;
	std::cout << triangleA.getPerimeter() << std::endl;
	std::cout << triangleA.getTriangleType() << std::endl;
	std::cout << triangleA.toString() << std::endl;
	Triangle triangleB;
	std::cout << triangleB.getBC() << std::endl;
}