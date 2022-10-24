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
 
 int k, n;
 vector<int> g[210];
 int cnt[210], u[210], open[210], it;
 int f[1 << 20];
 
 void add(int i, int d) {
 	if (u[i] != it) { u[i] = it; cnt[i] = 0; }
 	cnt[i] += d;
 }
 
 bool is_key(int i) {
 	if (u[i] != it) return false;
 	return cnt[i] > 0;
 }
 
 void solve() {
 	scanf("%d %d", &k, &n);
 	int x, z;
 	vector<int> init;
 	forn(i, k) {
 		scanf("%d", &x);
 		init.pb(x);
 	}
 	forn(i, n) {
 		scanf("%d %d", &open[i], &z);
 		g[i].clear();
 		forn(q, z) {
 			scanf("%d", &x);
 			g[i].pb(x);
 		}
 	}
 
 	f[0] = 0;
 	forn(i, 1 << n) {
 		it++;
 		forn(j, init.size()) add(init[j], +1);
 		forn(j, n)
 			if ((i & (1 << j)) == 0) {
 				add(open[j], -1);
 				forn(q, g[j].size())
 					add(g[j][q], +1);
 			}
 
 		f[i] = i == 0 ? 0 : -1;
 		forn(j, n)
 			if (i & (1 << j))
 				if (is_key(open[j]) && f[i ^ (1 << j)] >= 0) {
 					f[i] = j;
 					break;
 				}
 	}
 
 	int all = (1 << n) - 1;
 	if (f[all] == -1) printf("IMPOSSIBLE\n");
 	else {
 		vector<int> ans;
 		while (all > 0) {
 			ans.pb(f[all] + 1);
 			all ^= 1 << f[all];
 		}
 
 		forn(i, n) {
 			if (i) printf(" ");
 			printf("%d", ans[i]);
 		}
 		printf("\n");
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