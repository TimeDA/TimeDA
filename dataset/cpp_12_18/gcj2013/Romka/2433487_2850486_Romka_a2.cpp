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
 
 ll B;
 int n;
 ll x[40];
 ld ans;
 
 ld f(ll c) {
 	// fprintf(stderr, "c = %lld\n", c);
 	ld res = -1e18;
 	for (int cmin = 1; cmin <= 37; cmin++) {
 		ll cur = B;
 		ll tt = 0;
 		bool ok = true;
 		forn(i, cmin)
 			if (x[i] >= c) {
 				ok = false;
 				break;
 			}
 		if (!ok) break;
 
 		for (int i = cmin; i < 37; i++) {
 			if (x[i] < c) {
 				cur -= c - x[i];
 				tt += c - x[i];
 			}
 		}
 		if (cur < 0) continue;
 
 		// fprintf(stderr, "cmin = %d, c = %lld: ok, tt = %lld\n", cmin, c, tt);
 
 		ll to_put = cmin * (c - 1);
 		ll al = 0;
 		forn(i, cmin) al += x[i];
 		
 		ld z = -1;
 		if (to_put - al > cur) {
 			ll h = (cur + al) / cmin;
 			if (x[cmin - 1] > h) continue;
 			ll in = h * cmin - al;
 			// fprintf(stderr, "h = %lld, in = %lld\n", h, in);
 			z = ld(in) * 36.0 / cmin - (in + tt);
 		} else {
 			// fprintf(stderr, "to_put - al = %lld\n", to_put - al);
 			z = ld(to_put - al) * 36.0 / cmin - (to_put - al + tt);
 		}
 		// cerr << "cmin = " << cmin << ", z = " << z << endl;
 		res = max(res, z);
 		/*
 		if (left * c <= cur) {
 			cerr << "here: " << tt << endl;
 			// cerr << left << endl;
 			int cb = 0;
 			forn(i, n) cb += x[i] <= c;
 			cerr << cb << endl;
 			res = max(res, ld(left * c + tt) * 36.0 / (left + cb) - (left * c + tt));
 			cerr << res << endl;
 		}
 		*/
 	}
 	// cerr << c << ":" << res << endl;
 	if (res > ans) ans = res;
 	return res;
 }
 
 void solve() {
 	cin >> B >> n;
 	forn(i, n) cin >> x[i];
 	for (int i = n; i < 37; i++) x[i] = 0;
 	n = 37;
 	sort(x, x+n);
 	// f(300000);
 	// cerr << ans << endl;
 	// return;
 	ans = 0;
 	ll l = x[0], r = x[0] + B;
 	while (r - l > 3) {
 		ll m1 = l + (r - l) / 3;
 		ll m2 = r - (r - l) / 3;
 		// fprintf(stderr, "%lld %lld - %lld %lld\n", l, r, m1, m2);
 		
 		if (f(m1) >= f(m2)) r = m2;
 		else l = m1;
 	}
 
 	for (ll q = l; q <= r; q++) {
 		f(q);
 	}
 
 	printf("%.8f\n", double(ans));
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