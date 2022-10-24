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
 
 int i, j, k, m, n, l, v;
 string s[55];
 int id[55][55];
 int g[200][200];
 int vis[100][100][4];
 int cx[100], cy[100];
 
 set<int> e[100][100];
 
 const int dx[] = { -1,0,1,0 };
 const int dy[] = { 0,1,0,-1 };
 
 
 int through[100], fail;
 
 void beam(int x, int y, int k) {
 	F0(i, m) F0(j, n) F0(u, 4) vis[i][j][u] = 0;
 	vis[x][y][k] = 1;
 	while (1) {
 		x += dx[k];
 		y += dy[k];
 		if (x < 0 || x >= m || y < 0 || y >= n) break;
 		if (s[x][y] == '#') break;
 
 		if (s[x][y] == '/') {
 			if (k <= 1) k = 1 - k; else k = 5 - k;
 		}
 		else if (s[x][y] == '\\') {
 			k = 3 - k;
 		}
 		else if (id[x][y] != -1) {
 			fail = 1;
 		}
 		else {
 			if (s[x][y] != '.') throw 12;
 			e[x][y].insert(v);
 		}
 		if (vis[x][y][k] == 1) break;
 		vis[x][y][k] = 1;
 	}
 }
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt0.in", "r", stdin);
 	freopen("C-small-attempt0.out", "w", stdout);
 	
 	//freopen("C-large.in", "r", stdin);
 	//freopen("C-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
 
 		cin >> m >> n;
 		F0(i, m) cin >> s[i];
 
 		k = 0;
 		F0(i, m) F0(j, n) {
 			if (s[i][j] == '|' || s[i][j] == '-') {
 				cx[k] = i;
 				cy[k] = j;
 				id[i][j] = k++;
 			}
 			else id[i][j] = -1;
 		}
 
 		F0(i, 2 * k) F0(j, 2 * k) g[i][j] = 0;
 
 		F0(i, m) F0(j, n) if (s[i][j] == '.') {
 			e[i][j].clear();
 		}
 
 		F0(i, m) F0(j, n) if (id[i][j] >= 0) {
 			v = 2 * id[i][j];
 			fail = 0;
 			beam(i, j, 0);
 			beam(i, j, 2);
 			if (fail) g[v][v ^ 1] = 1;
 
 			fail = 0;
 			v = 2 * id[i][j] + 1;
 			beam(i, j, 1);
 			beam(i, j, 3);
 			if (fail) g[v][v ^ 1] = 1;
 		}
 
 		string ans = "POSSIBLE";
 
 		F0(i, m) F0(j, n) if (s[i][j] == '.') {
 			vector<int> v(e[i][j].begin(), e[i][j].end());
 			if (v.empty() || SZ(v) > 2) {
 				ans = "IMPOSSIBLE"; continue;
 			}
 			if (SZ(v) == 1) g[v[0] ^ 1][v[0]] = 1;
 			else {
 				g[v[0] ^ 1][v[1]] = 1;
 				g[v[1] ^ 1][v[0]] = 1;
 			}
 		}
 
 		F0(l, 2 * k) F0(i, 2 * k) F0(j, 2 * k) if (g[i][l] && g[l][j]) g[i][j] = 1;
 		F0(i, k) if (g[2 * i][2 * i + 1] && g[2 * i + 1][2 * i]) ans = "IMPOSSIBLE"; else {
 			if (g[2 * i][2 * i + 1]) s[cx[i]][cy[i]] = '-'; else s[cx[i]][cy[i]] = '|';
 		}
 	
   		printf("Case #%d: %s\n", tt, ans.c_str());
 		if (ans == "POSSIBLE") F0(i, m) cout << s[i] << endl;
 	}
 	return 0;
 }
