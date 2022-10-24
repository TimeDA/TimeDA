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
 int a[10000];
 
 int main() {
 //    freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 
 	//freopen("B-large.in", "r", stdin);
 	//freopen("B-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
   		printf("Case #%d: ", tt);
 		cin >> n;
 		F0(i,n) cin >> a[i];
 		int ans = 0;
 		F0(i,n) {
 			int c1 = 0, c2 = 0;
 			F0(j,n) if (a[j] > a[i]) {
 				if (j < i) c1++; else c2++;
 			}
 			ans += min(c1, c2);
 		}
 		cout << ans << endl;
 	}
 	//while (1);
 	return 0;
 }
