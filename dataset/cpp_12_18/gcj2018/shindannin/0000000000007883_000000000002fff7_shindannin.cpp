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
		scanf("%d", &T);

		for (int testcase = 0; testcase < T; ++testcase)
		{
			int N;
			cin >> N;

			double P;
			cin >> P;

			vector <int> w(N), h(N);
			vector <double> stretch(N);
			double rectPeri = 0.0;

			for (int i = 0; i < N; ++i)
			{
				cin >> w[i] >> h[i];

				if (w[i] > h[i])
				{
					swap(w[i], h[i]);
				}

				stretch[i] = 2 * (sqrt(w[i]*w[i]+h[i]*h[i]) - w[i]);
				rectPeri += 2 * w[i] + 2 * h[i];
			}

			const int S = 100500;

			vector < vector < double > > dp(N+1, vector <double>(S, NG));

			dp[0][0] = 0;

			for (int i = 0; i < N; ++i)
			{
				for (int s = 0; s < S; s++)
				{
					if (dp[i][s] != NG)
					{
						// Chosen
						amax(dp[i + 1][s + 2 * w[i]], dp[i][s] + stretch[i]);


						amax(dp[i + 1][s], dp[i][s]);
					}
				}
			}

			double best = rectPeri;

			for (int s = 0; s < S; ++s)
			{
				if (dp[N][s] != NG)
				{
					const double lower = rectPeri + s;
					const double upper = rectPeri + s + dp[N][s];


					// BEGIN CUT HERE
		//			cerr << " best=" << best << " lower=" << lower << " upper=" << upper << endl;
					// END CUT HERE






					if (INRANGE(P, lower-EPS, upper+EPS))
					{
						best = P;
						break;
					}

					const double lowerDiff = P - lower;
					const double upperDiff = P - upper;

					if (lowerDiff > 0 && lowerDiff < P - best + EPS)
					{
						best = lower;
					}

					if (upperDiff > 0 && upperDiff < P - best + EPS)
					{
						best = upper;
					}
				}
			}

			amin(best, P);

			printf("Case #%d: %.16f\n", testcase + 1, best);
		}

		return 0;
	}