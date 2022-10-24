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
 
 int i, j, k, m, n, l;
 double dp[205][205], p[205];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt1.in", "r", stdin);
 	freopen("B-small-attempt1.out", "w", stdout);
 
 	//freopen("B-large.in", "r", stdin);
 	//freopen("B-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		//cerr << tt << endl;
 		cin >> n >> k;
 		F0(i, n) cin >> p[i];
 		sort(p, p + n);
 		double ans = 0.0;
 		int bm = -1;
 		for (int x = 0; x <= k; x++) for (int y = 0; y <= k; y++) if (x + y == k) {
 			vector<double> a;
 			F0(i, x) a.push_back(p[i]);
 			for (int i = n - y; i < n; i++) a.push_back(p[i]);
 			//F0(i, n) if ((1 << i)&mask) a.push_back(p[i]);
 
 			F0(i, k + 1) F0(j, k + 1) dp[i][j] = 0;
 			dp[0][0] = 1.0;
 			F0(i, k) {
 				F0(j, i + 1) if (dp[i][j]) {
 					dp[i + 1][j] += dp[i][j] * (1 - a[i]);
 					dp[i + 1][j + 1] += dp[i][j] * a[i];
 				}
 			}
 			if (dp[k][k / 2] > ans) {
 				ans = dp[k][k / 2];
 			}
 		}
 		//F0(i, n) cout << p[i] << " "; cout << endl;
 		//F0(i, n) if ((1 << i)&bm)cout << 1; else cout << 0; cout << endl;
 
   		printf("Case #%d: %.10lf\n", tt, ans);
 		
 	}
 	return 0;
 }
