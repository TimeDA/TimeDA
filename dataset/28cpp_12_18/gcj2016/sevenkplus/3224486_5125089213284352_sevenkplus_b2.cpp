#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 110
 
 int n, p[N]; string s; 
 vector<string> S; 
 vector<int> A[N]; 
 double F[N]; 
 int w[N]; 
 
 void ff(int x) {
 	w[x] = 1;
 	for (int i = 0; i < (int) A[x].size(); i ++) {
 		ff(A[x][i]); w[x] += w[A[x][i]]; 
 	}
 }
 
 vector<int> cur, nc; 
 
 int getr() {
 	int sw = 0;
 	for (int i = 0; i < (int) cur.size(); i ++)
 		sw += w[cur[i]]; 
 	int cap = RAND_MAX/sw*sw; 
 	int x = rand();
 	while (x >= cap) x = rand(); 
 	x %= sw;
 	for (int i = 0; i < (int) cur.size(); i ++) {
 		if (x < w[cur[i]]) return cur[i];
 		else x -= w[cur[i]];
 	}
 	puts ("WTF");
 	return -1;
 }
 
 void run () {
 	cur.clear(); 
 	cur.pb(0); 
 	string u; 
 	for (int z = 0; z < n; z ++) {
 		int c = getr(); 
 		// cout << (int) cur.size() << endl;
 		if (c > 0) u += s[c-1]; 
 		nc.clear();
 		for (int j = 0; j < (int) cur.size(); j ++)
 			if (cur[j] != c) nc.pb(cur[j]);
 		for (int j = 0; j < (int) A[c].size(); j ++)
 			nc.pb(A[c][j]); 
 		cur = nc;
 	}
 	S.pb(u); 
 }
 
 void gen() {
 	for (int i = 0; i < n; i ++) A[i].clear(); 
 	for (int i = 1; i < n; i ++) 
 		A[p[i]].pb(i); 
 	ff(0);
 	for (int i = 0; i < 10000; i ++) run(); 
 }
 
 int main () {
 	srand(777); 
 	F[0] = 1;
 	for (int i = 1; i < N; i ++)
 		F[i] = F[i-1]*i; 
 	int _; cin >> _; 
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n; n ++; 
 		for (int i = 1; i < n; i ++) cin >> p[i];
 		cin >> s;
 		S.clear(); 
 		gen(); 
 		printf ("Case #%d:", __);
 		int m; 
 		cin >> m;
 		while (m--) {
 			string t;
 			cin >> t;
 			int TT = (int) S.size();
 			int SS = 0;
 			for (int i = 0; i < TT; i ++) 
 				if (S[i].find(t) != -1) SS ++;
 			//cout << SS << " " << TT << endl;
 			putchar(' ');
 			printf("%.9lf", (double) SS/TT); 
 		}
 		puts (""); 
 	}
 	return 0;
 }