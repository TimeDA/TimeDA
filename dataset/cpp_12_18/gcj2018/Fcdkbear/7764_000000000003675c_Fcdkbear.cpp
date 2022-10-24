#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <fstream>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

vector<int> p;
int brut1(vector<pnt> &R, vector<int> &g, int pos, int curRes, int sum) {
	if (sum <= curRes) {
		return 0;
	}
	if (pos == p.size()) {
		return g[0];
	}
	int res = brut1(R, g, pos + 1, curRes, sum);
	int v1 = R[p[pos]].first;
	int v2 = R[p[pos]].second;
	if ((g[v1] > 0) && (g[v2] > 0)) {
		g[v1]--;
		g[v2]--;
		g[p[pos]]++;
		res = max(res, brut1(R, g, pos, curRes, sum - 1));
		g[v1]++;
		g[v2]++;
		g[p[pos]]--;
	}
	return res;
}

int brut(vector<pnt> &R, vector<int> &g) {
	int res = g[0];
	FOR(i, 0, R.size()) {
		int v1 = R[i].first;
		int v2 = R[i].second;
		if ((g[v1] > 0) && (g[v2] > 0)) {
			g[v1]--;
			g[v2]--;
			g[i]++;
			res = max(res, brut(R, g));
			g[v1]++;
			g[v2]++;
			g[i]--;
		}
	}
	return res;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	int tests;
	cin >> tests;
	for (int testNumber = 1; testNumber <= tests; ++testNumber) {
		int n;
		cin >> n;
		vector<pnt> R(n);
		FOR(i, 0, n) {
			cin >> R[i].first >> R[i].second;
			R[i].first--;
			R[i].second--;
		}
		vector<int> g(n);
		int sum = 0;
		FOR(i, 0, n) {
			cin >> g[i];
			sum += g[i];
		}
		p.clear();
		FOR(i, 0, n) {
			p.push_back(i);
		}
		double b = clock();
		int res = 0;
		double al = 10.0 / testNumber;
		al -= 0.03;
		do {
			if ((p[p.size() - 1] != 0) && (((p[p.size() - 2] != R[0].first)) || ((p[p.size() - 2] != R[0].second)))) {
				continue;
			}
			res = max(res, brut1(R, g, 0, res, sum));
			double e = clock();
			if (e - b >= al * CLOCKS_PER_SEC) {
				break;
			}
		} while (next_permutation(p.begin(), p.end()));
		printf("Case #%d: %d\n", testNumber, res);
	}
	

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}