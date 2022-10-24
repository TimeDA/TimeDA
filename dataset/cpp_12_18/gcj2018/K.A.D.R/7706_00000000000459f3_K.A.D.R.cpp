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
int dp[2][502][502];

inline void upd(int &a, int b) {
	if (b > a) a = b;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	memset(dp, -1, sizeof(dp));
	int now = 1, nx = 0;
	dp[nx][0][0] = 0;

	rep(len, 32) {
		rept(r, len + 1) {
			swap(now, nx);
			memset(dp[nx], -1, sizeof(dp[nx]));
			int b = len - r;
			rept(i, 501) {
				rept(j, 501) {
					if (dp[now][i][j] == -1) continue;
					upd(dp[nx][i][j], dp[now][i][j]);

					if (i + r <= 500 && j + b <= 500) {
						upd(dp[nx][i + r][j + b], dp[now][i][j] + 1);
					}
				}
			}
		}
	}

	scanf("%d", &kolt);
	rep(hod, kolt) {
		int r, b;
		scanf("%d%d", &r, &b);
		printf("Case #%d: %d\n", hod, dp[nx][r][b]);
	}
}
