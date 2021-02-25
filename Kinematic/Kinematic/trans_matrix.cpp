#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "trans_matrix.h"

TransMatrix::TransMatrix()
{
	double n_temp[4]{ 1, 0, 0, 0 };
	double o_temp[4]{ 0, 1, 0, 0 };
	double a_temp[4]{ 0, 0, 1, 0 };
	double p_temp[4]{ 0, 0, 0, 1 };

	memcpy(normal_, n_temp, 4 * sizeof(double));
	memcpy(orientation_, o_temp, 4 * sizeof(double));
	memcpy(approach_, a_temp, 4 * sizeof(double));
	memcpy(position_, p_temp, 4 * sizeof(double));
}

TransMatrix::TransMatrix(const double* normal, const double* orientation, const double* approach, const double* position)
{
	memcpy(normal_, normal, 4 * sizeof(double));
	memcpy(orientation_, orientation, 4 * sizeof(double));
	memcpy(approach_, approach, 4 * sizeof(double));
	memcpy(position_, position, 4 * sizeof(double));
}

TransMatrix::~TransMatrix()
{

}

TransMatrix TransMatrix::TransBase(double delta_x, double delta_y, double delta_z)
{
	TransMatrix temp(*this);

	temp.position_[0] = position_[0] + delta_x;
	temp.position_[1] = position_[1] + delta_y;
	temp.position_[2] = position_[2] + delta_z;

	return temp;
}

TransMatrix TransMatrix::TransSelf(double delta_x, double delta_y, double delta_z)
{
	TransBase(delta_x, delta_y, delta_z);

	return *this;
}

TransMatrix TransMatrix::RotBase(char axis, double theta)
{
	TransMatrix temp(*this);

	double s = sin(theta);
	double c = cos(theta);

	if (axis == 'x' || axis == 'X')
	{
		temp.normal_[1] = normal_[1] * c - normal_[2] * s;
		temp.normal_[2] = normal_[1] * s + normal_[2] * c;
		temp.orientation_[1] = orientation_[1] * c - orientation_[2] * s;
		temp.orientation_[2] = orientation_[1] * s + orientation_[2] * c;
		temp.approach_[1] = approach_[1] * c - approach_[2] * s;
		temp.approach_[2] = approach_[1] * s + approach_[2] * c;
		temp.position_[1] = position_[1] * c - position_[2] * s;
		temp.position_[2] = position_[1] * s + position_[2] * c;
	}
	else if (axis == 'y' || axis == 'Y')
	{
		temp.normal_[0] = normal_[0] * c + normal_[2] * s;
		temp.normal_[2] = -normal_[0] * s + normal_[2] * c;
		temp.orientation_[0] = orientation_[0] * c + orientation_[2] * s;
		temp.orientation_[2] = -orientation_[0] * s + orientation_[2] * c;
		temp.approach_[0] = approach_[0] * c + approach_[2] * s;
		temp.approach_[2] = -approach_[0] * s + approach_[2] * c;
		temp.position_[0] = position_[0] * c + position_[2] * s;
		temp.position_[2] = -position_[0] * s + position_[2] * c;
	}
	else if (axis == 'z' || axis == 'Z')
	{
		temp.normal_[0] = normal_[0] * c - normal_[1] * s;
		temp.normal_[1] = normal_[0] * s + normal_[1] * c;
		temp.orientation_[0] = orientation_[0] * c - orientation_[1] * s;
		temp.orientation_[1] = orientation_[0] * s + orientation_[1] * c;
		temp.approach_[0] = approach_[0] * c - approach_[1] * s;
		temp.approach_[1] = approach_[0] * s + approach_[1] * c;
		temp.position_[0] = position_[0] * c - position_[1] * s;
		temp.position_[1] = position_[0] * s + position_[1] * c;
	}
	else
	{
		std::cout << "Wrong axis name!" << std::endl;
		std::cout << "Axis name must be 'x', 'X', 'y', 'Y', 'z' or 'Z'. " << std::endl << std::endl;
	}

	return temp;
}

TransMatrix TransMatrix::RotSelf(char axis, double theta)
{
	TransMatrix temp(*this);

	double s = sin(theta);
	double c = cos(theta);

	if (axis == 'x' || axis == 'X')
	{
		temp.orientation_[0] = orientation_[0] * c + approach_[0] * s;
		temp.orientation_[1] = orientation_[1] * c + approach_[1] * s;
		temp.orientation_[2] = orientation_[2] * c + approach_[2] * s;
		temp.approach_[0] = -orientation_[0] * s + approach_[0] * c;
		temp.approach_[1] = -orientation_[1] * s + approach_[1] * c;
		temp.approach_[2] = -orientation_[2] * s + approach_[2] * c;
	}
	else if (axis == 'y' || axis == 'Y')
	{
		temp.normal_[0] = normal_[0] * c - approach_[0] * s;
		temp.normal_[1] = normal_[1] * c - approach_[1] * s;
		temp.normal_[2] = normal_[2] * c - approach_[2] * s;
		temp.approach_[0] = normal_[0] * s + approach_[0] * c;
		temp.approach_[1] = normal_[1] * s + approach_[1] * c;
		temp.approach_[2] = normal_[2] * s + approach_[2] * c;
	}
	else if (axis == 'z' || axis == 'Z')
	{
		temp.normal_[0] = normal_[0] * c + orientation_[0] * s;
		temp.normal_[1] = normal_[1] * c + orientation_[1] * s;
		temp.normal_[2] = normal_[2] * c + orientation_[2] * s;
		temp.orientation_[0] = -normal_[0] * s + orientation_[0] * c;
		temp.orientation_[1] = -normal_[1] * s + orientation_[1] * c;
		temp.orientation_[2] = -normal_[2] * s + orientation_[2] * c;
	}
	else
	{
		std::cout << "Wrong axis name!" << std::endl;
		std::cout << "Axis name must be 'x', 'X', 'y', 'Y', 'z' or 'Z'. " << std::endl << std::endl;
	}

	return temp;
}

void TransMatrix::Show()
{
	std::cout << std::fixed;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(10) << std::right << normal_[i]
			<< std::setw(15) << std::right << orientation_[i]
			<< std::setw(15) << std::right << approach_[i]
			<< std::setw(15) << std::right << position_[i] << std::endl;
	}
	std::cout << std::endl;
}
