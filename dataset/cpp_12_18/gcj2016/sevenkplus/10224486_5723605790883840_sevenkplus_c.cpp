#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 210
 
 int n, m; PII a[N]; 
 
 int pr[N][N], pc[N][N], pL; 
 vector<int> A[N*N]; 
 int v[N*N]; 
 
 void addE(int x, int y) {
 	A[x].pb(y); A[y].pb(x);
 }
 
 int tr(int x) {
 	if (x < m) return pr[0][x];
 	x -= m;
 	if (x < n) return pc[x][m];
 	x -= n;
 	if (x < m) return pr[n][m-x-1];
 	x -= m;
 	if (x < n) return pc[n-x-1][0];
 	puts ("WTF"); 
 	return -1; 
 }
 
 int mu; 
 
 void ff(int x) {
 	v[x] = mu;
 	for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++) 
 		if (v[*i] == -1) ff(*i);
 }
 
 bool can(int p) {
 	for (int i = 0; i < pL; i ++) A[i].clear(); 
 	for (int i = 0; i < n; i ++)
 		for (int j = 0; j < m; j ++) {
 			if (p&1) {
 				addE(pr[i][j], pc[i][j]); 
 				addE(pr[i+1][j], pc[i][j+1]);
 			} else {
 				addE(pr[i][j], pc[i][j+1]); 
 				addE(pr[i+1][j], pc[i][j]);
 			}
 			p /= 2;
 		}
 	memset(v, -1, sizeof v); 
 	mu = 0; 
 	for (int i = 0; i < pL; i ++) 
 		if (v[i] == -1) {ff(i); mu ++;}
 	for (int i = 0; i < n+m; i ++) {
 		if (v[tr(a[i].fi)] != v[tr(a[i].se)]) return false;
 	}
 	return true; 
 }
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> m;
 		for (int i = 0; i < n+m; i ++) {
 			cin >> a[i].fi >> a[i].se; 
 			a[i].fi --; a[i].se --; 
 		}
 		pL = 0;
 		for (int i = 0; i <= n; i ++) 
 			for (int j = 0; j < m; j ++) {
 				pr[i][j] = pL++;;
 			}
 		for (int i = 0; i < n; i ++) 
 			for (int j = 0; j <= m; j ++) {
 				pc[i][j] = pL++;;
 			}
 		int S = -1;
 		for (int p = 0; p < (1<<n*m); p ++)
 			if (can(p)) {S = p; break;}
 		printf ("Case #%d:\n", __);
 		if (S == -1) puts ("IMPOSSIBLE"); else {
 			int p = S;
 			for (int i = 0; i < n; i ++) {
 				for (int j = 0; j < m; j ++) {
 					if (p&1) putchar('/'); else putchar('\\'); 
 					p /= 2;
 				}
 				puts (""); 
 			}
 		}
 	}
 	return 0;
 }