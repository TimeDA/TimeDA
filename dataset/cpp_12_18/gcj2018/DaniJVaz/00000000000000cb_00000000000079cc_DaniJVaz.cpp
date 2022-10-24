#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

const long double PI = 3.14159265358979L;
const long double EPS = 0.000000000001L;

struct point {
	long double x, y, z;
};

point operator+ (const point& p1, const point& p2) {
	point r = {p1.x+p2.x, p1.y+p2.y, p1.z+p2.z};
	return r;
}

point operator- (const point& p1, const point& p2) {
	point r = {p1.x-p2.x, p1.y-p2.y, p1.z-p2.z};
	return r;
}

long double dist(point p1, point p2);
long double computeArea3D(long double a, long double b);
long double areaTriangle(point p1, point p2, point p3);
point rotate3D(point p, long double a, long double b);
void printPoint(point p);



int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		double A;
		scanf("%lf", &A);
		printf("Case #%d:\n", iC);

		long double a = 0, b = PI/4;

		while (b-a > EPS) {
			long double t = (a+b)/2;
			long double areaT = computeArea3D(t, t);

			if (areaT <= A)
				a = t;
			else
				b = t;
		}

		point f1 = {0.5, 0, 0}, f2 = {0, 0.5, 0}, f3 = {0, 0, 0.5};
		printPoint(f1 = rotate3D(f1, a, a));
		printPoint(f2 = rotate3D(f2, a, a));
		printPoint(f3 = rotate3D(f3, a, a));

		// printf("Distances %lf %lf %lf\n", double(f1.x*f1.x+f1.y*f1.y+f1.z*f1.z), double(f2.x*f2.x+f2.y*f2.y+f2.z*f2.z), double(f3.x*f3.x+f3.y*f3.y+f3.z*f3.z));
		// printf("Dotprod 1-2 %lf\n", double(f1.x*f2.x+f1.y*f2.y+f1.z*f2.z));
	}
	return 0;
}

long double dist(point p1, point p2) {
	return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) + pow(p1.z-p2.z,2));
}

long double computeArea3D(long double a, long double b) {
	point f1 = {0.5, 0, 0}, f2 = {0, 0.5, 0}, f3 = {0, 0, 0.5};
	f1 = rotate3D(f1, a, b);
	f2 = rotate3D(f2, a, b);
	f3 = rotate3D(f3, a, b);

	f1.y = f2.y = f3.y = 0;
	
	return areaTriangle(f1 + f2 + f3, f1 + f2 - f3, f1 - f2 + f3) + areaTriangle(f1 - f2 - f3, f1 + f2 - f3, f1 - f2 + f3) + 
	       areaTriangle(f2 + f1 + f3, f2 + f1 - f3, f2 - f1 + f3) + areaTriangle(f2 - f1 - f3, f2 + f1 - f3, f2 - f1 + f3) + 
	       areaTriangle(f3 + f2 + f1, f3 + f2 - f1, f3 - f2 + f1) + areaTriangle(f3 - f2 - f1, f3 + f2 - f1, f3 - f2 + f1);
}

long double areaTriangle(point p1, point p2, point p3) {
	long double a = dist(p1, p2), b = dist(p2, p3), c = dist(p1, p3);
	long double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

point rotate3D(point p, long double a, long double b) {
	point p2;
	p2.x = p.x * cos(a) - p.y * sin(a);
	p2.y = p.x * sin(a) + p.y * cos(a);
	p2.z = p.z;

	point p3;
	p3.x = p2.x;
	p3.y = p2.z * sin(b) + p2.y * cos(b);
	p3.z = p2.z * cos(b) - p2.y * sin(b);
	return p3;
}

void printPoint(point p) {
	printf("%.9lf %.9lf %.9lf\n", (double) p.x, (double) p.y, (double) p.z);
}