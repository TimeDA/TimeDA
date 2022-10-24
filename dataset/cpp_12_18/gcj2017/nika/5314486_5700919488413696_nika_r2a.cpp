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
 #define CL(x) memset(x, 0, sizeof(x))
 #define F0(i,n) for(int i=0;i<n;i++)
 #define F1(i,n) for(int i=1;i<=n;i++)
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l;
 int a[100], dp[101][101][101];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 
 	//freopen("A-large.in", "r", stdin);
 	//freopen("A-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
 		cin >> n >> m;
 		F0(i, 10) a[i] = 0;
 		F0(i, n) {
 			cin >> j;
 			a[j % m]++;
 		}
 		int ans = a[0];
 
 		CL(dp);
 
 		F0(i1, a[1] + 1) F0(i2, a[2] + 1) F0(i3, a[3] + 1) {
 			int add = ((i1 + i2 * 2 + i3 * 3) % m) == 0;
 			if (i1 < a[1]) dp[i1 + 1][i2][i3] = max(dp[i1 + 1][i2][i3], dp[i1][i2][i3] + add);
 			if (i2 < a[2]) dp[i1][i2 + 1][i3] = max(dp[i1][i2 + 1][i3], dp[i1][i2][i3] + add);
 			if (i3 < a[3]) dp[i1][i2][i3 + 1] = max(dp[i1][i2][i3 + 1], dp[i1][i2][i3] + add);
 		}
 		ans += dp[a[1]][a[2]][a[3]];
 	
   		printf("Case #%d: %d\n", tt, ans);
 	}
 	return 0;
 }
