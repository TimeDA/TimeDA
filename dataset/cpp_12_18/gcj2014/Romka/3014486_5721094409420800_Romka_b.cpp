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
 
 int n, a[1010];
 
 void solve() {
 	scanf("%d", &n);
 	forn(i, n) scanf("%d", &a[i]);
 	int L = 0, R = n - 1;
 	int ans = 0;
 	while (L <= R) {
 		int mi = L;
 		for (int j = L; j <= R; j++)
 			if (a[j] < a[mi]) mi = j;
 
 		if (mi - L < R - mi) {
 			ans += mi - L;
 			for (int j = mi; j > L; j--) a[j] = a[j-1];
 			L++;
 		} else {
 			ans += R - mi;
 			for (int j = mi; j < R; j++) a[j] = a[j+1];
 			R--;
 		}
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
