#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include "trans_matrix.h"
#include "robot.h"

/*
// 测试trans_matrix.h与trans_matrix.cpp
int main()
{
	// trans matrix 0
	TransMatrix t0;
	std::cout << "trans matrix 0:" << std::endl;
	t0.ShowTransMatrix();

	// trans matrix 1
	double n_1[4]{ 0.527, 0.369, -0.766, 0 };
	double o_1[4]{ -0.547, 0.819, 0, 0 };
	double a_1[4]{ 0.628, 0.439, 0.643, 0 };
	double p_1[4]{ 5, 3, 8, 1 };
	TransMatrix t1{ n_1, o_1, a_1, p_1 };
	std::cout << "trans matrix 1:" << std::endl;
	t1.ShowTransMatrix();
	std::cout << "trans matrix 1 after trans base:" << std::endl;
	t1.TransBase(0, 10, 5).ShowTransMatrix();
	
	// position 0
	Coord p0{ 2, 3, 4 }, p1;
	p1 = t0.RotBase('x', M_PI_2).TransCoord(p0);
	std::cout << "position 0:" << std::endl;
	ShowCoord(p0);
	std::cout << "position 0 after rot base:" << std::endl;
	ShowCoord(p1);

	// position 2
	Coord p2{ 7, 3, 1 };
	Coord p3{};
	p3 = t0.RotBase('z', M_PI_2).RotBase('y', M_PI_2).TransBase(4, -3, 7).TransCoord(p2);
	std::cout << "position 2:" << std::endl;
	ShowCoord(p2);
	std::cout << "position 2 after trans and rot base:" << std::endl;
	ShowCoord(p3);

	// position 4
	Coord p4{};
	p4 = t0.RotBase('z', M_PI_2).TransBase(4, -3, 7).RotBase('y', M_PI_2).TransCoord(p2);
	std::cout << "position 2 after trans and rot base in different order:" << std::endl;
	ShowCoord(p4);

	// position 5
	Coord p5{};
	p5 = t0.RotSelf('a', M_PI_2).TransSelf(4, -3, 7).RotSelf('o', M_PI_2).TransCoord(p2);
	std::cout << "position 2 after trans and rot self:" << std::endl;
	ShowCoord(p5);

	// position 6
	Coord p6{ 1, 5, 4 };
	Coord p7{};
	p7 = t0.RotBase('x', M_PI_2).TransSelf(0, 0, 3).RotBase('z', M_PI_2).TransSelf(0, 5, 0).TransCoord(p6);
	std::cout << "position 6:" << std::endl;
	ShowCoord(p6);
	std::cout << "position 6 after trans and rot:" << std::endl;
	ShowCoord(p7);

	// trans matrix 2
	TransMatrix t2;
	std::cout << "trans matrix 2:" << std::endl;
	t2.RotBase('y', M_PI_2).RotSelf('o', M_PI / 6).TransSelf(5, 0, 0).TransBase(4, 0, 0).ShowTransMatrix();

	// trans matrix 3
	TransMatrix t3{};
	std::cout << "trans matrix 3:" << std::endl;
	t3 = t3.RotBase('x', 40 * M_PI / 180);
	t3.ShowTransMatrix();
	std::cout << "trans matrix 3 after inverse:" << std::endl;
	t3.Inverse().ShowTransMatrix();

	// trans matrix 4
	double n_4[4]{ 0.5, 0.866, 0, 0 };
	double o_4[4]{ 0, 0, 1, 0 };
	double a_4[4]{ 0.866, -0.5, 0, 0 };
	double p_4[4]{ 3, 2, 5, 1 };
	TransMatrix t4{ n_4, o_4, a_4, p_4 };
	std::cout << "trans matrix 4:" << std::endl;
	t4.ShowTransMatrix();
	std::cout << "trans matrix 4 after inverse:" << std::endl;
	t4.Inverse().ShowTransMatrix();

	// trans matrix multiplication
	std::cout << "product of trans matrix 4 and trans matrix 4 inverse:" << std::endl;
	TransMatrix t5 = t4.Inverse();
	(t4 * t5).ShowTransMatrix();

	double n_6[4]{ 1, 0, 0, 0 };
	double o_6[4]{ 0, 1, 0, 0 };
	double a_6[4]{ 0, 0, 1, 0 };
	double p_6[4]{ 0, 0, -3, 0 };

	double n_7[4]{ 0, -1, 0, 0 };
	double o_7[4]{ 1, 0, 0, 0 };
	double a_7[4]{ 0, 0, 1, 0 };
	double p_7[4]{ 0, 0, -4, 0 };

	double n_8[4]{ 0, 0, -1, 0 };
	double o_8[4]{ 0, -1, 0, 0 };
	double a_8[4]{ -1, 0, 0, 0 };
	double p_8[4]{ 3, 0, 5, 1 };

	double n_9[4]{ 0, 1, 0, 0 };
	double o_9[4]{ 0, 0, 1, 0 };
	double a_9[4]{ 1, 0, 0, 0 };
	double p_9[4]{ 2, 2, 4, 1 };
	
	TransMatrix t6{ n_6, o_6, a_6, p_6 };
	TransMatrix t7{ n_7, o_7, a_7, p_7 };
	TransMatrix t8{ n_8, o_8, a_8, p_8 };
	TransMatrix t9{ n_9, o_9, a_9, p_9 };
	std::cout << "product of trans matrix 6, 7, 8, 9:" << std::endl;
	(t6* t7* t8* t9).ShowTransMatrix();
}
*/

///*
// 测试robot.h与robot.cpp
int main()
{
	// robot 1
	Robot r1;
	std::cout << "dh of robot 1:" << std::endl;
	r1.ShowDH();

	// robot 2
	DH r2_dh[3]{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	Robot r2(r2_dh, 3);
	std::cout << "dh of robot 2:" << std::endl;
	r2.ShowDH();

	// robot 3
	DH r3_dh[2]{ {0, 0, 10, 0}, {0, 0, 10, 0} };
	Robot r3(r3_dh, 2);
	std::cout << "df of robot3:" << std::endl;
	r3.ShowDH();

	std::vector<double> r3_joint1{ 0, 0 };
	std::cout << "trans matrix of robot 3  when joints are (0, 0):" << std::endl;
	r3.ForwardKinematics(r3_joint1).ShowTransMatrix();

	std::vector<double> r3_joint2{ M_PI_2, 0 };
	std::cout << "trans matrix of robot 3 when joints are (pi/2, 0):" << std::endl;
	r3.ForwardKinematics(r3_joint2).ShowTransMatrix();

	// motoman k10
	DH motoman_k10_dh[6]
	{
		{0, 585, 200, M_PI_2},
		{M_PI_2, 0, 600, 0},
		{0, 0, 115, M_PI_2},
		{M_PI, 770, 0, M_PI_2},
		{M_PI, 0, 0, M_PI_2},
		{0, 100, 0, 0}
	};
	Robot motoman_k10(motoman_k10_dh, 6);
	std::cout << "dh of motoman k10:" << std::endl;
	motoman_k10.ShowDH();

	std::vector<double> motoman_k10_joint{ 0, 0, 0, 0, 0, 0 };
	std::cout << "trans matrix of motoman k10 when joints are (0, 0, 0, 0, 0, 0):" << std::endl;
	motoman_k10.ForwardKinematics(motoman_k10_joint).ShowTransMatrix();

	// robot 225

}
//*/