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
 
 int n, m, a[110][110], u[110][110];
 
 string solve() {
 	scanf("%d %d", &n, &m);
 	forn(i, n) forn(j, m) scanf("%d", &a[i][j]);
 
 	memset(u, 0, sizeof(u));
 
 	for (int h = 1; h <= 101; h++) {
 		forn(i, n) {
 			bool ok = true;
 			forn(j, m) if (a[i][j] != h) { ok = false; break; }
 			if (ok) forn(j, m) u[i][j] = h;
 		}
 
 		forn(j, m) {
 			bool ok = true;
 			forn(i, n) if (a[i][j] != h) { ok = false; break; }
 			if (ok) forn(i, n) u[i][j] = h;
 		}
 
 		forn(i, n) forn(j, m) if (a[i][j] == h && u[i][j] != h) return "NO";
 		forn(i, n) forn(j, m) if (a[i][j] == h) a[i][j] = h + 1;
 	}
 
 	return "YES";
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		printf("%s\n", solve().c_str());
 	}
 	return 0;
 }