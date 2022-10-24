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
 int x[1001], y[1001], seat[1001], user[1001];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 
 	//freopen("B-large.in", "r", stdin);
 	//freopen("B-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
 		int ans = 0;
 
 		cin >> n >> m >> k;
 
 		F1(i, n) seat[i] = 0;
 		F1(i, m) user[i] = 0;
 
 		F0(i, k) {
 			cin >> x[i] >> y[i];
 			seat[x[i]]++;
 			user[y[i]]++;
 		}
 
 		F1(i, m) ans = max(ans, user[i]);
 		int sum = 0;
 		F1(i, n) {
 			sum += seat[i];
 			ans = max(ans, sum / i);
 		}
 
 		int ans2 = k;
 		F1(i, n) {
 			ans2 -= min(seat[i], ans);
 		}
 		
   		printf("Case #%d: %d %d\n", tt, ans, ans2);
 	}
 	return 0;
 }
