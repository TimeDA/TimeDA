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
int cnt[100002];

pair<int, pii> mas[100002];
pii ee[100002];
int na[100002], nb[100002];

unordered_map<int, VI> posa, posb;
unordered_map<ll, VI> posboth;

inline ll gh(ll a, ll b) {
	a += 2 * INF;
	b += 2 * INF;

	return ((ll)a << 32) + b;
}

inline bool check(int l, int r) {
	// Left a
	int A = ee[l].x;

	int fir = na[l];
	if (fir > r) return 1;
	int nv = ee[fir].y;

	const auto& A1 = posa[A];
	const auto& B1 = posb[nv];
	const auto& C1 = posboth[gh(A, nv)];

	int cnt = upper_bound(A1.begin(), A1.end(), r) - lower_bound(A1.begin(), A1.end(), l);
	cnt += upper_bound(B1.begin(), B1.end(), r) - lower_bound(B1.begin(), B1.end(), l);
	cnt -= upper_bound(C1.begin(), C1.end(), r) - lower_bound(C1.begin(), C1.end(), l);

	if (cnt == r - l + 1) return 1;

	// Left b
	int B = ee[l].y;
	fir = nb[l];
	if (fir > r) return 1;
	nv = ee[fir].x;
	
	const auto& A2 = posa[nv];
	const auto& B2 = posb[B];
	const auto& C2 = posboth[gh(nv, B)];

	cnt = upper_bound(A2.begin(), A2.end(), r) - lower_bound(A2.begin(), A2.end(), l);
	cnt += upper_bound(B2.begin(), B2.end(), r) - lower_bound(B2.begin(), B2.end(), l);
	cnt -= upper_bound(C2.begin(), C2.end(), r) - lower_bound(C2.begin(), C2.end(), l);

	return (cnt == r - l + 1);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d", &n);
		
		posa.clear(); posb.clear(); posboth.clear();
		rept(i, n) {
			scanf("%d%d%d", &mas[i].x, &mas[i].y.x, &mas[i].y.y);
			ee[i].x = mas[i].x + mas[i].y.x;
			ee[i].y = mas[i].x - mas[i].y.y;

			posa[ee[i].x].pb(i);
			posb[ee[i].y].pb(i);

			ll h = gh(ee[i].x, ee[i].y);
			posboth[h].pb(i);
		}
		rept(i, n + 1) cnt[i] = 0;

		na[n - 1] = INF;
		nb[n - 1] = INF;
		FORD(i, n - 2, 0) {
			if (ee[i].x != ee[i + 1].x) {
				na[i] = i + 1; 
			}
			else {
				na[i] = na[i + 1];
			}

			if (ee[i].y != ee[i + 1].y) {
				nb[i] = i + 1;
			}
			else {
				nb[i] = nb[i + 1];
			}
		}
		
		int e = 0;
		rept(i, n) {
			if (e <= i) e = i + 1;

			while (e < n) {
				if (!check(i, e)) break;
				++e;
			}

			++cnt[e - i];
		}

		e = n;
		while (!cnt[e]) --e;
		printf("Case #%d: %d %d\n", hod, e, cnt[e]);
	}
}
