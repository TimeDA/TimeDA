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

int a, b, c, d, n, m, k, kolt, l;

inline int gs(int a, int b) {
	a = 200 * a / b;
	return (a + 1) / 2;
}
inline int delta(int a, int b) {
	int cur = gs(a, b);

	int nx = gs(a + 1, b);

	return nx - cur;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d%d", &n, &l);
		vector<int> cc(n);
		int s = 0;
		rept(i, l) {
			scanf("%d", &cc[i]);
			s += cc[i];
		}

		priority_queue<pair<int, pii>, vector<pair<int, pii> > > q;
		rept(i, L(cc)) {
			q.push(mp(delta(cc[i], n), mp(-gs(cc[i], n), i)));
		}

		rept(iter, n - s) {
			auto t = q.top();
			q.pop();
			++cc[t.y.y];
			q.push(mp(delta(cc[t.y.y], n), mp(-gs(cc[t.y.y], n), t.y.y)));
		}

		int ans = 0;
		rept(i, L(cc)) ans += gs(cc[i], n);

		printf("Case #%d: %d\n", hod, ans);
	}
}
