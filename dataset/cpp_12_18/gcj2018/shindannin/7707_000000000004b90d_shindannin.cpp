#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x&&x <= b; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS*max(1.0, max(fabs(x), fabs(y))); }
double SQSUM(double x, double y) { return x*x + y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

struct POS
{
	POS(double ix = 0.0, double iy = 0.0, double iz = 0.0) : x(ix), y(iy), z(iz) {}
	double x;
	double y;
	double z;
};

POS cross(const POS& a, const POS& b)
{
	POS ret;
	ret.x = a.y*b.z - a.z*b.y;
	ret.y = a.z*b.x - a.x*b.z;
	ret.z = a.x*b.y - a.y*b.x;
	return ret;
}

POS add(const POS& a, const POS& b)
{
	POS ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return ret;
}

POS mul(const POS& a, double k)
{
	POS ret;
	ret.x = a.x * k;
	ret.y = a.y * k;
	ret.z = a.z * k;
	return ret;
}

POS div(const POS& a, double k)
{
	assert(k != 0.0);
	return mul(a, 1.0 / k);
}

POS sub(const POS& a, const POS& b)
{
	POS ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return ret;
}

double dot(const POS& a, const POS& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}



int main()
{
	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int N;
		cin >> N;

		vector <double> x(N), y(N), z(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> x[i] >> y[i] >> z[i];
		}

		vector <int> perm(N);

		for (int i = 0; i < N; ++i)
		{
			perm[i] = i;
		}

		do
		{



			bool ok = true;

/*
			for (int i = 1; i < N - 1; ++i)
			{
				if ( ( x[perm[0]] * y[perm[1]] - x[perm[1]] * y[perm[0]]) * (x[perm[i]]*y[perm[i+1]]-x[perm[i+1]]*y[perm[i]]) < 0 )
				{
					ok = false;
					goto NUKE;
				}
			}
			*/

			for (int i = 0; i < N-2; ++i)
			{
				POS A(x[perm[i]], y[perm[i]], z[perm[i]]);
				POS B(x[perm[i + 1]], y[perm[i + 1]], z[perm[i + 1]]);
				POS C(x[perm[i + 2]], y[perm[i + 2]], z[perm[i + 2]]);

				POS AB = sub(B, A);
				POS AC = sub(C, A);
				POS n = cross(AB, AC);
				if (n.z < 0)
				{
					n.x *= -1;
					n.y *= -1;
					n.z *= -1;
				}

				double d = -dot(n, A);

				double checkB = dot(n, B) + d;
				double checkC = dot(n, C) + d;


				for (int k=0;k<i;k++)
				{
					double left = dot(n, POS(x[perm[k]], y[perm[k]], z[perm[k]])) + d;

					// BEGIN CUT HERE
//					cerr << " i=" << i << " k=" << k << " left=" << left << endl;
					// END CUT HERE


					if (left>0)
					{
						ok = false;
						goto NUKE;
					}
				}
			}

		NUKE:;


			if (ok)
			{
				printf("Case #%d: ", testcase + 1);
				for (int i = 0; i < N; ++i)
				{
					printf("%d%s", perm[i]+1, i==N-1?"\n":" ");
				}

				break;
			}
		} while (next_permutation(perm.begin(), perm.end()));


	}

	return 0;
}
