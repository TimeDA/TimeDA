#include <cstdio>
 #include <numeric>
 #include <iostream>
 #include <vector>
 #include <set>
 #include <cstring>
 #include <string>
 #include <map>
 #include <cmath>
 #include <ctime>
 #include <algorithm>
 #include <bitset>
 #include <queue>
 #include <sstream>
 #include <deque>
 #include <cassert>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 #define rep(i,n) for(int i = 0; i < (n); i++)
 #define re return
 #define fi first
 #define se second
 #define sz(x) ((int) (x).size())
 #define all(x) (x).begin(), (x).end()
 #define sqr(x) ((x) * (x))
 #define sqrt(x) sqrt(abs(x))
 #define y0 y3487465
 #define y1 y8687969
 #define fill(x,y) memset(x,y,sizeof(x))
 #define prev PREV
                          
 typedef vector<int> vi;
 typedef long long ll;
 typedef long double ld;
 typedef double D;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef vector<vi> vvi;
 
 template<class T> T abs(T x) { re x > 0 ? x : -x; }
 
 int n;
 int m;
 
 string s[50];
 pair<ii, int> g[50][50][4];
 int num[50][50];
 int r = 0;
 ii p[100];
 int can[50][50][4];
 vi v[100*2];
 vi rv[100*2];
 vi w[100*2];
 int tout[100*2];
 int was[100*2];
 int col[100*2];
 vi q;
 int ct;
 
 int addedge (int i1, int j1, int t1, int i2, int j2, int t2) {
 	int a = num[i1][j1] * 2 + t1;
 	int b = num[i2][j2] * 2 + t2;
 //	printf ("%d %d\n", a, b);
 	v[a].pb (b);
 	rv[b].pb (a);
 	re 0;
 }
 
 int go (int x) {
 	if (was[x]) re 0;
 	was[x] = 1;
 	for (int i = 0; i < sz (v[x]); i++) go (v[x][i]);
 	q.pb (x);
 	re 0;
 }
 
 int go2 (int x, int c) {
 	if (was[x]) re 0;
 //	printf ("col %d = %d\n", x, c);
 	was[x] = 1;
 	col[x] = c;
 	for (int i = 0; i < sz (rv[x]); i++) go2 (rv[x][i], c);
 	re 0;
 }
 
 int go3 (int x) {
 	if (was[x]) re 0;
 	was[x] = 1;
 	for (int i = 0; i < sz (w[x]); i++) go3 (w[x][i]);
 //	printf ("%d = %d\n", x, ct);
 	tout[x] = ct++;
 	re 0;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n >> m;
 		for (int i = 0; i < n; i++) cin >> s[i];
 		r = 0;
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				if (s[i][j] == '-' || s[i][j] == '|') {
 					p[r] = mp (i, j);
 					num[i][j] = r++;
 				}	
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				for (int t = 0; t < 4; t++)
 					g[i][j][t] = mp (mp (0, 0), -1);
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				if (s[i][j] == '-' || s[i][j] == '|') {
 					for (int t = 0; t < 4; t++) {
 						can[i][j][t] = 1;
 						int ii = i, jj = j;
 						while (true) {
 							ii += int (t == 0) - int (t == 1);
 							jj += int (t == 2) - int (t == 3);
 							if (ii < 0 || jj < 0 || ii >= n || jj >= m || s[ii][jj] == '#') break;
 							if (s[ii][jj] == '-' || s[ii][jj] == '|') {
 								can[i][j][t] = 0;
 								break;
 							} else g[ii][jj][t] = mp (mp (i, j), t);
 						}
 					}
 				}
 		for (int i = 0; i < r * 2; i++) {
 			v[i].clear ();
 			rv[i].clear ();
 		}	
 		for (int i = 0; i < r; i++) {
 			int ii = p[i].fi;
 			int jj = p[i].se;
 			if (!can[ii][jj][0] || !can[ii][jj][1]) addedge (ii, jj, 0, ii, jj, 1);
 			if (!can[ii][jj][2] || !can[ii][jj][3]) addedge (ii, jj, 1, ii, jj, 0);
 		}
 		int ok = 1;
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				if (s[i][j] == '.') {
 					vector<pair<ii, int> > v;
 					for (int k = 0; k < 4; k++)
 						if (g[i][j][k].se != -1) {
 							int ii = g[i][j][k].fi.fi;
 							int jj = g[i][j][k].fi.se;
 							int t = g[i][j][k].se;
 							if (can[ii][jj][t] && can[ii][jj][t ^ 1])
 								v.pb (mp (mp (ii, jj), t));
 						}
 //					printf ("%d %d = %d\n", i, j, sz (v));	
 					if (sz (v) == 0) ok = 0; else
 					if (sz (v) == 1) {
 						int ii = v[0].fi.fi;
 						int jj = v[0].fi.se;
 						int t = v[0].se / 2;
 						addedge (ii, jj, t ^ 1, ii, jj, t);
 					} else {
 						assert (sz (v) == 2);
 						int i1 = v[0].fi.fi;
 						int j1 = v[0].fi.se;
 						int t1 = v[0].se / 2;
 						int i2 = v[1].fi.fi;
 						int j2 = v[1].fi.se;
 						int t2 = v[1].se / 2;
 						addedge (i1, j1, t1 ^ 1, i2, j2, t2);
 						addedge (i2, j2, t2 ^ 1, i1, j1, t1);
 					}
 				}
 		if (ok) {
 			memset (was, 0, sizeof (was));
 			q.clear ();
 			for (int i = 0; i < r * 2; i++)
 				if (!was[i])
 					go (i);
 			memset (was, 0, sizeof (was));
 			reverse (all (q));
 			int c = 0;
 			for (int i = 0; i < r * 2; i++)
 				if (!was[q[i]])
 					go2 (q[i], c++);
 			for (int i = 0; i < r; i++)
 				if (col[2 * i] == col[2 * i + 1])
 					ok = 0;
 			if (ok) {
 				for (int i = 0; i < c; i++) w[i].clear ();
 				for (int i = 0; i < r * 2; i++)
 					for (int j = 0; j < sz (v[i]); j++)
 						if (col[i] != col[v[i][j]])
 							w[col[i]].pb (col[v[i][j]]);
 				memset (was, 0, sizeof (was));
 				ct = 0;
 				for (int i = 0; i < c; i++)
 					if (!was[i])
 						go3 (i);
 				for (int i = 0; i < r; i++)
 					if (tout[col[2 * i]] < tout[col[2 * i + 1]])
 						s[p[i].fi][p[i].se] = '|';
 					else
 						s[p[i].fi][p[i].se] = '-';	
 			}
 		}
 		cout << "Case #" << it << ": ";
 		if (!ok) cout << "IMPOSSIBLE" << endl; else {
 			cout << "POSSIBLE" << endl;
 			for (int i = 0; i < n; i++) cout << s[i] << endl;
 		}
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }