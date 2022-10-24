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
 
 int aa(int x) {
 	return x < 0 ? -x : x;
 }
 
 const int R[4][4] = {
 	{1, 2, 3, 4},
 	{2, -1, 4, -3},
 	{3, -4, -1, 2},
 	{4, 3, -2, -1}
 };
 
 int mult(int a, int b) {
 	int va = aa(a) - 1;
 	int vb = aa(b) - 1;
 	int r = R[va][vb];
 	if (a * b < 0) r = -r;
 	return r;
 }
 
 bool isk[10010];
 
 bool solve() {
 	int n, k;
 	scanf("%d %d", &n, &k);
 	string z, s;
 	cin >> z;
 	forn(i, k) s += z;
 	n = s.size();
 
 	int c = 1;
 	isk[n] = false;
 	for (int z = n - 1; z >= 0; z--) {
 		c = mult(s[z] - 'i' + 2, c);
 		isk[z] = c == 4;
 	}
 	c = 1;
 	forn(i, n) {
 		c = mult(c, s[i] - 'i' + 2);
 		if (c == 2) {
 			int q = 1;
 			for (int j = i + 1; j < n - 1; j++) {
 				q = mult(q, s[j] - 'i' + 2);
 				if (q == 3 && isk[j + 1]) {
 					return true;
 				}
 			}
 		}
 	}
 
 	return false;
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		printf(solve() ? "YES\n" : "NO\n");
 	}
 	return 0;
 }
