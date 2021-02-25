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
	position_[0] += delta_x;
	position_[1] += delta_y;
	position_[2] += delta_z;

	return *this;
}

TransMatrix TransMatrix::TransSelf(double delta_x, double delta_y, double delta_z)
{
	TransBase(delta_x, delta_y, delta_z);

	return *this;
}

TransMatrix TransMatrix::RotBase(char axis, double theta)
{
	double n_temp[4]{ 1, 0, 0, 0 };
	double o_temp[4]{ 0, 1, 0, 0 };
	double a_temp[4]{ 0, 0, 1, 0 };
	double p_temp[4]{ 0, 0, 0, 1 };

	double s = sin(theta);
	double c = cos(theta);

	if (axis == 'x' || axis == 'X')
	{
		n_temp[1] = normal_[1] * c - normal_[2] * s;
		n_temp[2] = normal_[1] * s + normal_[2] * c;
		o_temp[1] = orientation_[1] * c - orientation_[2] * s;
		o_temp[2] = orientation_[1] * s + orientation_[2] * c;
		a_temp[1] = approach_[1] * c - approach_[2] * s;
		a_temp[2] = approach_[1] * s + approach_[2] * c;
		p_temp[1] = position_[1] * c - position_[2] * s;
		p_temp[2] = position_[1] * s + position_[2] * c;

		normal_[1] = n_temp[1];
		normal_[2] = n_temp[2];
		orientation_[1] = o_temp[1];
		orientation_[2] = o_temp[2];
		approach_[1] = a_temp[1];
		approach_[2] = a_temp[2];
		position_[1] = p_temp[1];
		position_[2] = p_temp[2];
	}
	else if (axis == 'y' || axis == 'Y')
	{
		n_temp[0] = normal_[0] * c + normal_[2] * s;
		n_temp[2] = -normal_[0] * s + normal_[2] * c;
		o_temp[0] = orientation_[0] * c + orientation_[2] * s;
		o_temp[2] = -orientation_[0] * s + orientation_[2] * c;
		a_temp[0] = approach_[0] * c + approach_[2] * s;
		a_temp[2] = -approach_[0] * s + approach_[2] * c;
		p_temp[0] = position_[0] * c + position_[2] * s;
		p_temp[2] = -position_[0] * s + position_[2] * c;

		normal_[0] = n_temp[0];
		normal_[2] = n_temp[2];
		orientation_[0] = o_temp[0];
		orientation_[2] = o_temp[2];
		approach_[0] = a_temp[0];
		approach_[2] = a_temp[2];
		position_[0] = p_temp[0];
		position_[2] = p_temp[2];
	}
	else if (axis == 'z' || axis == 'Z')
	{
		n_temp[0] = normal_[0] * c - normal_[1] * s;
		n_temp[1] = normal_[0] * s + normal_[1] * c;
		o_temp[0] = orientation_[0] * c - orientation_[1] * s;
		o_temp[1] = orientation_[0] * s + orientation_[1] * c;
		a_temp[0] = approach_[0] * c - approach_[1] * s;
		a_temp[1] = approach_[0] * s + approach_[1] * c;
		p_temp[0] = position_[0] * c - position_[1] * s;
		p_temp[1] = position_[0] * s + position_[1] * c;

		normal_[0] = n_temp[0];
		normal_[1] = n_temp[1];
		orientation_[0] = o_temp[0];
		orientation_[1] = o_temp[1];
		approach_[0] = a_temp[0];
		approach_[1] = a_temp[1];
		position_[0] = p_temp[0];
		position_[1] = p_temp[1];
	}
	else
	{
		std::cout << "Wrong axis name!" << std::endl;
		std::cout << "Axis name must be 'x', 'X', 'y', 'Y', 'z' or 'Z'. " << std::endl << std::endl;
	}

	return *this;
}

TransMatrix TransMatrix::RotSelf(char axis, double theta)
{
	double n_temp[4]{ 1, 0, 0, 0 };
	double o_temp[4]{ 0, 1, 0, 0 };
	double a_temp[4]{ 0, 0, 1, 0 };
	double p_temp[4]{ 0, 0, 0, 1 };

	double s = sin(theta);
	double c = cos(theta);

	if (axis == 'x' || axis == 'X')
	{
		o_temp[0] = orientation_[0] * c + approach_[0] * s;
		o_temp[1] = orientation_[1] * c + approach_[1] * s;
		o_temp[2] = orientation_[2] * c + approach_[2] * s;
		a_temp[0] = -orientation_[0] * s + approach_[0] * c;
		a_temp[1] = -orientation_[1] * s + approach_[1] * c;
		a_temp[2] = -orientation_[2] * s + approach_[2] * c;

		orientation_[0] = o_temp[0];
		orientation_[1] = o_temp[1];
		orientation_[2] = o_temp[2];
		approach_[0] = a_temp[0];
		approach_[1] = a_temp[1];
		approach_[2] = a_temp[2];
	}
	else if (axis == 'y' || axis == 'Y')
	{
		n_temp[0] = normal_[0] * c - approach_[0] * s;
		n_temp[1] = normal_[1] * c - approach_[1] * s;
		n_temp[2] = normal_[2] * c - approach_[2] * s;
		a_temp[0] = normal_[0] * s + approach_[0] * c;
		a_temp[1] = normal_[1] * s + approach_[1] * c;
		a_temp[2] = normal_[2] * s + approach_[2] * c;

		normal_[0] = n_temp[0];
		normal_[1] = n_temp[1];
		normal_[2] = n_temp[2];
		approach_[0] = a_temp[0];
		approach_[1] = a_temp[1];
		approach_[2] = a_temp[2];
	}
	else if (axis == 'z' || axis == 'Z')
	{
		n_temp[0] = normal_[0] * c + orientation_[0] * s;
		n_temp[1] = normal_[1] * c + orientation_[1] * s;
		n_temp[2] = normal_[2] * c + orientation_[2] * s;
		o_temp[0] = -normal_[0] * s + orientation_[0] * c;
		o_temp[1] = -normal_[1] * s + orientation_[1] * c;
		o_temp[2] = -normal_[2] * s + orientation_[2] * c;

		normal_[0] = n_temp[0];
		normal_[1] = n_temp[1];
		normal_[2] = n_temp[2];
		orientation_[0] = o_temp[0];
		orientation_[1] = o_temp[1];
		orientation_[2] = o_temp[2];
	}
	else
	{
		std::cout << "Wrong axis name!" << std::endl;
		std::cout << "Axis name must be 'x', 'X', 'y', 'Y', 'z' or 'Z'. " << std::endl << std::endl;
	}

	return *this;
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
