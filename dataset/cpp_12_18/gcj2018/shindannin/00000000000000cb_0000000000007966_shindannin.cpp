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
		int d;
		string s;
		cin >> d >> s;

		const int N = SZ(s);

		int turn = 0;
		while (1)
		{
			int total = 0;
			int damage = 1;
			for (int i = 0; i < N; ++i)
			{
				if (s[i] == 'C')
				{
					damage *= 2;
				}
				else
				{
					total += damage;
				}
			}

			if (total <= d)
			{
				break;
			}

			bool swapped = false;
			for (int i = N - 2; i >= 0; --i)
			{
				if (s[i] == 'C' && s[i + 1] == 'S')
				{
					swap(s[i], s[i + 1]);
					swapped = true;
					break;
				}
			}

			if (!swapped)
			{
				turn = NG;
				break;
			}

			turn++;
		}

		if (turn == NG)
		{
			printf("Case #%d: IMPOSSIBLE\n", testcase + 1);
		}
		else
		{
			printf("Case #%d: %d\n", testcase + 1, turn);
		}

	}



	return 0;
}