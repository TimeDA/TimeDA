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
 
 int T, n, m;
 bool u[10][10];
 int a[10][10];
 int cnt[10];
 
 void go(int i, int j) {
 	u[i][j] = true;
 	if (a[i][j] == 2) return;
 	forn(q, 8) {
 		int ni = i + di[q];
 		int nj = j + dj[q];
 		if (ni >= 0 && ni < n && nj >= 0 && nj < m)
 			if (a[ni][nj] != 1 && !u[ni][nj]) go(ni, nj);
 	}
 }
 
 bool check() {
 	forn(i, n) forn(j, m) a[i][j] = 0;
 	forn(i, n) forn(j, cnt[i]) a[i][j] = 1;
 	forn(i, n) forn(j, m) {
 		u[i][j] = false;
 		if (a[i][j] != 1)
 			forn(q, 8) {
 				int ni = i + di[q];
 				int nj = j + dj[q];
 				if (ni >= 0 && ni < n && nj >= 0 && nj < m)
 					if (a[ni][nj] == 1) a[i][j] = 2;
 			}
 	}
 
 	// forn(i, n) printf("%d ", cnt[i]); printf("\n");
 	// forn(i, n) {
 	// 	forn(j, m) printf("%d", a[i][j]);
 	// 	printf("\n");
 	// }
 
 	go(0, m - 1);
 
 	forn(i, n) forn(j, m)
 		if (a[i][j] != 1 && !u[i][j]) return false;
 
 	return true;
 }
 
 bool rec(int i, int left) {
 	if (i == n) {
 		if (left == 0 && check()) return true;
 		return false;
 	} else {
 		forn(j, min(left + 1, m + 1)) {
 			cnt[i] = j;
 			if ((i > 0 || j != m) && rec(i + 1, left - j)) return true;
 		}
 		return false;
 	}
 }
 
 void solve() {
 	scanf("%d %d %d", &n, &m, &T);
 	if (rec(0, T)) {
 		forn(i, n) {
 			forn(j, m) {
 				if (a[i][j] == 1) printf("*");
 				else if (i == 0 && j == m - 1) printf("c");
 				     else printf(".");
 			}
 			printf("\n");
 		}
 	} else printf("Impossible\n");
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d:\n", q);
 		solve();
 		fprintf(stderr, "Case %d done.\n", q);
 	}
 	return 0;
 }
