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
int mas[102][102];
VI sm[102];
int lp[102], q[102];
bool used[102];

bool dfs(int v) {
	if (used[v]) return 0;
	used[v] = 1;
	rept(i, L(sm[v])) {
		if (q[sm[v][i]] == -1 || dfs(q[sm[v][i]])) {
			lp[v] = sm[v][i];
			q[sm[v][i]] = v;
			return 1;
		}
	}
	return 0;
}
int calc(int num) {
	rept(i, n) {
		sm[i].clear();
		rept(j, n) {
			if (mas[i][j] == num) sm[i].pb(j);
		}
	}

	memset(lp, -1, n * sizeof(int));
	memset(q, -1, n * sizeof(int));

	int ans = 0, old = -1;
	while (ans != old) {
		old = ans;
		memset(used, 0, n);
		rept(i, n) if (lp[i] == -1 && dfs(i)) ++ans;
	}
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &n);
		rept(i, n) {
			rept(j, n) {
				scanf("%d", &mas[i][j]);
			}
		}

		int sum = 0;
		FOR(i, -n, n) {
			if (!i) continue;
			sum += calc(i);
		}

		printf("Case #%d: %d\n", hod, n * n - sum);
	}
}
