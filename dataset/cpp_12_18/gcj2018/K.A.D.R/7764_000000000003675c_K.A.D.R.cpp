#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#define GETS gets_s
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <stdio.h>
#define GETS gets
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k, kolt;
pii rr[102];
int beg[102], cur[102];

int used[102];
bool dfs(int v, int w) {
	if (cur[v] >= w) {
		cur[v] -= w;
		return 1;
	}
	
	if (used[v] > 102) return 0;
	++used[v];

	w -= cur[v];
	cur[v] = 0;

	
	if (rr[v].x == v || rr[v].y == v) return 0;
	if (!dfs(rr[v].x, w)) return 0;
	if (!dfs(rr[v].y, w)) return 0;
	return 1;
}
bool check(int xx) {
	C(used);
	rept(i, m) cur[i] = beg[i];
	return dfs(0, xx);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &m);
		rept(i, m) {
			scanf("%d%d", &rr[i].x, &rr[i].y);
			--rr[i].x; --rr[i].y;
		}
		rept(i, m) {
			scanf("%d", &beg[i]);
		}

		int l = 0, r = 2 * INF + 2;
		while (r - l > 1) {
			int xx = ((ll)l + (ll)r) / 2;
			if (check(xx)) l = xx; else
				r = xx;
		}
		int ans = l;
		printf("Case #%d: %d\n", hod, ans);
	}
}
