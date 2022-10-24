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


class BipartiteMatching
{
public:
	BipartiteMatching(int v) : V(v)
	{
		init();
	}

	void init()
	{
		G.clear();
		G.resize(V);
		match.clear();
		match.resize(V);
		used.clear();
		used.resize(V);
	}

	void add_edge(int u, int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int run()
	{
		int res = 0;
		fill(match.begin(), match.end(), -1);
		for (int v = 0; v<V; v++)
		{
			if (match[v]<0)
			{
				fill(used.begin(), used.end(), false);
				if (dfs(v))
				{
					res++;
				}
			}
		}

		return res;
	}

private:
	const int V;
	vector < vector <int> > G;
	vector <int> match;
	vector <bool> used;


	bool dfs(int v)
	{
		used[v] = true;
		for (int i = 0; i<SZ(G[v]); i++)
		{
			int u = G[v][i];
			int w = match[u];
			if (w<0 || !used[w] && dfs(w))
			{
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
};

int main()
{

	int T;
	scanf("%d ", &T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int N;
		scanf("%d ", &N);


		vector < vector < int > > vvi(N, vector <int>(N, 0));

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				scanf("%d ", &vvi[y][x]);
			}
		}

		int sum = 0;

		for (int c = -N; c <= N; ++c)
		{
			BipartiteMatching bm(2*N);


			int num_edge = 0;
			for (int y = 0; y < N; ++y)
			{
				for (int x = 0; x < N; ++x)
				{
					if (vvi[y][x] == c)
					{
						bm.add_edge(y,N+x);
						num_edge++;
					}
				}
			}

			int pr = num_edge  - bm.run();
			sum += pr;
		}

		printf("Case #%d: %d\n", testcase + 1, sum);
	}



	return 0;
}