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
 	int n, m;
 	scanf("%d %d", &n, &m);
 	multiset<int> ss;
 	int x;
 	forn(i, n) {
 		scanf("%d", &x);
 		ss.insert(x);
 	}
 	int ans = 0;
 	while (!ss.empty()) {
 		ans++;
 		x = *ss.rbegin();
 		ss.erase(--ss.end());
 		if (ss.empty()) break;
 		int y = m - x;
 		multiset<int>::iterator it = ss.lower_bound(y);
 		if (it == ss.end() || *it > y)
 			if (it != ss.begin()) it--;
 		if (it != ss.end() && x + *it <= m)
 			ss.erase(it);
 	}
 	printf("%d\n", ans);
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
