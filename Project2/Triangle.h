#define M_PI       3.14159265358979323846
#include <string>

class Triangle
{
private:
	double sideAB, sideBC, sideAC, p;
	double angleA, angleB, angleC;
	double heightAB, heightBC, heightAC;
	double square, perimeter;
	std::string type;
public:
	Triangle(double AB, double AC, double A)
	{
		sideAB = AB;
		sideAC = AC;

		if (A > 180) A = 360 - A;
		angleA = A;

		sideBC = sqrt(AB * AB + AC * AC - 2 * AB * AC * cos(A * M_PI / 180));
		angleB = acos((AB * AB + sideBC * sideBC - AC * AC) / (2 * AB * sideBC)) * 180 / M_PI;
		angleC = 180 - A - angleB;
		if (sideAB == sideAC && round(sideBC*1000)/1000 == sideAC) 
			type.append("Equilateral ");
		if (round(angleA*1000)/1000 == round(angleB*1000)/1000 || angleA == round(angleC*1000)/1000 || round(angleB*1000)/1000 == round(angleC * 1000)/1000)
			type.append("Isosceles ");
		if (angleA == 90 || angleB == 90 || angleC == 90) 
			type.append("Rectangular ");
		else if (type=="") type.append("Common");

		p = (sideAB + sideAC + sideBC) / 2;
		square = sqrt(p * (p - sideAB) * (p - sideAC) * (p - sideBC));
		perimeter = p * 2;
		heightAB = (2 * sqrt(p * (p - sideAB) * (p - sideAC) * (p - sideBC))) / sideAB;
		heightAC = (2 * sqrt(p * (p - sideAB) * (p - sideAC) * (p - sideBC))) / sideAC;
		heightBC = (2 * sqrt(p * (p - sideAB) * (p - sideAC) * (p - sideBC))) / sideBC;


	}
	Triangle()
	{
		sideAB = sideBC = sideAC = p = 0;
		angleA = angleB = angleC = 0;
	};

	double getAB() { return sideAB; }
	double getBC() { return sideBC; }
	double getAC() { return sideAC; }

	double getAngleA() { return angleA; }
	double getAngleB() { return angleB; }
	double getAngleC() { return angleC; }

	double getSquare() { return square; }
	double getPerimeter() { return perimeter; }
	double getHeightAB() { return heightAB; }
	double getHeightBC() { return heightBC; }
	double getHeightAC() { return heightAC; }

	void setAB(double side) { sideAB = side; }
	void setBC(double side) { sideBC = side; }
	void setAC(double side) { sideAC = side; }

	void setAngleA(double angle) { angleA = angle; }
	void setAngleB(double angle) { angleB = angle; }
	void setAngleC(double angle) { angleC = angle; }


	std::string getTriangleType()	{ return type; }
	std::string toString() {
		return "Sides: " + std::to_string(sideAB) + " " + std::to_string(sideAC) + " " + std::to_string(sideBC) + " " + '\n'
			+ "Angles: " + std::to_string(angleA) + " " + std::to_string(angleB) + " " + std::to_string(angleC) + '\n'
			+ "Square: " + std::to_string(square) + '\n'
			+ "Perimeter: " + std::to_string(perimeter) + '\n'
			+ "Heights: " + std::to_string(heightAB) + " " + std::to_string(heightAC) + " " + std::to_string(heightBC) + '\n'
			+ "Type: " + type;
	}
};

