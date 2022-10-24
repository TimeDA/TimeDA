
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;
double A;
class rPOINT;
class POINT {
public:
	POINT() {}
	POINT(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	POINT(rPOINT p);
	double x, y, z;
	POINT operator * (double r) {
		return POINT(x*r, y*r, z*r);
	}
	POINT operator + (POINT p) {
		return POINT(x + p.x, y + p.y, z + p.z);
	}
	void print() {
		printf("%.18lf %.18lf %.18lf\n", x, y, z);
	}
};
class rPOINT {
public:
	rPOINT(POINT p) {
		r = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
		theta = acos(p.z / r);
		phi = atan2(p.y, p.x);
	}
	double theta, phi, r;
	void rotate(double dt, double dp) {
		theta += dt;
		phi += dp;
	}
};
POINT::POINT(rPOINT p) {
	x = p.r * sin(p.theta) * cos(p.phi);
	y = p.r * sin(p.theta) * sin(p.phi);
	z = p.r * cos(p.theta);
}
POINT p1(0.5, 0, 0), p2(0, 0.5, 0), p3(0, 0, 0.5);
//POINT c1(0.5, 0.5, 0.5), c2(0.5, 0.70710678118654752440084436210485, 0);
POINT c1(0.5, 0.5, 0.5), c2(0, 0.86602540378443864676372317075294, 0);

double CCW(POINT a, POINT b, POINT c) {
	return (a.x * b.z + b.x * c.z + c.x * a.z)
		- (a.z * b.x + b.z * c.x + c.z * a.x);
}
double dist(POINT a, POINT b) {
	double dx = a.x - b.x;
	double dz = a.z - b.z;
	return sqrt(dx*dx + dz * dz);
}
double getArea(POINT a, POINT b, POINT c) {
	vector<POINT> P;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
		POINT p(0, 0, 0);
		p = (a * (i ? 1.0 : -1.0)) + (b * (j ? 1.0 : -1.0)) + (c * (k ? 1.0 : -1.0));
		P.push_back(p);
	}
	double area = 0;
	int N = (int)P.size();
	sort(P.begin(), P.end(), [](POINT a, POINT b) -> bool {
		return a.x < b.x;
	});
	sort(P.begin() + 1, P.end(), [&P](POINT a, POINT b) -> bool {
		double ta = atan2(a.z - P[0].z, a.x - P[0].x);
		double tb = atan2(b.z - P[0].z, b.x - P[0].x);
		return ta < tb;
	});
	vector<POINT> Q;
	Q.push_back(P[0]);
	Q.push_back(P[1]);
	int Qn = 2;
	const double ep = 1e-16;
	for (int i = 2; i < N; i++) {
		while (Qn >= 2) {
			double ccw = CCW(Q[Qn - 2], Q[Qn - 1], P[i]);
			if (ccw < -ep || ccw < ep && dist(Q[Qn - 2], Q[Qn - 1]) < dist(Q[Qn - 2], P[i])) {
				Qn--;
				Q.pop_back();

			}
			else break;
		}
		Q.push_back(P[i]);
		Qn++;
	}
	for (int i = 1; i+1 < Qn; i++) {
		area += CCW(Q[0], Q[i], Q[i + 1]);
	}
	area /= 2.0;
	return area;
}
POINT rotate(POINT p, double dx, double dz) {
	POINT r;
	r.x = p.x;
	r.y = cos(dx) * p.y - sin(dx) * p.z;
	r.z = sin(dx) * p.y + cos(dx) * p.z;

	POINT q;
	q.x = cos(dz) * r.x - sin(dz) * r.y;
	q.y = sin(dz) * r.x + cos(dz) * r.y;
	q.z = r.z;
	return q;
}
const double phi = 3.1415926535897932384626433832795;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%lf", &A);
		rPOINT rc1(c1), rc2(c2);
		//double dtheta = rc2.theta - rc1.theta;
		//double dphi = rc2.phi - rc1.phi;
		double dtheta = phi * 0.25;
		double dphi = phi * 0.195913;
		double ms = 0, me = 1;
		POINT pp1, pp2, pp3;
		double area;
		for (int i = 0; i < 500; i++) {
			double mm = (ms + me) / 2.0;
			double dt = dtheta * mm;
			double dp = dphi * mm;
			pp1 = rotate(p1, dt, dp);
			pp2 = rotate(p2, dt, dp);
			pp3 = rotate(p3, dt, dp);
			area = getArea(pp1, pp2, pp3);
			if (area < A) ms = mm;
			else me = mm;
		}

		static int cs = 1;
		printf("Case #%d: \n", cs++);
		pp1.print();
		pp2.print();
		pp3.print();
		//fprintf(stderr, "%.12lf %.12lf\n", area, A); 

	}
	return 0;
}