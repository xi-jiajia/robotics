#ifndef POSE_H_
#define POSE_H_

namespace robot
{
	class Pose
	{
	private:
		double normal_[4];
		double orientation_[4];
		double approach_[4];
		double position_[4];
	public:
		Pose();
		Pose(const double* normal, const double* orientation, const double* approach, const double* position);
		~Pose();
		int TransBase(double delta_x, double delta_y, double delta_z);
		int TransSelf(double delta_x, double delta_y, double delta_z);
		int RotBase(char axis, double angle);
		int RotSelf(char axis, double angle);
		void Show();
	};
}

#endif