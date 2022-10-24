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
 #define CL(a,x) memset(x, a, sizeof(x))
 const int inf = 1000000009;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l, ans;
 char ss[1000002];
 ll a[1000002], all;
 
 int main() {
  //   freopen("x.in", "r", stdin);
 
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w", stdout);
 
 //	freopen("A-large.in", "r", stdin);
 //	freopen("A-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 	F1(tt,tn) {
         cerr << tt << endl;
         ll p, q, r, s;
         cin >> n >> p >> q >> r >> s;
         all = 0;
         F0(i,n) { a[i] = (i*p + q)%r + s; all += a[i]; }
 
         ll P=0, Q=1e15, R;
         while (P < Q) {
             R=(P+Q) / 2;
             int i = 0;
             ll cur = 0;
             while (i < n && cur + a[i] <= R) {
                 cur += a[i++];
             }
             cur = 0;
             while (i < n && cur + a[i] <= R) {
                 cur += a[i++];
             }
             cur = 0;
             while (i < n) {
                 cur += a[i++];
             }
             if (cur <= R)
                 Q = R; else P = R + 1;
         }
         printf("Case #%d: %.10lf\n", tt, 1.0-(1.0*P / all));
 	}
 
 	return 0;
 }
