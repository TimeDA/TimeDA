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

inline int calPer(int v, int n) {
	int val = (n + 1) / 2;
	int res = (100 * v) / n;
	int m = (100 * v) % n;
	return res + (m >= val);
}

int calcLeft(int n, vector<int> &a) {
	FOR(i, 0, a.size()) {
		n -= a[i];
	}
	return n;
}

int solveBiggerThan100(int n, vector<int> &a) {
	int left = calcLeft(n, a);
	vector<int> per(n + 1);
	FOR(i, 0, per.size()) {
		per[i] = calPer(i, n);
	}
	vector<int> dp(n + 1, n);
	for (int i = n - 1; i >= 0; --i) {
		if (per[i] == per[i + 1]) {
			dp[i] = dp[i + 1] + 1;
		}
		else {
			dp[i] = 1;
		}
	}
	multiset<pnt> s;
	int res = 0;
	FOR(i, 0, a.size()) {
		res += calPer(a[i], n);
		s.insert(mp(dp[a[i]], a[i]));
	}
	FOR(i, 0, left) {
		s.insert(mp(dp[0], 0));
	}
	while (1) {
		pnt v = *s.begin();
		s.erase(s.begin());
		if (v.first <= left) {
			left -= v.first;
			res++;
			int ne = v.second + v.first;
			s.insert(mp(dp[ne], ne));
		}
		else {
			break;
		}
	}
	return res;
}

int solveLessThanOrEq100(int n, vector<int> &a) {
	int left = calcLeft(n, a);
	vector<int> per(n + 1);
	FOR(i, 0, per.size()) {
		per[i] = calPer(i, n);
	}
	vector<int> dp(n + 1, 0);
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = per[i + 1] - per[i];
	}
	multiset<pnt> s;
	int res = 0;
	FOR(i, 0, a.size()) {
		res += calPer(a[i], n);
		s.insert(mp(-dp[a[i]], a[i]));
	}
	FOR(i, 0, left) {
		s.insert(mp(-dp[0], 0));
	}
	while (1) {
		pnt v = *s.begin();
		s.erase(s.begin());
		if (left >= 1) {
			left --;
			res -= v.first;
			int ne = v.second + 1;
			s.insert(mp(-dp[ne], ne));
		}
		else {
			break;
		}
	}
	return res;
}

int dp[300][300];

int brut(vector<int>&a, int p, int left, int n) {
	if ((p >= a.size()) && (left == 0)) {
		return 0;
	}
	if (dp[p][left] != -1) {
		return dp[p][left];
	}
	int res = 0;
	if (p < a.size()) {
		FOR(i, 0, left + 1) {
			res = max(res, calPer(a[p] + i, n) + brut(a, p + 1, left - i, n));
		}
	}
	else {
		FOR(i, 1, left + 1) {
			res = max(res, calPer(i, n) + brut(a, p, left - i, n));
		}
	}
	return dp[p][left] = res;
}

int solveStupid(int n, vector<int> &a) {
	MEMS(dp, -1);
	int left = calcLeft(n, a);
	return brut(a, 0, left, n);
}

void go() {
	FOR(it, 0, 100000) {
		int n = rand() % 9; n+=2;
		int l = rand() % (n - 1);
		l++;
		vector<int> a(l, 1);
		int left = n - l;
		FOR(i, 0, l) {
			if (left > 1) {
				a[i] += rand() % (left - 1);
			}
		}
		int res1 = solveStupid(n, a);
		int res2 = solveLessThanOrEq100(n, a);
		if (res1 != res2) {
			cout << "Expected: " << res1 << endl;
			cout << "Received: " << res2 << endl;
			cout << n <<" " << a.size() <<  endl;
			FOR(i, 0, a.size()) {
				cout << a[i] << " ";
			}
			break;
		}
		else {
			cout << it << endl;
		}
	}
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	//go();
	//return 0;
	int tests;
	cin >> tests;
	for (int testNumber = 1; testNumber <= tests; ++testNumber) {
		int n, l;
		scanf("%d%d", &n, &l);
		vector<int> a;
		a.resize(l);
		FOR(i, 0, l) {
			scanf("%d", &a[i]);
		}
		int res = 0;
		if (n > 250) {
			res = solveBiggerThan100(n, a);
		}
		else {
			res = solveStupid(n, a);
		}

		printf("Case #%d: %d\n", testNumber, res);
	}
	

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}