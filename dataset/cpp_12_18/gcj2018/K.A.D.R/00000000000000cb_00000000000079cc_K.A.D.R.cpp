#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#define GETS gets_s
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <stdio.h>
#define GETS gets
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

struct P {
	double x, y, z;
};

int a, b, c, d, n, m, k, kolt;

const double tt[] = { -0.5, 0.5 };

inline void rot(double &x, double &y, double a) {
	double ca = cos(a), sa = sin(a);
	double nx = ca * x - sa * y;
	double ny = sa * x + ca * y;

	x = nx; y = ny;
}

inline pdd operator -(const pdd &a, const pdd &b) {
	return mp(a.x - b.x, a.y - b.y);
}
inline double vec(const pdd &a, const pdd &b) {
	return a.x * b.y - b.x * a.y;
}
vector<pdd> ConvexHull(vector<pdd> a) {
	SORT(a);
	vector<pdd> res;
	rept(iter, 2) {
		vector<pdd> hull;
		rept(i, L(a)) {
			while (L(hull) >= 2 &&
				vec((a[i] - hull.back()), (hull.back() - hull[L(hull) - 2])) <= 0)
				hull.pop_back();
			hull.push_back(a[i]);
		}
		hull.pop_back();
		res.insert(res.end(), all(hull));
		reverse(all(a));
	}
	return res;
}

inline double calc(double a1, double a2) {
	vector<P> pnt;
	pnt.reserve(8);
	rept(x, 2) {
		rept(y, 2) {
			rept(z, 2) {
				pnt.push_back({ tt[x], tt[y], tt[z] });
			}
		}
	}

	// first angle
	rept(i, L(pnt)) {
		rot(pnt[i].x, pnt[i].y, a1);
	}

	// second angle
	rept(i, L(pnt)) {
		rot(pnt[i].y, pnt[i].z, a2);
	}

	vector<pdd> proj;
	rept(i, L(pnt)) {
		proj.pb(mp(pnt[i].x, pnt[i].z));
	}
	vector<pdd> hull = ConvexHull(proj);

	double s = 0.0;
	rept(i, L(hull)) {
		s += hull[i].x * hull[(i + 1) % L(hull)].y - hull[i].y * hull[(i + 1) % L(hull)].x;
	}
	if (s < 0) s = -s;
	s /= 2;
	return s;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		double A;
		scanf("%lf", &A);

		int c = 0;
		double p1 = calc(pi / 4, 0.0);
		if (p1 > A) {
			c = 0;
		}
		else {
			c = 1;
		}

		double l = 0.0, r = c ? (pi / 4) * (pi / 4) : pi / 4;

		rep(hod, 100) {
			double xx = (r + l) / 2;

			double a1 = 0.0, a2 = 0.0;
			if (!c) {
				a1 = xx;
			}
			else {
				a1 = pi / 4;
				a2 = xx;
			}

			double p = calc(a1, a2);
			if (p > A) r = xx; else
				l = xx;
		}


		double a1 = 0.0, a2 = 0.0;
		if (!c) a1 = (l + r) / 2.0; else {
			a1 = pi / 4;
			a2 = (l + r) / 2.0;
		}
		printf("Case #%d:\n", hod);

		vector<P> pnt;
		pnt.pb({ 0.5, 0.0, 0.0 });
		pnt.pb({ 0.0, 0.5, 0.0 });
		pnt.pb({ 0.0, 0.0, 0.5 });

		rept(i, L(pnt)) {
			rot(pnt[i].x, pnt[i].y, a1);
		}
		rept(i, L(pnt)) {
			rot(pnt[i].y, pnt[i].z, a2);
		}

		rept(i, L(pnt)) {
			printf("%.12lf %.12lf %.12lf\n", pnt[i].x, pnt[i].y, pnt[i].z);
		}
	}
}
