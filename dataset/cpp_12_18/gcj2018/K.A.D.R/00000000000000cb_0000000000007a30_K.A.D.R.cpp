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
bool used[4][205];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &a);
		int w = (a + 2) / 3;
		C(used);
		
		while (1) {
			int mn = INF, v = -1;
			const int i = 2;
			FOR(j, 2, w - 1) {
				int cnt = 0;
				FOR(di, -1, 1) {
					FOR(dj, -1, 1) {
						cnt += used[i + di][j + dj];
					}
				}
				if (cnt < mn) {
					mn = cnt;
					v = j;
				}
			}

			printf("%d %d\n", i, v);
			fflush(stdout);
			scanf("%d%d", &a, &b);
			if (a == -1 && b == -1) break;
			if (a == 0 && b == 0) break;
			used[a][b] = 1;
		}
	}
}
