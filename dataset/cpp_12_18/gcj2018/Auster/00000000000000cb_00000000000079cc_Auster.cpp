#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void rotate(double& x, double& y, double angle) {
	double nx = x * cos(angle) - y * sin(angle);
	double ny = y * cos(angle) + x * sin(angle);
	x = nx;
	y = ny;
}

double cross(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}


double square(double M) {
	vector<vector<double>> cube;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j)	{
			for (int k = 0; k < 2; ++k) {
				cube.push_back({-0.5 + i, -0.5 + j, -0.5 + k});
			}
		}
	}

	double angle = acos(-1.0) / 4;

	for (int i = 0; i < 8; ++i)	{
		rotate(cube[i][0], cube[i][1], -angle);
		rotate(cube[i][0], cube[i][2], -angle);
	}

	for (int i = 0; i < 8; ++i)	{
		rotate(cube[i][2], cube[i][1], M);
	}

	for (int i = 0; i < 8; ++i) {
		rotate(cube[i][0], cube[i][2], angle);
		rotate(cube[i][0], cube[i][1], angle);
	}

	vector<vector<double>> p;

	for (int i = 0; i < 8; ++i)	{
		p.push_back({cube[i][0], cube[i][2]});
	}

	//for (int i = 0; i < 8; ++i)	{
	//	cout << p[i][0] << " " << p[i][1] << endl;
	//}
	//cout << "-----";

	vector<int> hull;

	int v = 0;
	for (int i = 0; i < 8; ++i) {
		if (p[v][1] > p[i][1] || p[v][1] == p[i][1] && p[v][0] > p[i][0]) {
			v = i;
		}
	}

	hull.push_back(v);

	while (1) {
		int v = hull.back();
		int k = v == 0 ? 1 : 0;
		for (int i = 0; i < 8; ++i)	{
			if (i == v || i == k) {
				continue;
			}
			double x1 = p[k][0] - p[v][0];
			double y1 = p[k][1] - p[v][1];
			double x2 = p[i][0] - p[v][0];
			double y2 = p[i][1] - p[v][1];
			if (cross(x1, y1, x2, y2) < 0) {
				k = i;
			}
		}
		if (hull[0] == k) {//hypot(p[hull[0]][0] - p[k][0], p[hull[0]][1] - p[k][1]) < 1e-6) {
			break;
		}
		hull.push_back(k);
	}
	double res = 0;
	for (int i = 0; i < hull.size(); ++i) {
		int j = (i + 1) % hull.size();
		int v1 = hull[i];
		int v2 = hull[j];
		res += cross(p[v1][0], p[v1][1], p[v2][0], p[v2][1]);
	}
	return res / 2;
}


void solve(double a) {

	vector<vector<double>> pts(3, { 0, 0, 0 });
	for (int i = 0; i < 3; ++i) {
		pts[i][i] = 0.5;
	}

	//if (a < sqrt(2.0)) {
	//	double L = 0, R = acos(-1.0) / 4;
	//	for (int it = 0; it < 100; ++it) {
	//		double M = (L + R) / 2;
	//		double x1 = -0.5;
	//		double y1 = 0.5;
	//		double x2 = 0.5;
	//		double y2 = -0.5;
	//		rotate(x1, y1, M);
	//		rotate(x2, y2, M);
	//		if (x2 - x1 < a) {
	//			L = M;
	//		} else {
	//			R = M;
	//		}
	//	}
	//	for (int i = 0; i < 3; ++i) {
	//		rotate(pts[i][0], pts[i][1], (L + R) / 2);
	//	}
	//}
	//else {
		double L = 0, R = acos(-1.0) / 6;
		for (int it = 0; it < 100; ++it) {
			double M = (L + R) / 2;
			if (square(M) < a) {
				L = M;
			} else {
				R = M;
			}
		}

		double angle = acos(-1.0) / 4;

		for (int i = 0; i < 3; ++i) {
			rotate(pts[i][0], pts[i][1], -angle);
			rotate(pts[i][0], pts[i][2], -angle);
		}

		for (int i = 0; i < 3; ++i) {
			rotate(pts[i][2], pts[i][1], (L + R) / 2);
		}

		for (int i = 0; i < 3; ++i) {
			rotate(pts[i][0], pts[i][2], angle);
			rotate(pts[i][0], pts[i][1], angle);
		}
	//}

	cout.precision(9);
	cout << fixed;
	for(int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << pts[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		double a;
		cin >> a;
		cout << "Case #" << i << ":\n";
		solve(a);
	}
	return 0;
}