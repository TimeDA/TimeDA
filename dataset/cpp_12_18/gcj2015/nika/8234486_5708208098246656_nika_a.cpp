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
 int dx[] = { 0, -1, 0, 1 };
 int dy[] = { 1, 0, -1, 0 };
 string h = ">^<v";
 int i, j, k, m, n, l;
 string s[105];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 
 	//freopen("A-large.in", "r", stdin);
 	//freopen("A-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		//cerr << tt << endl;
 		printf("Case #%d: ", tt);
 
 		cin >> m >> n;
 		F0(i, m) cin >> s[i];
 		int ans = 0, good = 1;
 		F0(i, m) F0(j, n) if (s[i][j] != '.') {
 			int k = h.find(s[i][j]);
 			if (k == -1) throw 12;
 			bool coline = false;
 			F0(k, m) if (k != i && s[k][j] != '.') coline = true;
 			F0(k, n) if (k != j && s[i][k] != '.') coline = true;
 			if (!coline) good = 0; else {
 				ans++;
 				int x = i + dx[k], y = j + dy[k];
 				while (x >= 0 && x < m && y >= 0 && y < n) {
 					if (s[x][y] != '.') { ans--; break; }
 					x += dx[k];
 					y += dy[k];
 				}
 			}
 		}
 
 		if (!good) cout << "IMPOSSIBLE"; else cout << ans;
 		cout << endl;
 	}
 	return 0;
 }
