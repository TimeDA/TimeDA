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
 #include <unordered_map>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 int P;
 ll s[10010], c[10010], cc[10010];
 
 void solve() {
 	scanf("%d", &P);
 	forn(i, P) scanf("%lld", &s[i]);
 	ll total = 0;
 	forn(i, P) {
 		scanf("%lld", &c[i]);
 		total += c[i];
 	}
 
 	vector<ll> ans;
 	while (total > 1) {
 		ll cur = 1e15;
 		forn(i, P) {
 			ll X = s[i] - s[0];
 			int j1 = 0, j2 = 0;
 			bool ok = true, is0A = false, is0B = false;
 			forn(j, P) cc[j] = c[j];
 			while (j1 < P) {
 				while (j2 < P && s[j2] < s[j1] + X) j2++;
 				if (j2 == P || s[j2] != s[j1] + X || cc[j1] > cc[j2]) {
 					// printf("%lld failed on %d, %d\n", X, j1, j2);
 					ok = false;
 					break;
 				}
 				if (j1 == j2) {
 					if (cc[j2] % 2 != 0) {
 						ok = false;
 						break;
 					}
 					if (s[j1] == 0) {
 						is0A = is0B = true;
 					}
 					j1++;
 					j2++;
 				} else {
 					cc[j2] -= cc[j1];
 					cc[j1] = 0;
 					is0A |= s[j1] == 0;
 					is0B |= s[j2] == 0;
 				}
 				while (j1 < P && cc[j1] == 0) ++j1;
 			}
 			// printf("%lld - %d\n", X, ok);
 			if (ok) {
 				if (is0A) cur = min(cur, X);
 				if (is0B) cur = min(cur, -X);
 			}
 		}
 		// printf("found %lld\n", cur);
 
 		ans.push_back(cur);
 		int j1 = 0, j2 = 0;
 		unordered_map<ll, ll> nc;
 		ll aX = abs(cur);
 		while (j1 < P) {
 			while (j2 < P && s[j2] < s[j1] + aX) j2++;
 			if (j1 == j2) {
 				nc[s[j1]] += c[j1] / 2;
 				j1++;
 			} else {
 				if (cur < 0) nc[s[j2]] += c[j1];
 				else nc[s[j1]] += c[j1];
 				c[j2] -= c[j1];
 				c[j1] = 0;
 			}
 			while (j1 < P && c[j1] == 0) ++j1;
 		}
 
 		P = 0;
 		total = 0;
 		vector<pair<ll, ll>> tmp(nc.begin(), nc.end());
 		sort(tmp.begin(), tmp.end());
 		for (const auto& x : tmp) {
 			s[P] = x.first;
 			c[P] = x.second;
 			total += x.second;
 			P++;
 		}
 		// printf("after iteration: total %lld\n", total);
 		// forn(i, P) printf("%lld ", s[i]); printf("\n");
 		// forn(i, P) printf("%lld ", c[i]); printf("\n");
 	}
 
 	for (ll x: ans) printf(" %lld", x);
 	printf("\n");
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d:", q);
 		solve();
 	}
 	return 0;
 }
