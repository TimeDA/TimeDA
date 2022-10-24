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
 
 int n, k;
 string s[1010];
 int ans;
 int kt, trie[1010 * 10][26];
 int b[1010];
 int best;
 int root[1010];
 
 int alloc() {
 	forn(j, 26) trie[kt][j] = -1;
 	return kt++;
 }
 
 void add(int cur, string& s, int i) {
 	if (i == (int)s.size()) return;
 	int j = s[i] - 'A';
 	if (trie[cur][j] == -1) trie[cur][j] = alloc();
 	add(trie[cur][j], s, i + 1);
 }
 
 void check() {
 	kt = 0;
 	forn(i, k) root[i] = alloc();
 	forn(i, n)
 		add(root[b[i]], s[i], 0);
 
 	forn(i, k) {
 		bool ok = false;
 		forn(j, 26) ok |= trie[root[i]][j] != -1;
 		if (!ok) kt--;
 	}
 
 	if (kt > best) {
 		best = kt;
 		ans = 0;
 	}
 
 	if (kt == best) ans++;
 }
 
 void go(int i) {
 	if (i == n) check();
 	else
 		for (b[i] = 0; b[i] < k; b[i]++)
 			go(i + 1);
 }
 
 void solve() {
 	scanf("%d %d", &n, &k);
 	forn(i, n) cin >> s[i];
 
 	ans = 0;
 	best = 0;
 	go(0);
 
 	printf("%d %d\n", best, ans);
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
