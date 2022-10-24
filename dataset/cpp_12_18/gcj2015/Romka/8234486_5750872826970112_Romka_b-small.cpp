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
 
 const ld eps = 1e-14;
 
 bool solveq(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2, ld& x, ld& y) {
 	ld D = b1 * a2 - b2 * a1;
 	if (fabs(D) < eps) return false;
 	y = (c1 * a2 - c2 * a1) / D;
 	x = (c2 * b1 - c1 * b2) / D;
 	return true;
 }
 
 void solve() {
 	int n;
 	double V, C;
 	ld t1, t2;
 	scanf("%d %lf %lf", &n, &V, &C);
 	vector<double> r(n), c(n);
 	forn(i, n) scanf("%lf %lf", &r[i], &c[i]);
 	double minc = c[0], maxc = c[0];
 	forn(i, n) {
 		if (c[i] < minc) minc = c[i];
 		if (c[i] > maxc) maxc = c[i];
 	}
 
 	if (int(minc * 10000 + 0.5) > int(C * 10000 + 0.5)) {
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 
 	if (int(maxc * 10000 + 0.5) < int(C * 10000 + 0.5)) {
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 
 	if (fabs(minc - maxc) < 1e-8) {
 		r.push_back(0);
 		printf("%.8f\n", V / (r[0] + r[1]));
 		return;
 	}
 
 	if (n == 2 && solveq(r[0], r[1], V, r[0] * c[0], r[1] * c[1], V * C, t1, t2)) {
 		// fprintf(stderr, "%.5f %.5f\n", double(V), double(C));
 		// fprintf(stderr, "%.5f %.5f\n", double(r[0]), double(c[0]));
 		// fprintf(stderr, "%.5f %.5f\n", double(r[1]), double(c[1]));
 		// fprintf(stderr, "> %.8f %.8f\n", double(t1), double(t2));
 		printf("%.8f\n", double(max(t1, t2)));
 	} else {
 		assert(n == 1 || fabs(c[0] - c[1]) < eps);
 		r.push_back(0);
 		printf("%.8f\n", V / (r[0] + r[1]));
 	}
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
