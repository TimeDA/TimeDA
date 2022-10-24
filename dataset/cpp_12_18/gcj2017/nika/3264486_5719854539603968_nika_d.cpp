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
 typedef pair<int, int> pii;
 #define F0(i,n) for (int i = 0; i < n; i++)
 #define F1(i,n) for (int i = 1; i <= n; i++)
 #define CL(a,x) memset(x, a, sizeof(x));
 #define SZ(x) ((int)x.size())
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, n, l;
 char c, s[101][101], f[101][101];
 
 const int N = 401;
 int x[N], y[N], V[N], ans;
 int d[N][N];
 
 int rec(int n, int i) {
 	V[i] = 1;
 	for (int j = 0; j < n; j++) if (d[i][j]) {
 		if (y[j] == -1 || (V[y[j]] == 0 && rec(n, y[j]))) {
 			x[i] = j;
 			y[j] = i;
 			return 1;
 		}
 	}
 	return 0;
 }
 
 void matching(int n)
 {
 	memset(x, -1, sizeof(x));
 	memset(y, -1, sizeof(y));
 	F0(i, n) if (x[i] == -1) {
 		for (j = 0; j < n; j++) V[j] = 0;
 		ans += rec(n, i);
 	}
 }
 
 
 int main() {
 	//freopen("x.in", "r", stdin);
 
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("D-small-attempt1.out", "w", stdout);
 
 	//freopen("D-large.in", "r", stdin);
 	//freopen("D-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		//cerr << tt << endl;
 		int cnt;
 		cin >> n >> cnt;
 		CL(0, s); CL(0, f);
 		while (cnt--) {
 			cin >> c >> i >> j; i--; j--;
 			s[i][j] = f[i][j] = c;
 		}
 
 		ans = 0;
 
 		// vertical
 		CL(0, d);
 		F0(i, n) F0(j, n) d[i][j] = 1;
 		F0(i, n) F0(j, n) if (s[i][j] == 'o' || s[i][j] == 'x') {
 			ans++;
 			F0(k, n) {
 				d[i][k] = d[k][j] = 0;
 			}
 		}
 		matching(n);
 		F0(i, n) if (x[i] != -1) {
 			int j = x[i];
 			if (!f[i][j]) f[i][j] = 'x';
 			else f[i][j] = 'o';
 		}
 
 		// diagonal
 		CL(0, d);
 		F0(i, n) F0(j, n) {
 			int d1 = i + j;
 			int d2 = i - j + (n - 1);
 			d[d1][d2] = 1;
 		}
 
 		F0(i, n) F0(j, n) if (s[i][j] == 'o' || s[i][j] == '+') {
 			ans++;
 			int d1 = i + j;
 			int d2 = i - j + (n - 1);
 			F0(k, 2 * n - 1) {
 				d[d1][k] = d[k][d2] = 0;
 			}
 		}
 		matching(2 * n - 1);
 		F0(d1, 2 * n - 1) {
 			int d2 = x[d1];
 			if (d2 != -1) {
 				d2 -= (n - 1);
 				int i = (d1 + d2) / 2;
 				int j = (d1 - d2) / 2;
 				if (!f[i][j]) f[i][j] = '+';
 				else f[i][j] = 'o';
 			}
 		}
 		
 		vector<pair<char, pii> > v;
 		F0(i, n) F0(j, n) if (s[i][j] != f[i][j]) v.push_back(make_pair(f[i][j], pii(i, j)));
 
   		printf("Case #%d: %d %d\n", tt, ans, SZ(v));
 		for (auto p : v) {
 			cout << p.first << " " << p.second.first + 1 << " " << p.second.second + 1 << endl;
 		}
 	}
 	return 0;
 }
