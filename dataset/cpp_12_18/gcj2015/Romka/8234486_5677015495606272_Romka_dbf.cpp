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
 
 // const int md = 1000000007;
 
 const int di[] = {-1, 0, 1, 0};
 const int dj[] = {0, -1, 0, 1};
 
 vector<pii> neigh[7][7];
 vector<pii> all;
 int ans, R, C;
 int x[12512];
 int L[7][7], a[7][7];
 
 bool cmp(const pii& a, const pii& b) {
 	return abs(a.first - R / 2) + abs(a.second - C / 2) <
 	       abs(b.first - R / 2) + abs(b.second - C / 2);
 }
 
 void inc_ans() {
 	forn(j, C) {
 		int v = 0;
 		forn(i, R) v = v * 10 + a[i][j];
 		x[j] = v;
 	}
 	forn(j, C)
 		x[j + C] = x[j];
 	for (int j = 1; j < C; j++) {
 		bool ls = false;
 		forn(q, C) {
 			if (x[j + q] < x[q]) {ls = true; break;}
 			if (x[j + q] > x[q]) {break;}
 		}
 		if (ls) return;
 	}
 	ans++;
 }
 
 bool test(int i, int j) {
 	if (a[i][j] == 0) return false;
 	int cnt[4] = {0, 0, 0, 0};
 	for (pii& n: neigh[i][j])
 		cnt[a[n.first][n.second]]++;
 
 	return cnt[a[i][j]] != a[i][j];
 }
 
 void go(size_t ind) {
 	// fprintf(stderr, "go %d\n", int(ind));
 	if (ind == all.size()) { inc_ans(); return; }
 
 	int i = all[ind].first;
 	int j = all[ind].second;
 	// fprintf(stderr, "its %d %d\n", i, j);
 
 	for (pii& n: neigh[i][j]) {
 		L[n.first][n.second]--;
 	}
 
 	for (int cur = 1; cur <= 3; cur++) {
 		a[i][j] = cur;
 		if (L[i][j] == 0)
 			if (test(i, j)) continue;
 		bool bad = false;
 		for (pii& n: neigh[i][j]) {
 			if (L[n.first][n.second] == 0)
 				if (test(n.first, n.second)) {
 					bad = true;
 					break;
 				}
 		}
 		if (bad) continue;
 		go(ind + 1);
 	}
 	a[i][j] = 0;
 
 	for (pii& n: neigh[i][j]) {
 		L[n.first][n.second]++;
 	}
 }
 
 void solve() {
 	scanf("%d %d", &R, &C);
 	all.clear();
 	ans = 0;
 	forn(i, R) forn(j, C) {
 		neigh[i][j].clear();
 		forn(w, 4) {
 			int ni = i + di[w];
 			int nj = j + dj[w];
 			if (ni >= 0 && ni < R) {
 				nj = (nj + C) % C;
 				neigh[i][j].emplace_back(ni, nj);
 			}
 		}
 		L[i][j] = neigh[i][j].size();
 		all.emplace_back(i, j);
 	}
 	sort(all.begin(), all.end(), cmp);
 	go(0);
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
