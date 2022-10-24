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
 
 int x[15], y[15], p[15], xx[15], yy[15];
 int n, tos;
 int st[15];
 double angle[15];
 int dist[15];
 
 #define sqr(x) (x)*(x)
 
 bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
 	int A1 = y2 - y1;
 	int B1 = x1 - x2;
 	int C1 = -x1 * A1 - y1 * B1;
 
 	int A2 = y4 - y3;
 	int B2 = x3 - x4;
 	int C2 = -x3 * A2 - y3 * B2;
 
 	int p1 = (A2 * x1 + B2 * y1 + C2);
 	int p2 = (A2 * x2 + B2 * y2 + C2);
 
 	int p3 = (A1 * x3 + B1 * y3 + C1);
 	int p4 = (A1 * x4 + B1 * y4 + C1);
 
 	int lx = max(min(x1, x2), min(x3, x4));
 	int rx = min(max(x1, x2), max(x3, x4));
 
 	int ly = max(min(y1, y2), min(y3, y4));
 	int ry = min(max(y1, y2), max(y3, y4));
 
 	if (ly > ry || lx > rx) return false;
 
 	if (p1 * p2 <= 0 && p3 * p4 <= 0) {
 		// printf("%d %d  %d %d     %d %d   %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
 		// printf("%d %d %d %d\n", p1, p2, p3, p4);
 		return true;
 	}
 	return false;
 }
 
 bool cmp(int i, int j) {
 	if (fabs(angle[i] - angle[j]) > 1e-6) return angle[i] < angle[j];
 	else return dist[i] < dist[j];
 }
 
 bool rotate(int i, int j, int k) {
 	int A = y[j] - y[i];
 	int B = x[i] - x[j];
 	int C = -x[i] * A - y[i] * B;
 
 	return A * x[k] + B * y[k] + C >= 0;
 }
 
 int getcharea() {
 	tos = 0;
 	int mi = 0;
 	forn(i, n)
 		if (y[mi] > y[i] || (y[i] == y[mi] && x[i] < x[mi]))
 			mi = i;
 
 	swap(x[mi], x[0]);
 	swap(y[mi], y[0]);
 
 	st[tos++] = 0;
 
 	for (int i = 1; i < n; i++) {
 		dist[i] = sqr(x[i] - x[0]) + sqr(y[i] - y[0]);
 		angle[i] = atan2(y[i] - y[0], x[i] - x[0]);
 		p[i] = i;
 		// printf("%d %d %d %.5f\n", x[i], y[i], dist[i], angle[i]);
 	}
 
 	sort(p + 1, p + n, cmp);
 	st[tos++] = p[1];
 
 	for (int i = 2; i < n; i++) {
 		while (tos > 1 && rotate(st[tos-2], st[tos-1], p[i])) tos--;
 		st[tos++] = p[i];
 
 		// forn(i, tos) printf("%d %d - ", x[ st[i] ], y[ st[i] ]);
 		// printf("\n");
 	
 	}
 
 	// forn(i, tos) printf("%d %d - ", x[ st[i] ], y[ st[i] ]);
 	// printf("\n");
 	st[tos] = st[0];
 	int res = 0;
 	forn(i, tos) {
 		res += (y[st[i]] + y[st[i+1]]) * (x[st[i+1]] - x[st[i]]);
 	}
 	if (res < 0) res = -res;
 	return res;
 }
 
 void solve() {
 	scanf("%d", &n);
 	forn(i, n) scanf("%d %d", &x[i], &y[i]);
 	int my = y[0];
 	forn(i, n) my = min(my, y[i]);
 	forn(i, n) y[i] -= my;
 
 	forn(i, n) xx[i] = x[i], yy[i] = y[i];
 	int area = getcharea();
 	forn(i, n) x[i] = xx[i], y[i] = yy[i];
 
 	forn(i, n) p[i] = i;
 
 	do {
 		p[n] = p[0];
 		bool ok = true;
 		int cur = 0;
 		// printf("begin\n");
 		forn(i, n) {
 			int j = p[i];
 			int k = p[i+1];
 			cur += (y[k] + y[j]) * (x[k] - x[j]);
 			// printf("cur += %d * %d\n",)
 			forn(ii, i - 1) {
 				if (k != p[ii])
 					if (intersect(x[j], y[j], x[k], y[k], x[p[ii]], y[p[ii]], x[p[ii+1]], y[p[ii+1]])) {
 						ok = false;
 						break;
 					}
 			}
 			if (!ok) break;
 		}
 		if (cur < 0) cur = -cur;
 		if (ok) {
 			// forn(i, n) printf("%d ", p[i]); printf("\n");
 			// printf("cur = %d, area = %d\n", cur, area);
 			if (cur * 2 > area) {
 				forn(i, n) {
 					if (i) printf(" ");
 					printf("%d", p[i]);
 				}
 				printf("\n");
 				return;
 			}
 		}
 	} while (next_permutation(p + 1, p + n));
 
 	// forn(i, n)
 	// 	printf("%d %d\n", x[i], y[i]);
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