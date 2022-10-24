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

typedef vector <double> Vec;
typedef vector <Vec> Mtx;

Vec mul(const Mtx& A, const Vec& B)
{
	Vec C(SZ(B));
	for (int i = 0; i < SZ(A); i++)
	{
		for (int k = 0; k < SZ(B); k++)
		{
			C[i] = C[i] + A[i][k] * B[k];
		}
	}
	return C;
}

double calcArea(const Vec& a, const Vec& b, const Vec& c)
{
	double ab_x = b[0] - a[0];
	double ab_y = b[1] - a[1];
	double ac_x = c[0] - a[0];
	double ac_y = c[1] - a[1];

	return 0.5 * abs(ab_x*ac_y - ab_y*ac_x);
}

class RandXor
{
public:
	RandXor()
	{
		init();
	}

	void init()
	{
		x = 123456789;
		y = 362436069;
		z = 521288629;
		w = 88675123;
	}

	void init(ll seed)
	{
		x = 123456789;
		y = static_cast<unsigned int>(362436069 + seed);
		z = static_cast<unsigned int>(521288629 - seed);
		w = static_cast<unsigned int>(88675123 * seed);
	}


	inline unsigned int rand()
	{
		unsigned int t;
		t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}

	unsigned int next() {
		return rand();
	}

	unsigned int nextInt(int num) {
		return rand() % num;
	}

	unsigned char nextInt(unsigned char num) {
		return rand() % num;
	}

	// [a,b)
	int next(int a, int b) {
		return a + (rand() % (b - a));
	}

	// [-d,d]
	int nextDelta(int d) {
		return next(-d, d + 1);
	}

	double nextDouble() {
		return (rand() + 0.5) * (1.0 / 4294967296.0);
	}

	void randomShuffle(vector <int> &a) {
		const int n = SZ(a);
		for (int i = n - 1; i > 0; --i) {
			swap(a[i], a[nextInt(i + 1)]);
		}
	}

private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int w;
};

int main()
{
	int T;
	scanf("%d", &T);


	for (int testcase = 0; testcase < T; ++testcase)
	{
		double a;
		scanf("%lf", &a);

		double radianY = 0;
		double radianX = 0;
		double currentArea = 0;
		Vec best[3];

		RandXor xor;

		const int T = 2000000;
		for (int i=0;i<T;++i)
		{
			double backupRadianY = radianY;
			double backupRadianX = radianX;

			double ratio = (double)(T - i) / T;

			radianX += PI / 64 * ratio * (2.0*xor.nextDouble() - 1.0);
			radianY += PI / 64 * ratio * (2.0*xor.nextDouble() - 1.0);

			if (radianX < 0)
			{
				radianX = 0;
			}
			else if (radianX > PI / 4)
			{
				radianX = PI / 4;
			}

			if (radianY < 0)
			{
				radianY = 0;
			}
			else if (radianY > PI / 4)
			{
				radianY = PI / 4;
			}

			vector <Vec> vertices =
			{
				{ 0.5, 0.5, 0.5 },
				{ 0.5, -0.5, 0.5 },
				{ 0.5, -0.5, -0.5 },
				{ 0.5, 0.5, -0.5 },
				{ -0.5, 0.5, -0.5 },
				{ -0.5, 0.5, 0.5 },
				{ -0.5, -0.5, 0.5 },
				{ 0.5, 0, 0 },
				{ 0, 0.5, 0 },
				{ 0, 0, 0.5 },
			};


			Mtx rotateX =
			{
				{ 1, 0, 0 },
				{ 0, cos(radianX), -sin(radianX) },
				{ 0, sin(radianX), cos(radianX) },
			};

			Mtx rotateY =
			{
				{ cos(radianY), 0, sin(radianY) },
				{ 0, 1, 0 },
				{ -sin(radianY), 0, cos(radianY) },
			};

			for (Vec& v : vertices)
			{
				v = mul(rotateX, v);
				v = mul(rotateY, v);
			}

			double area = 0.0;

			area += calcArea(vertices[0], vertices[1], vertices[2]);
			area += calcArea(vertices[0], vertices[2], vertices[3]);
			area += calcArea(vertices[0], vertices[3], vertices[4]);
			area += calcArea(vertices[0], vertices[4], vertices[5]);
			area += calcArea(vertices[0], vertices[5], vertices[6]);
			area += calcArea(vertices[0], vertices[6], vertices[1]);

			if (abs(area - a) < abs(currentArea - a))
			{
				currentArea = area;
				best[0] = vertices[7];
				best[1] = vertices[8];
				best[2] = vertices[9];
			}
			else
			{
				radianY = backupRadianY;
				radianX = backupRadianX;
			}
		}

		printf("Case #%d:\n", testcase + 1);
		printf("%.16f %.16f %.16f\n", best[0][0], best[1][0], best[2][0]);
		printf("%.16f %.16f %.16f\n", best[0][1], best[1][1], best[2][1]);
		printf("%.16f %.16f %.16f\n", best[0][2], best[1][2], best[2][2]);
	}

	return 0;
}