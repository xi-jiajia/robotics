#ifndef ROBOT_H_
#define ROBOT_H_

#include <vector>
#include "trans_matrix.h"

struct DH
{
	double theta;
	double d;
	double a;
	double alpha;
};

struct InverseSolution
{
	std::vector <double> joint_1;
	std::vector <double> joint_2;
	std::vector <double> joint_3;
	std::vector <double> joint_4;
	std::vector <double> joint_5;
	std::vector <double> joint_6;
};

class Robot
{
private:
	int dof_;
	std::vector<double> theta_;
	std::vector<double> d_;
	std::vector<double> a_;
	std::vector<double> alpha_;

public:
	Robot();
	Robot(const DH* dh, int dof);
	~Robot();
	void ShowDH();
	TransMatrix ForwardKinematics(const std::vector<double>& joint_angle);
	InverseSolution InverseKinematics(const double* normal, const double* orientation, const double* approach, const double* position);
};

#endif