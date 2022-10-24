#include<bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
const double root2by2 = sqrt(2) / 2;

struct Point {
	double x, y;
};

Point rotatePoint(double x, double y, double theta) {
	Point p;
	p.x = cos(theta) * x - sin(theta) * y;
	p.y = sin(theta) * x + cos(theta) * y;
	return p;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		double A;
		cin >> A;

		double L = A / 2;
		double theta = acos(L / root2by2);
		double rotate = pi / 4 - theta;

		//printf("%.8lf %.8lf\n", theta, rotate);

		Point p1, p2, p3;
		p1 = rotatePoint(0, 0.5, rotate);
		p2 = rotatePoint(0.5, 0, rotate);
		p3.x = 0; p3.y = 0;

		cout << "Case #" << cases << ":" << endl;
		printf("%.15lf %.15lf %.15lf\n", p1.x, p1.y, 0);
		printf("%.15lf %.15lf %.15lf\n", p2.x, p2.y, 0);
		printf("%.15lf %.15lf %.15lf\n", p3.x, p3.y, 0.5);

	}
	return 0;
}

