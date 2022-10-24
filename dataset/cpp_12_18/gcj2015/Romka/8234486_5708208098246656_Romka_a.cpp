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
 
 const int di[] = {-1, 0, 1, 0};
 const int dj[] = {0, -1, 0, 1};
 
 int n, m;
 char s[110][110];
 
 int getw(char c) {
 	if (c == '^') return 0;
 	if (c == '<') return 1;
 	if (c == 'v') return 2;
 	if (c == '>') return 3;
 	return -1;
 }
 
 bool isarrow(int i, int j, int w) {
 	int ni = i + di[w], nj = j + dj[w];
 	while (ni >= 0 && ni < n && nj >= 0 && nj < m) {
 		if (s[ni][nj] != '.') return true;
 		ni += di[w], nj += dj[w];
 	}
 	return false;
 }
 
 int solve() {
 	scanf("%d %d", &n, &m);
 	forn(i, n) scanf("%s", s[i]);
 	int res = 0;
 	forn(i, n) forn(j, m) {
 		if (s[i][j] != '.') {
 			int w = getw(s[i][j]);
 			if (isarrow(i, j, w)) continue;
 			bool ok = false;
 			forn(q, 4)
 				if (isarrow(i, j, q)) {
 					ok = true;
 					res++;
 					break;
 				}
 			if (!ok) return -1;
 		}
 	}
 
 	return res;
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		int z = solve();
 		if (z == -1) printf("IMPOSSIBLE\n");
 		else printf("%d\n", z);
 	}
 	return 0;
 }
