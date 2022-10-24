#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 30
 
 int n; int a[N], b[N];
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n;
 		for (int i = 0; i < n; i ++) {
 			string s; cin >> s;
 			int x = 0;
 			for (int j = 0; j < n; j ++) (x*=2) += (s[j]-'0');
 			a[i] = x;
 		}
 		int S = N*N;
 		for (int p = 0; p < (1<<n*n); p ++) {
 			if (pct(p) >= S) continue; 
 			for (int i = 0; i < n; i ++) {
 				b[i] = a[i] | ((p>>(i*n))&((1<<n)-1));
 			}
 			bool F = true;
 			for (int i = 0; i < n; i ++) {
 				bool G = true; 
 				for (int q = 0; q < (1<<n); q ++) if ((q&b[i]) == q) {
 					int c = 0; 
 					for (int j = 0; j < n; j ++) if (j != i)
 						if (b[j]&q) c ++;
 					if (c < pct(q)) G = false; 
  				}
 				if (G) F = false; 
 			}
 			if (F) S = min(S, pct(p));
 		}
 		printf ("Case #%d: %d\n", __, S);
 	}
 	return 0;
 }