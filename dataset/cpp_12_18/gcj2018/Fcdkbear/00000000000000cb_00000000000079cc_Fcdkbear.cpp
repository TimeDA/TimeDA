#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

vector<pair<double, pair<double, double>>> centers;
vector<pair<double, pair<double, double>>> vertices;

void rotateX(double xIn, double yIn, double zIn, double& xOut, double& yOut, double& zOut, double angle) {
	xOut = xIn;
	yOut = yIn * cos(angle) - zIn * sin(angle);
	zOut = yIn * sin(angle) + zIn * cos(angle);
}

void rotateY(double xIn, double yIn, double zIn, double& xOut, double& yOut, double& zOut, double angle) {
	xOut = xIn * cos(angle) + zIn * sin(angle);
	yOut = yIn;
	zOut = -xIn * sin(angle) + zIn * cos(angle);
}

void rotateZ(double xIn, double yIn, double zIn, double& xOut, double& yOut, double& zOut, double angle) {
	xOut = xIn * cos(angle) - yIn * sin(angle);
	yOut = xIn * sin(angle) + yIn * cos(angle);
	zOut = zIn;
}

void rotateXYZ(double xIn, double yIn, double zIn, double& xOut, double& yOut, double& zOut, double angleX, double angleY, double angleZ) {
	double xt, yt, zt;
	rotateX(xIn, yIn, zIn, xt, yt, zt, angleX);
	rotateY(xt, yt, zt, xt, yt, zt, angleY);
	rotateZ(xt, yt, zt, xOut, yOut, zOut, angleZ);
}


struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

double sq (const vector<pt> & fig)
{
	double res = 0;
	for (unsigned i=0; i<fig.size(); i++)
	{
		pt p1 = i ? fig[i-1] : fig.back(), p2 = fig[i];
		res += (p1.x - p2.x) * (p1.y + p2.y);
	}
	return fabs (res) / 2;
}

double calcArea(double angleX, double angleY, double angleZ) {
	vector<pt> a;
	FOR(i,0,centers.size()) {
		double x,y,z;
		rotateXYZ(vertices[i].first, vertices[i].second.first, vertices[i].second.second, x, y, z, angleX, angleY, angleZ);
		pt tmp; tmp.x = x; tmp.y = z;
		a.push_back(tmp);
	}
	convex_hull(a);
	return sq(a);
}

int main()
{
	int tests;
	cin >> tests;
	centers.push_back(mp(0, mp(-0.5, -0.5)));
	centers.push_back(mp(0, mp(0.5, -0.5)));
	centers.push_back(mp(-0.5, mp(0, -0.5)));
	centers.push_back(mp(0.5, mp(0, -0.5)));
	
	
	centers.push_back(mp(0, mp(-0.5, 0.5)));
	centers.push_back(mp(0, mp(0.5, 0.5)));
	centers.push_back(mp(-0.5, mp(0, 0.5)));
	centers.push_back(mp(0.5, mp(0, 0.5)));
	
	
	centers.push_back(mp(-0.5, mp(-0.5, 0)));
	centers.push_back(mp(-0.5, mp(0.5, 0)));
	centers.push_back(mp(0.5, mp(-0.5, 0)));
	centers.push_back(mp(0.5, mp(0.5, 0)));
	
	vertices.push_back(mp(-0.5, mp(-0.5, -0.5)));
	vertices.push_back(mp(-0.5, mp(-0.5, 0.5)));
	vertices.push_back(mp(-0.5, mp(0.5, -0.5)));
	vertices.push_back(mp(-0.5, mp(0.5, 0.5)));
	vertices.push_back(mp(0.5, mp(-0.5, -0.5)));
	vertices.push_back(mp(0.5, mp(-0.5, 0.5)));
	vertices.push_back(mp(0.5, mp(0.5, -0.5)));
	vertices.push_back(mp(0.5, mp(0.5, 0.5)));
	
	double mx = 0;
	double ans1, ans2, ans3;
	int N = 100000; 
	double prT = 0;
	//0.615485124728026
	
	FOR(testNumber, 1, tests + 1) {
		double a;
		cin >> a;
		if (a <= 1.414213) {
			double l = 0;
			double r = PI / 4;
			FOR(it,0,200) {
				double m = (l + r) / 2;
				double area = calcArea(m, 0, 0);
				//cout << m << " " << area << endl;
				if (area > a) {
					r = m;
				} else {
					l = m;
				}
			}
			double angleX = (l + r) / 2;
			printf("Case #%d:\n", testNumber);
			double xOut, yOut, zOut;
			rotateXYZ(0, 0, -0.5, xOut, yOut, zOut, angleX, 0, 0);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
			rotateXYZ(0, -0.5, 0, xOut, yOut, zOut, angleX, 0, 0);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
			rotateXYZ(-0.5, 0, 0, xOut, yOut, zOut, angleX, 0, 0);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
		} else {
			double l = 0;
			double r = 0.615485124728026;
			FOR(it,0,200) {
				double m = (l + r) / 2;
				double area = calcArea(PI / 4, 0, m);
				//cout << m << " " << area << endl;
				if (area > a) {
					r = m;
				} else {
					l = m;
				}
			}
			double angleZ = (l + r) / 2;
			printf("Case #%d:\n", testNumber);
			double xOut, yOut, zOut;
			rotateXYZ(0, 0, -0.5, xOut, yOut, zOut, PI / 4, 0, angleZ);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
			rotateXYZ(0, -0.5, 0, xOut, yOut, zOut, PI / 4, 0, angleZ);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
			rotateXYZ(-0.5, 0, 0, xOut, yOut, zOut, PI / 4, 0, angleZ);
			printf("%.15lf %.15lf %.15lf\n", xOut, yOut, zOut);
		}
		
	}
	return 0;
}