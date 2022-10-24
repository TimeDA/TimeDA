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
 	double C, F, X;
 	scanf("%lf %lf %lf", &C, &F, &X);
 	double cur = 2, ans = 0;
 	while (true) {
 		double left_now = X / cur;
 		double maybe_left = X / (cur + F) + C / cur;
 		if (maybe_left <= left_now) {
 			ans += C / cur;
 			cur += F;
 		} else break;
 	}
 	printf("%.7f\n", ans + X / cur);
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
