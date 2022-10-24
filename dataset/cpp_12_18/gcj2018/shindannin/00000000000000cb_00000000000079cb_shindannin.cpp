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
		int N;
		vector <int> odd, even;
		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			int tmp;
			cin >> tmp;
			if (i % 2 == 0)
			{
				even.push_back(tmp);
			}
			else
			{
				odd.push_back(tmp);
			}
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		vector <int> sorted;
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
			{
				sorted.push_back(even[i / 2]);
			}
			else
			{
				sorted.push_back(odd[i / 2]);
			}
		}

		int wrong = NG;
		for (int i = 0; i < N-1; ++i)
		{
			if (sorted[i] > sorted[i + 1])
			{
				wrong = i;
				break;
			}

		}

		if (wrong == NG)
		{
			printf("Case #%d: OK\n", testcase + 1);
		}
		else
		{
			printf("Case #%d: %d\n", testcase + 1, wrong);
		}
	}



	return 0;
}