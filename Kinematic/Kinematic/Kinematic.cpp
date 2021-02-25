#include <iostream>
#include "Pose.h"

using namespace robot;

int main()
{
    Pose p1;
    p1.Show();

    double n[4]{ 0.527, 0.369, -0.766, 0 };
    double o[4]{ -0.547, 0.819, 0, 0 };
    double a[4]{ 0.628, 0.439, 0.643, 0 };
    double p[4]{ 5, 3, 8, 1 };

    Pose p2{ n, o, a, p };
    p2.Show();

    Pose p3;
    p3.TransBase(1, 1, 1);
    p3.Show();
}