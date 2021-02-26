#ifndef TRANS_MATRIX_H_
#define TRANS_MATRIX_H_

struct Coord
{
	double x;
	double y;
	double z;
};

void ShowCoord(Coord c);

class TransMatrix
{
private:
	double normal_[4];
	double orientation_[4];
	double approach_[4];
	double position_[4];
public:
	TransMatrix();
	TransMatrix(const double* normal, const double* orientation, const double* approach, const double* position);
	~TransMatrix();
	TransMatrix TransBase(double delta_x, double delta_y, double delta_z);
	TransMatrix TransSelf(double delta_x, double delta_y, double delta_z);
	TransMatrix RotBase(char axis, double theta);
	TransMatrix RotSelf(char axis, double theta);
	Coord TransCoord(Coord c);
	void ShowTransMatrix();
};

#endif