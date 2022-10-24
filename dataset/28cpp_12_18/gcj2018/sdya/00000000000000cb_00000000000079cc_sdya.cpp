#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct pt {
	double x, y;
    pt() {}
    pt(double x, double y) : x(x), y(y) {}
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

double area(vector < pt > &a) {
    convex_hull(a);
    double res = 0.0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        res += a[i].x * a[(i + 1) % n].y - a[i].y * a[(i + 1) % n].x;
    }
    return fabs(res / 2.0) / 4.0;
}

double m[3][3];

void rotate(int index, double alpha, double &a, double &b, double &c) {
    if (index == 0) {
        m[0][0] = 1.0, m[0][1] = 0.0, m[0][2] = 0.0;
        m[1][0] = 0.0, m[1][1] = cos(alpha), m[1][2] = -sin(alpha);
        m[2][0] = 0.0, m[2][1] = sin(alpha), m[2][2] = cos(alpha);
    } else if (index == 1) {
        m[0][0] = cos(alpha), m[0][1] = 0.0, m[0][2] = sin(alpha);
        m[1][0] = 0.0, m[1][1] = 1,  m[1][2] = 0;
        m[2][0] = -sin(alpha), m[2][1] = 0, m[2][2] = cos(alpha);
    } else {
        m[0][0] = cos(alpha), m[0][1] = -sin(alpha), m[0][2] = 0;
        m[1][0] = sin(alpha), m[1][1] = cos(alpha),  m[1][2] = 0;
        m[2][0] = 0, m[2][1] = 0, m[2][2] = 1.0;
    }

    double na = m[0][0] * a + m[0][1] * b + m[0][2] * c;
    double nb = m[1][0] * a + m[1][1] * b + m[1][2] * c;
    double nc = m[2][0] * a + m[2][1] * b + m[2][2] * c;
    a = na;
    b = nb;
    c = nc;
}

double x[] = {-1,-1,-1,-1, 1, 1, 1, 1};
double y[] = {-1,-1, 1, 1,-1,-1, 1, 1};
double z[] = {-1, 1,-1, 1,-1, 1,-1, 1};

double cx[] = {0, 0, 1};
double cy[] = {0, 1, 0};
double cz[] = {1, 0, 0};

void solve(int test) {
    double A;
    scanf("%lf", &A);

    double bound = acos(0.0);
    int iters;
    double eps = 1e-6;
    if (A <= 1.414213) {
        for (double ang = 0; ang < bound; ang += eps * 2) {
            ++iters;
            vector < pt > a;
            for (int i = 0; i < 8; ++i) {
                double u = x[i], v = y[i], w = z[i];
                rotate(0, ang, u, v, w);
                a.push_back(pt(u, w));
            }
            double s = area(a);
            if (iters % 1000 == 0) {
                //cerr << s << endl;
            }
            //cerr << s << endl;
            if (fabs(A - s) < 1e-6) {
                printf("Case #%d:\n", test);
                for (int i = 0; i < 3; ++i) {
                    double u = cx[i], v = cy[i], w = cz[i];
                    rotate(0, ang, u, v, w);
                    printf("%.10lf %.10lf %.10lf\n", u / 2, v / 2, w / 2);
                }
                return;
            }
        }
    }
    for (double ang2 = 0; ang2 < bound; ang2 += eps * 2) {
        vector < pt > a;
        for (int i = 0; i < 8; ++i) {
            double u = x[i], v = y[i], w = z[i];
            rotate(0, bound / 2.0, u, v, w);
            rotate(2, ang2, u, v, w);
            a.push_back(pt(u, w));
        }
        double s = area(a);
        if (fabs(A - s) < 1e-6) {
            printf("Case #%d:\n", test);
            for (int i = 0; i < 3; ++i) {
                double u = cx[i], v = cy[i], w = cz[i];
                rotate(0, bound / 2.0, u, v, w);
                rotate(2, ang2, u, v, w);
                printf("%.10lf %.10lf %.10lf\n", u / 2, v / 2, w / 2);
            }
            return;
        }
    }
    
    cerr << "BAD" << endl;
}

int main(int argc, char* argv[]) {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}
	return 0;
}