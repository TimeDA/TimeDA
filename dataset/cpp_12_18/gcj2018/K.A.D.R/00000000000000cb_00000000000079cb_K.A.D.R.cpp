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
int mas[100002];

bool check(const VI& p) {
	rept(i, L(p)) {
		if (p[i] % 2 != i % 2) return 0;
	}
	return 1;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &n);
		VI p0, p1;
		rept(i, n) {
			scanf("%d", &mas[i]);
			if (i % 2 == 0) {
				p0.pb(mas[i]);
			}
			else {
				p1.pb(mas[i]);
			}
		}

		SORT(p0);
		SORT(p1);

		VI ov;
		int v = -1;
		int a = 0, b = 0;
		rept(i, n) {
			if (i % 2 == 0) {
				ov.pb(p0[a++]);
			}
			else {
				ov.pb(p1[b++]);
			}
		}

		rept(i, L(ov) - 1) {
			if (ov[i] > ov[i + 1]) {
				v = i;
				break;
			}
		}

		printf("Case #%d: ", hod);
		if (v == -1) printf("OK\n"); else
			printf("%d\n", v);
	}
}
