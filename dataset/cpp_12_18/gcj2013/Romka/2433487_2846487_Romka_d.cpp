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
 
 double f[1 << 20][21];
 bool u[1 << 20][21];
 
 void canonize(int& mask, int n) {
 	int res = mask;
 	forn(i, n) {
 		mask = ((mask & 1) << (n-1)) + (mask >> 1);
 		if (mask < res) res = mask;
 	}
 	mask = res;
 }
 
 double getf(int mask, int n) {
 	canonize(mask, n);
 	// while ((mask & 1) == 0) mask >>= 1;
 	if (mask == (1 << n) - 1) return 0;
 	if (u[mask][n]) return f[mask][n];
 	u[mask][n] = true;
 	double& res = f[mask][n];
 
 	forn(i, n) {
 		int j = i;
 		int c = 0;
 		while (mask & (1 << j)) {
 			j = (j + 1) % n;
 			c++;
 		}
 		res += getf(mask ^ (1 << j), n) + n - c;
 	}
 
 	res /= n;
 
 	return res;
 }
 
 void solve() {
 	char s[25];
 	scanf("%s", s);
 	int n = strlen(s);
 	int mask = 0;
 	forn(i, n)
 		if (s[i] == 'X') mask ^= 1 << i;
 	printf("%.8f\n", getf(mask, n));
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