#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "trans_matrix.h"

int main()
{
	//TransMatrix t0;
	//std::cout << "t0:" << std::endl;
	//t0.Show();

	//double n_1[4]{ 0.527, 0.369, -0.766, 0 };
	//double o_1[4]{ -0.547, 0.819, 0, 0 };
	//double a_1[4]{ 0.628, 0.439, 0.643, 0 };
	//double p_1[4]{ 5, 3, 8, 1 };
	//TransMatrix t1{ n_1, o_1, a_1, p_1 };
	//TransMatrix t2;
	//std::cout << "t1:" << std::endl;
	//t1.Show();
	//t2 = t1.TransBase(0, 10, 5);
	//std::cout << "t2:" << std::endl;
	//t2.Show();
	//
	//TransMatrix t3, t4;
	//std::cout << "t4:" << std::endl;
	//t4 = t3.RotBase('z', M_PI_2).RotBase('y', M_PI_2).TransBase(4, -3, 7);
	//t4.Show();

	TransMatrix t[6];
	t[0].RotBase('x', M_PI_2).Show();
	t[1].RotBase('y', M_PI_2).Show();
	t[2].RotBase('z', M_PI_2).Show();
	t[3].RotSelf('X', M_PI_2).Show();
	t[4].RotSelf('Y', M_PI_2).Show();
	t[5].RotSelf('z', M_PI_2).Show();
}