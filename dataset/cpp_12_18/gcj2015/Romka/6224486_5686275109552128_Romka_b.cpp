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
 
 void solve() {
 	int x, n;
 	scanf("%d", &n);
 	map<int, int> mm;
 	forn(i, n) { scanf("%d", &x); mm[-x]++; }
 	int ans = 1e9;
 	int elapsed = 0;
 	while (true) {
 		int cur = -mm.begin()->first;
 		if (elapsed + cur < ans) ans = elapsed + cur;
 		if (cur == 1) break;
 		int cnt = mm.begin()->second;
 		mm.erase(mm.begin());
 		elapsed += cnt;
 		mm[-((cur + 1) / 2)] += cnt;
 		mm[-(cur / 2)] += cnt;
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
