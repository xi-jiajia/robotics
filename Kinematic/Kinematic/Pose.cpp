#include <iostream>
#include <cstring>
#include "Pose.h"

namespace robot
{
	Pose::Pose()
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

	Pose::Pose(const double* normal, const double* orientation, const double* approach, const double* position)
	{
		memcpy(normal_, normal, 4 * sizeof(double));
		memcpy(orientation_, orientation, 4 * sizeof(double));
		memcpy(approach_, approach, 4 * sizeof(double));
		memcpy(position_, position, 4 * sizeof(double));
	}

	Pose::~Pose()
	{

	}

	int Pose::TransBase(double delta_x, double delta_y, double delta_z)
	{
		position_[0] += delta_x;
		position_[1] += delta_y;
		position_[2] += delta_z;

		return 0;
	}

	int Pose::TransSelf(double delta_x, double delta_y, double delta_z)
	{


		return 0;
	}

	int RotBase(char axis, double angle)
	{


		return 0;
	}

	int RotSelf(char axis, double angle)
	{


		return 0;
	}

	void Pose::Show()
	{
		for (int i = 0; i < 4; i++)
		{
			std::cout << normal_[i] << "\t"
				<< orientation_[i] << "\t"
				<< approach_[i] << "\t"
				<< position_[i]
				<< std::endl;
		}
		std::cout << std::endl;
	}
}