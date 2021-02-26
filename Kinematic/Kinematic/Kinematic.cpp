﻿#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "trans_matrix.h"

int main()
{
	TransMatrix t0;
	std::cout << "t0:" << std::endl;
	t0.ShowTransMatrix();

	double n_1[4]{ 0.527, 0.369, -0.766, 0 };
	double o_1[4]{ -0.547, 0.819, 0, 0 };
	double a_1[4]{ 0.628, 0.439, 0.643, 0 };
	double p_1[4]{ 5, 3, 8, 1 };
	TransMatrix t1{ n_1, o_1, a_1, p_1 };
	std::cout << "t1:" << std::endl;
	t1.ShowTransMatrix();
	std::cout << "t1 after trans base:" << std::endl;
	t1.TransBase(0, 10, 5).ShowTransMatrix();
	
	Coord p0{ 2, 3, 4 }, p1;
	p1 = t0.RotBase('x', M_PI_2).TransCoord(p0);
	std::cout << "p0:" << std::endl;
	ShowCoord(p0);
	std::cout << "p0 after rot base:" << std::endl;
	ShowCoord(p1);

	Coord p2{ 7, 3, 1 };
	Coord p3{};
	p3 = t0.RotBase('z', M_PI_2).RotBase('y', M_PI_2).TransBase(4, -3, 7).TransCoord(p2);
	std::cout << "p2:" << std::endl;
	ShowCoord(p2);
	std::cout << "p2 after trans and rot base:" << std::endl;
	ShowCoord(p3);

	Coord p4{};
	p4 = t0.RotBase('z', M_PI_2).TransBase(4, -3, 7).RotBase('y', M_PI_2).TransCoord(p2);
	std::cout << "p2 after trans and rot base in different order:" << std::endl;
	ShowCoord(p4);

	Coord p5{};
	p5 = t0.RotSelf('a', M_PI_2).TransSelf(4, -3, 7).RotSelf('o', M_PI_2).TransCoord(p2);
	std::cout << "p2 after trans and rot self:" << std::endl;
	ShowCoord(p5);

	Coord p6{ 1, 5, 4 };
	Coord p7{};
	p7 = t0.RotBase('x', M_PI_2).TransSelf(0, 0, 3).RotBase('z', M_PI_2).TransSelf(0, 5, 0).TransCoord(p6);
	std::cout << "p6:" << std::endl;
	ShowCoord(p6);
	std::cout << "p6 after trans and rot:" << std::endl;
	ShowCoord(p7);

	TransMatrix t2;
	std::cout << "t2:" << std::endl;
	t2.RotBase('y', M_PI_2).RotSelf('o', M_PI / 6).TransSelf(5, 0, 0).TransBase(4, 0, 0).ShowTransMatrix();
}