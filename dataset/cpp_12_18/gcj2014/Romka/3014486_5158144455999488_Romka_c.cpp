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
 
 const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
 const int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
 const int maxn = 110 * 510 * 2;
 
 int w, h, k, a[510][510];
 vector<pii> g[maxn];
 int f[maxn * 10], c[maxn * 10];
 int p[maxn], pe[maxn], u[maxn], it, q[maxn], qb, qf, xa[1010], ya[1010], xb[1010], yb[1010], T, S, V, e;
 
 void edge(int v1, int v2) {
 	// printf("edge %d -> %d\n", v1, v2);
 	f[e] = 1;
 	c[e] = 0;
 	g[v1].pb(pii(v2, e++));
 	f[e] = 0;
 	c[e] = 0;
 	g[v2].pb(pii(v1, e++));
 }
 
 bool bfs() {
 	it++;
 	qb = qf = 0;
 	q[qf++] = S;
 	u[S] = it;
 	p[S] = -1;
 
 	// printf("bfs\n");
 	while (qb < qf) {
 		int x = q[qb++];
 		// printf("outq %d\n", x);
 		forn(i, g[x].size()) {
 			int e = g[x][i].second;
 			int y = g[x][i].first;
 
 			if (c[e] < f[e] && u[y] != it) {
 				u[y] = it;
 				p[y] = x;
 				pe[y] = e;
 				q[qf++] = y;
 			}
 		}
 	}
 
 	return u[T] == it;
 }
 
 void push_flow() {
 	int i = T;
 	while (i != S) {
 		c[ pe[i] ]++;
 		c[ pe[i]^ 1]--;
 		i = p[i];
 	}
 }
 
 void solve() {
 	scanf("%d %d %d", &w, &h, &k);
 	forn(j, w) forn(i, h) a[i][j] = 0;
 	forn(q, k) {
 		scanf("%d %d %d %d", &xa[q], &ya[q], &xb[q], &yb[q]);
 		for (int y = ya[q]; y <= yb[q]; y++)
 			for (int x = xa[q]; x <= xb[q]; x++)
 				a[y][x] = 1;
 	}
 
 	S = h * w * 2;
 	T = S + 1;
 	V = T + 1;
 	e = 0;
 
 	forn(i, V) g[i].clear();
 
 	forn(i, h) forn(j, w)
 		if (a[i][j] != 1) {
 			edge(i * w * 2 + j * 2 + 0, i * w * 2 + j * 2 + 1);
 			forn(q, 4) {
 				int ni = i + di[q];
 				int nj = j + dj[q];
 				if (ni >= 0 && ni < h && nj >= 0 & nj < w)
 					if (a[ni][nj] != 1)
 						edge(i * w * 2 + j * 2 + 1, ni * w * 2 + nj * 2 + 0);
 			}
 		}
 
 	forn(j, w) {
 		if (a[0][j] != 1)
 			edge(S, j * 2);
 		if (a[h-1][j] != 1)
 			edge((h-1) * w * 2 + j * 2 + 1, T);
 	}
 
 	int ans = 0;
 	while (bfs()) {
 		push_flow();
 		ans++;
 	}
 	printf("%d\n", ans);
 
 	// if (ans == 0) {
 	// 	printf("%d %d %d\n", w, h, k);
 	// 	forn(q, k) printf("%d %d %d %d\n", xa[q], ya[q], xb[q], yb[q]);
 	// 	printf("=====\n");
 	// }
 
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
