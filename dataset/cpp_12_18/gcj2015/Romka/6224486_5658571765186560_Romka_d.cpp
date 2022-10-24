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
 
 bool solve() {
 	int x, r, c;
 	scanf("%d %d %d", &x, &r, &c);
 	if (r > c) swap(r, c);
 	if (x == 1) return true;
 	if (x == 2) {
 		if (r != 1 || c != 1)
 			if (r * c % 2 == 0)
 				return true;
 		return false;
 	}
 	if (x == 3) {
 		if (r == 1 || c == 1) return false;
 		if (r == 2 && c == 3) return true;
 		if (r == 3 && c == 4) return true;
 		if (r == 3 && c == 3) return true;
 		return false;
 	}
 	if (x == 4) {
 		if (r == 1) return false;
 		if (r == 2) return false;
 		if (r == 3) return c == 4;
 		return true;
 	}
 	return false;
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: %s\n", q, solve() ? "GABRIEL" : "RICHARD");
 	}
 	return 0;
 }
