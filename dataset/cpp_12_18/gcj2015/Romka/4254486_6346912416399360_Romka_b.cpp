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
 
 int n, k, s[1010], w[1010], l[1010], r[1010];
 
 bool check(int L, int m, int moves) {
 	ll cm = 0;
 	forn(i, k) {
 		if (r[i] - (l[i] - L) > m) {
 			cm = -1;
 			break;
 		} else {
 			cm += m - (r[i] - (l[i] - L));
 		}
 	}
 	return cm >= moves;
 }
 
 void solve() {
 	scanf("%d %d", &n, &k);
 	forn(i, n - k + 1) scanf("%d", &s[i]);
 	forn(i, k) w[i] = 0;
 	for (int i = k; i < n; i++) {
 		int p = i - k;
 		w[i] = w[p] - (s[p] - s[p+1]);
 	}
 	// forn(i, n) printf("%d ", w[i]); printf("\n");
 
 	forn(i, k) {
 		l[i] = r[i] = 0;
 		for (int j = i + k; j < n; j += k) {
 			if (w[j] < l[i]) l[i] = w[j];
 			if (w[j] > r[i]) r[i] = w[j];
 		}
 		// printf("> %d %d\n", l[i], r[i]);
 	}
 
 	int best = 2e9;
 	int mn = l[0], mx = l[0];
 	forn(i, k) {
 		if (l[i] < mn) mn = l[i];
 		if (l[i] > mx) mx = l[i];
 	}
 	fprintf(stderr, "check %d-%d\n", mn, mx);
 	for (int L = mn-10001; L <= mx+10001; L++) {
 		int cs = 0;
 		// fprintf(stderr, "L = %d\n", L);
 		forn(i, k) {
 			cs += L - l[i];
 		}
 		// if (L == -1) fprintf(stderr, "cs = %d\n", cs);
 		if (cs > s[0]) continue;
 		int moves = s[0] - cs;
 		int bl = L, br = mx + 123456789;
 		while (br - bl > 1) {
 			int m = (bl + br) / 2;
 			if (check(L, m, moves)) br = m;
 			else bl = m;
 			// if (L == -1) fprintf(stderr, "%d %d\n", bl, br);
 		}
 		// if (L == -1) fprintf(stderr, ">> %d %d %d\n", L, bl, moves);
 		if (check(L, bl, moves)) br = bl;
 		if (br - L < best) {
 			best = br - L;
 		}
 	}
 
 	printf("%d\n", best);
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
