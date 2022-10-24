#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <bitset>
 
 using namespace std;
 
 int n, w, l;
 int mx, my, m2x, m2y;
 int lr[1100];
 pair<int, int> r[1100];
 int used[1100];
 pair<int, int> ans[1100];
 
 void solve(int x1, int y1, int x2, int y2) {
 	int ok = 0;
 	for (int i = 0; i < n; ++i) {
 		ok += used[i];
 	}
 	if (ok == n) {
 		//cerr << "Nice!" << endl;
 		return;
 	}
 	int tk = -1;
 	for (int i = 0; i < n; ++i) {
 		if (!used[i]) {
 			int cx = x1 + r[i].first;
 			int cy = y1 + r[i].first;
 			if (cx < m2x) cx = m2x;
 			if (cy < m2y) cy = m2y;
 			if (cx <= mx && cy <= my && cx + r[i].first <= x2 && cy + r[i].first <= y2) {
 				tk = i;
 				break;
 			}
 		}
 	}
 	if (tk == -1) return;
 	used[tk] = 1;
 	int cx = x1 + r[tk].first;
 	int cy = y1 + r[tk].first;
 	if (cx < m2x) cx = m2x;
 	if (cy < m2y) cy = m2y;
 	ans[r[tk].second] = make_pair(cx, cy);
 	long long val1 = (long long)(cx + r[tk].first) * (long long)(y2 - (y1 + cy + r[tk].first));
 	long long val2 = (long long)(x2 - (x1 + cx + r[tk].first)) * (long long)(y2 - y1);
 	/*if (val1 < val2)*/ {
 		solve(x1, cy + r[tk].first, cx + r[tk].first, y2);
 		solve(cx + r[tk].first, y1, x2, y2); 
 	}/* else {
 		solve(x1, y1 + cy + r[tk].first, x2, y2);
 		solve(x1 + cx + r[tk].first, y1, x2, y1 + cy + r[tk].first);
 	}*/
 }
 
 void check() {
 	for (int i = 0; i < n; ++i) {
 		int cx = ans[i].first;
 		int cy = ans[i].second;
 		if (!(0 <= cx && cx <= w && 0 <= cy && cy <= l)) {
 			cerr << "BAD" << endl; 
 		}
 	}
 
 	for (int i = 0; i < n; ++i) {
 		for (int j = i + 1; j < n; ++j) {
 			int cx = abs(ans[i].first - ans[j].first);
 			int cy = abs(ans[i].second - ans[j].second);
 			int d = lr[i] + lr[j];
 			if (cx < d && cy < d) {
 				cerr << "BAS" << endl;
 			}
 		}
 	}
 }
 
 void solve(int testcase) {
 	printf("Case #%d:", testcase);
 	cin >> n >> w >> l;
 	for (int i = 0; i < n; ++i) {
 		cin >> r[i].first;
 		r[i].second = i;
 		lr[i] = r[i].first;
 	}
 	sort(r, r + n);
 	reverse(r, r + n);
 	memset(used, 0, sizeof(used));
 	mx = r[0].first + w;
 	my = r[0].first + l;
 	m2x = r[0].first;
 	m2y = r[0].first;
 
 
 	solve(0, 0, 1050000000, 1050000000);
 	int dx = ans[r[0].second].first;
 	int dy = ans[r[0].second].second;
 	for (int i = 0; i < n; ++i) {
 		ans[i].first -= dx;
 		ans[i].second -= dy;
 	}
 	for (int i = 0; i < n; ++i) {
 		printf(" %d %d", ans[i].first, ans[i].second);
 	}
 	printf("\n");
 	check();
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	cin >> tests;
 
 	for (int t = 1; t <= tests; ++t) {
 		solve(t);
 		cerr << t << endl;
 	}
 
 	return 0;
 }