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
 
 struct Gen {
 	ll S;
 	int A, C, R;
 
 	Gen() {
 		scanf("%lld %d %d %d\n", &S, &A, &C, &R);
 	}
 
 	int get() {
 		int res = S;
 		S = (S * A + C) % R;
 		return res;
 	}
 };
 
 int n, D, s[1000010], m[1000010], bal[1000010];
 vector<int> g[1000010];
 
 void dfs(int i, int L, int R) {
 	// printf("\ndfs %d %d %d ", i, L, R);
 	bal[max(L, 0)]++;
 	bal[R+1]--;
 
 	forn(j, g[i].size()) {
 		int y = g[i][j];
 		int nr = min(R, s[y]);
 		int nl = max(L, s[y] - D);
 		if (nl <= nr) dfs(y, nl, nr);
 	}
 }
 
 void solve() {
 	scanf("%d %d", &n, &D);
 	Gen sg;
 	Gen mg;
 	forn(i, n) {
 		g[i].clear();
 		s[i] = sg.get();
 		m[i] = mg.get();
 		if (i) {
 			m[i] %= i;
 			g[m[i]].pb(i);
 		}
 	}
 	memset(bal, 0, sizeof(bal));
 	dfs(0, s[0] - D, s[0]);
 
 	int cur = 0;
 	int ans = 0;
 	forn(i, 1000002) {
 		cur += bal[i];
 		if (cur > ans) ans = cur;
 	}
 	printf("%d\n", ans);
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		solve();
 	}
 	return 0;
 }
