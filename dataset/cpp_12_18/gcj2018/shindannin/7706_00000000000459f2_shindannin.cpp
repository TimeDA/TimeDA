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

int main()
{

	int T;
	scanf("%d ", &T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int w;
		cin >> w;

		vector <int> x(w);
		vector <int> goal(w);

		int sum = 0;
		for (int i = 0; i < w; ++i)
		{
			cin >> x[i];
			sum += x[i];
		}

		bool ok = true;
		if (sum != w)
		{
			ok = false;
		}

		if (x[0] == 0)
		{
			ok = false;
		}

		if (x[w - 1] == 0)
		{
			ok = false;
		}

		if (ok)
		{
			int i = 0;
			int g = 0;
			while (i<w)
			{
				if (x[i] > 0)
				{
					goal[g] = i;
					g++;
					x[i]--;
				}
				else
				{
					i++;
				}
			}
		}


		vector < vector < char > > mv(w);

		for (int dist=1;dist<=100;dist++)
		{
			for (int i = 0; i < w; ++i)
			{
				if (i - goal[i] == dist)
				{
					for (int k = i; k > goal[i]; --k)
					{
						mv[k].push_back('/');
					}
				}
				else if (goal[i] - i == dist)
				{
					for (int k=i;k<goal[i];++k)
					{
						mv[k].push_back('\\');
					}
				}
			}
		}

		int row = 0;
		for (int i = 0; i < w; ++i)
		{
			amax(row, SZ(mv[i]));
		}
		row++;

		if (ok)
		{
			printf("Case #%d: %d\n", testcase + 1, row);

			for (int r = 0; r < row; r++)
			{
				for (int i = 0; i < w; ++i)
				{
					if (r < SZ(mv[i]))
					{
						printf("%c", mv[i][r]);
					}
					else
					{
						printf(".");
					}
				}
				printf("\n");
			}

		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", testcase + 1);
		}

	}



	return 0;
}