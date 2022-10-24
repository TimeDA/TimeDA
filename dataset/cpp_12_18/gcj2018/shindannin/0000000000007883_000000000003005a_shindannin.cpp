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
		int H, W, cutH, cutW;
		cin >> H >> W >> cutH >> cutW;

		cutH++;
		cutW++;

		vector <string> cake;
		for (int y = 0; y < H; ++y)
		{
			string s;
			cin >> s;
			cake.push_back(s);
		}

		int chips = 0;
		for (int y = 0; y < H; ++y)
		{
			for (int x = 0; x < W; ++x)
			{
				if (cake[y][x] == '@')
				{
					chips++;
				}

			}

		}

		bool ok = true;
		if (chips%cutH == 0 && chips%cutW == 0 && chips%(cutW*cutH) == 0)
		{
			const int numChipH = chips / cutH;
			const int numChipEach = chips / (cutW*cutH);


			vector <int> placeY;
			vector <int> id(H);

			int n = 0;
			for (int y = 0; y < H; ++y)
			{
				id[y] = SZ(placeY);

				for (int x = 0; x < W; ++x)
				{
					if (cake[y][x] == '@')
					{
						n++;
					}
				}

				if (n > numChipH)
				{
					ok = false;
					break;
				}
				else if (n == numChipH)
				{
					placeY.push_back(y);
					n = 0;
				}
			}

			if (ok)
			{
				int numCut = 0;
				vector <int> ns(SZ(placeY));
				for (int x = 0; x < W; ++x)
				{
					for (int y = 0; y < H; ++y)
					{
						if (cake[y][x] == '@')
						{
							ns[id[y]]++;
						}
					}

					if (count(ns.begin(), ns.end(), numChipEach) == SZ(placeY))
					{
						numCut++;
						fill(ns.begin(), ns.end(), 0);
					}

					for (int a : ns)
					{
						if (a > numChipEach)
						{
							ok = false;
						}
					}

					if (!ok)
					{
						break;
					}
				}
			}
		}
		else
		{
			ok = false;
		}

		printf("Case #%d: %s\n", testcase + 1, ok ? "POSSIBLE" : "IMPOSSIBLE");
	}

	return 0;
}