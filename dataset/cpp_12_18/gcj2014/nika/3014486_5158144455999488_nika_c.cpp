#pragma comment(linker, "/STACK:50000000")
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <string>
 #include <vector>
 #include <iostream>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <queue>
 #include <sstream>
 using namespace std;
 typedef long long ll;
 typedef pair<int,int> pii;
 #define SZ(x) (int)(x.size())
 #define F0(i,n) for(int i=0;i<n;i++)
 #define F1(i,n) for(int i=1;i<=n;i++)
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l, W, H;
 int a[501][501];
 
 struct Edge {
   int x, y, rev;
   ll c, f;
 }; 
 
 const int MaxN = 100002;
 const int MaxE = 500002;
 ll cap;
 vector<int> adj[MaxN];
 Edge E[MaxE];
 int v[MaxN], s, t, En;
 
 void add(int x, int y, ll c) {
   E[En].x = x;
   E[En].y = y;
   E[En].c = c;
   E[En].f = 0;
   E[En].rev = En+1;
   adj[x].push_back(En);
   En++;
   E[En].x = y;
   E[En].y = x;
   E[En].c = 0;
   E[En].f = 0;
   E[En].rev = En-1;
   adj[y].push_back(En);
   En++;
 } 
 
 int rec(int i) {
   v[i] = 1;
   if (i == t) return 1;
   int sz = SZ(adj[i]);
   for (int _j = 0; _j < sz; _j++) {
     int j = adj[i][_j];
     if (E[j].f + cap <= E[j].c && !v[E[j].y] && rec(E[j].y)) {
       E[j].f += cap;
       E[ E[j].rev ].f -= cap;
       return 1;
     }
   }
   return 0;
 }
 
 ll getflow() {
   ll ans = 0;
   int i;
   cap = 1;
   while (cap) {
     for(i = 0; i <= t; i++) v[i] = 0;
     if (rec(s)) ans += cap; else cap /= 2;
   } 
   return ans;
 }
 
 int id1(int x, int y) {
 	return x * H + y + 1;
 }
 int id2(int x, int y) {
 	return x * H + y + 1 + W*H;
 }
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt2.in", "r", stdin);
 	freopen("C-small-attempt2.out", "w", stdout);
 	//freopen("x.out", "w", stdout);
 
 	//freopen("C-large.in", "r", stdin);
 	//freopen("C-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
   		printf("Case #%d: ", tt);
 		cin >> W >> H >> k;
 		F0(i,W) F0(j,H) a[i][j] = 1;
 		while (k--) {
 			int x1, y1, x2, y2;
 			cin >> x1 >> y1 >> x2 >> y2;
 			for (int i = x1; i <= x2; i++)
 				for (int j = y1; j <= y2; j++)
 					a[i][j] = 0;
 		}
 		En = 0;
 		s = 0;
 		t = 2*W*H+1;
 		F0(i,t+1) adj[i].clear();
 		F0(i,W) {
 			add(s, id1(i,0), 1);
 			add(id2(i,H-1), t, 1);
 		}
 		F0(i,W) F0(j,H) if (a[i][j])
 		{
 			add(id1(i,j), id2(i,j), 1);
 			if (i > 0 && a[i-1][j])
 				add(id2(i,j), id1(i-1,j), 1);
 			if (i+1 < W && a[i+1][j])
 				add(id2(i,j), id1(i+1,j), 1);
 			if (j+1 < H && a[i][j+1])
 				add(id2(i,j), id1(i,j+1), 1);
 			if (j > 0 && a[i][j-1])
 				add(id2(i,j), id1(i,j-1), 1);
 		}
 		cout << getflow() << endl;
 	}
 	//while (1);
 	return 0;
 }
