#include <iostream>
#include <iomanip>
#include <vector>
#include "robot.h"

Robot::Robot()
{
	dof_ = 0;
}

Robot::Robot(const DH* dh, int dof)
{
	dof_ = dof;

	for (int i = 0; i < dof; i++)
	{
		theta_.push_back(dh[i].theta);
		d_.push_back(dh[i].d);
		a_.push_back(dh[i].a);
		alpha_.push_back(dh[i].alpha);
	}
}

Robot::~Robot()
{
	
}

void Robot::ShowDH()
{
	std::cout << std::setw(30) << "D-H" << std::endl;
	std::cout << std::setw(10) << "theta"
		<< std::setw(15) << "d"
		<< std::setw(15) << "a"
		<< std::setw(15) << "alpha" << std::endl;
	for (int i = 0; i < dof_; i++)
	{
		std::cout << std::setw(10) << theta_[i]
			<< std::setw(15) << d_[i]
			<< std::setw(15) << a_[i]
			<< std::setw(15) << alpha_[i] << std::endl;
	}
	std::cout << std::endl;
}

TransMatrix Robot::ForwardKinematics(const std::vector<double>& joint_angle)
{
	TransMatrix temp;

	for (int i = 0; i < joint_angle.size(); i++)
	{
		temp = temp.RotSelf('a', theta_[i] + joint_angle[i]).TransSelf(0, 0, d_[i]).TransSelf(a_[i], 0, 0).RotSelf('n', alpha_[i]);
	}

	return temp;
}

std::vector<double> Robot::InverseKinematics(const TransMatrix& t)
{
	std::vector<double> temp;
	return temp;
}