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
	TransMatrix ForwardKinematics(const std::vector<double>& joint_angle); // 由关节角度到末端位姿
	std::vector<double> InverseKinematics(const TransMatrix& t); // 由末端位姿到关节角度
};

#endif