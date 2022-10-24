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
int mas[102];
char ans[103][103];

inline void upd_right(int s, int v) {
	int r = 0;
	FOR(i, s, v - 1) {
		ans[r++][i] = '\\';
	}
}

inline void upd_left(int s, int v) {
	int r = 0;
	FORD(i, s, v + 1) {
		ans[r++][i] = '/';
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &n);
		c = 0;
		rept(i, n) {
			scanf("%d", &mas[i]);
			c += mas[i];
		}
		
		printf("Case #%d: ", hod);
		if (!mas[0] || !mas[n - 1] || c != n) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		rept(i, n + 1) {
			rept(j, n) ans[i][j] = '.';
			ans[i][n] = 0;
		}

		a = 0;
		rept(i, n) {
			if (!mas[i]) continue;
			int l = a, r = a + mas[i] - 1;
		
			if (l < i) {
				upd_right(l, i);
			}
			if (r > i) {
				upd_left(r, i);
			}
			
			a = r + 1;
		}

		int m = 0;
		while (1) {
			bool ok = 1;
			rept(i, n) {
				if (ans[m][i] != '.') {
					ok = 0;
					break;
				}
			}
			if (ok) break;
			++m;
		}
		++m;
		printf("%d\n", m);
		rept(i, m) {
			printf("%s\n", ans[i]);
		}
	}
}
