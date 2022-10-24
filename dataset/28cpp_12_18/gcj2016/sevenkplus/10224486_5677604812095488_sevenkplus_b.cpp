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
 
 int n, m; double p[N]; 
 double q[N];
 
 double f[N][N];
 
 double ff(int c) {
 	int L = 0;
 	for (int i = 0; i < n; i ++) {	
 		if (i>=c && i < n-(m-c)) continue; 
 		q[L++] = p[i];
 	}
 	for (int i = 0; i <= m; i ++)
 		for (int j = 0; j <= i; j ++) f[i][j] = 0; 
 	f[0][0] = 1;
 	for (int i = 0; i < m; i ++)
 		for (int j = 0; j <= i; j ++) {
 			f[i+1][j] += f[i][j]*(1-q[i]);
 			f[i+1][j+1] += f[i][j]*q[i];
 		}
 	return f[m][m/2];
 }
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> m;
 		for (int i = 0; i < n; i ++) cin >> p[i];
 		sort(p, p+n); 
 		double S = 0; 
 		for (int i = 0; i <= m; i ++) 
 			S = max(S, ff(i));
 		printf ("Case #%d: %.9lf\n", __, S);
 	}
 	return 0;
 }