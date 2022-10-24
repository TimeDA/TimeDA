#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 const int inf = int(2e9);
 
 const int maxn = 4010;
 const int maxm = 8010;
 
 int n, m, k;
 vector<int> g[maxn], gb[maxn];
 int x[maxm], y[maxm], a[maxm], b[maxm];
 int d0[maxn], d1[maxn];
 int path[maxm];
 bool inp[maxm];
 bool u[maxn], u2[maxn];
 
 void dijkstra(int S, int* d, bool edges, vector<int>* g) {
 	forn(i, n) u[i] = false, d[i] = inf;
 	d[S] = 0;
 
 	forn(i, n) {
 		int mi = -1;
 		forn(j, n)
 			if (!u[j])
 				if (mi == -1 || d[j] < d[mi])
 					mi = j;
 		u[mi] = 1;
 		forn(j, g[mi].size()) {
 			int e = g[mi][j];
 			int v = edges ? x[e] : y[e];
 			int w = inp[e] ? a[e] : b[e];
 			if (d[v] > d[mi] + w) {
 				d[v] = d[mi] + w;
 			}
 		}
 	}
 }
 
 bool check() {
 	dijkstra(0, d0, false, g);
 	int sp = 0;
 	forn(i, m) if (inp[i]) sp += a[i];
 	if (d0[1] == sp) return true;
 	return false;
 }
 
 bool go(int v) {
 	if (v == 1) return check();
 	else {
 		forn(j, g[v].size()) {
 			int e = g[v][j];
 			int u = y[e];
 			if (!u2[u]) {
 				inp[e] = true;
 				u2[u] = true;
 				bool z = go(u);
 				u2[u] = false;
 				inp[e] = false;
 				if (z) return 1;
 			}
 		}
 		return 0;
 	}
 }
 
 void solve() {
 	scanf("%d %d %d", &n, &m, &k);
 	forn(i, n) g[i].clear(), gb[i].clear();
 	forn(i, m) {
 		scanf("%d %d %d %d", &x[i], &y[i], &a[i], &b[i]);
 		x[i]--, y[i]--;
 		g[ x[i] ].pb(i);
 		gb[ y[i] ].pb(i);
 		// dst[ x[i] ].pb(y[i]);
 		// g[ y[i] ].pb(i);
 		// dst[ y[i] ].pb(x[i]);
 		inp[i] = 0;
 	}
 	// memset(inp, 0, sizeof(inp));
 	forn(i, k) {
 		scanf("%d", &path[i]); path[i]--;
 		inp[ path[i] ] = 1;
 	}
 
 	dijkstra(0, d0, false, g);
 	dijkstra(1, d1, true, gb);
 
 	// forn(i, n) printf("%d ", d0[i]); printf("\n");
 	// forn(i, n) printf("%d ", d1[i]); printf("\n");
 
 	int sp = 0;
 	forn(i, k) sp += a[ path[i] ];
 	if (d0[1] == sp) printf("Looks Good To Me\n");
 	else {
 		sp = 0;
 		forn(i, n) u2[i] = 0;
 		forn(i, m) inp[i] = 0;
 		u2[0] = 1;
 		forn(i, k) {
 			sp += a[ path[i] ];
 			inp[ path[i] ] = 1;
 			int v = y[ path[i] ];
 			u2[v] = 1;
 			if (!go(v)) {
 				printf("%d\n", path[i] + 1);
 				return;
 			}
 		}
 	}
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		solve();
 		fprintf(stderr, "Case %d done.\n", q);
 	}
 	return 0;
 }