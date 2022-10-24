#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef long long ll;
 typedef pair<int, int> PII;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 
 #define N 1010
 #define M 2010
 #define INF 1000000007
 int n, m;
 int S[M], px[M], py[M];
 int c[N];
 bool v[N];
 int f[N], g[N]; // father, edge
 vector<PII> A[N];
 int ti[N], tt;
 
 void add(int x) {
 	if (x < 0) S[-x-1]--;
 	else S[x]++;
 }
 
 void ff(int x) {
 	ti[x] = tt++;
 	v[x] = true;
 	for (vector<PII>::iterator i = A[x].begin(); i != A[x].end(); i ++)
 		if (g[x] != -i->se-1) {
 			if (v[i->fi]) {
 				if (ti[i->fi] > ti[x]) continue;
 				// some ancestor
 				add(i->se);
 				int p = x;
 				while (p != i->fi) {
 					add(g[p]);
 					p = f[p];
 				}
 			} else {
 				f[i->fi] = x;
 				g[i->fi] = i->se;
 				ff(i->fi);
 			}
 		}
 }
 
 int main() {
 	int _;
 	cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> m;
 		memset(S, 0, sizeof S);
 		for (int i = 0; i < n; i ++) A[i].clear();
 		for (int i = 0; i < m; i ++) {
 			int x, y;
 			cin >> x >>  y;
 			x--;
 			y--;
 			A[x].pb(mp(y, i));
 			A[y].pb(mp(x, -i-1));
 			px[i] = x;
 			py[i] = y;
 		}
 		
 		memset(f, -1, sizeof f);
 		for (int i = 0; i < n; i ++) g[i] = INF;
 		tt = 0;
 		memset(ti, 0, sizeof ti);
 		memset(v, 0, sizeof v);
 		for (int i = 0; i < n; i ++)
 			if (!v[i]) ff(i);
 		
 		bool F = true;
 		for (int i = 0; i < m; i ++)
 			if (!S[i]) F = false;
 		memset(c, 0, sizeof c);
 		for (int i = 0; i < m; i ++) {
 			c[px[i]] += S[i];
 			c[py[i]] -= S[i];
 		}
 		for (int i = 0; i < n; i ++)
 			if (c[i]) F = false;
 		printf ("Case #%d: ", __);
 		if (!F) puts ("IMPOSSIBLE"); else {
 			for (int i = 0; i < m; i ++)
 				printf ("%d%c", S[i], i == m-1?'\n':' ');
 		}
 	}
 	return 0;
 }