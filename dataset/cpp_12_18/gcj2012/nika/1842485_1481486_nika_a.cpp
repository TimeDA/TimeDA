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
 #include <cstring>
 #include <sstream>
 using namespace std;
 typedef long long ll;
 typedef pair<int,int> pii;
 #define SZ(x) (int)(x.size())
 #define F0(i,n) for(i=0;i<n;i++)
 #define F1(i,n) for(i=1;i<=n;i++)
 const int inf = 1000000009;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l, ans;
 int x[1000002], h[1000002], X, d[1000002];
 
 int main() {
 //	freopen("a.in", "r", stdin);
 
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w", stdout);
 
 //	freopen("A-large.in", "r", stdin);
 //	freopen("A-large.out", "w", stdout);
 	int tt, tn; cin >> tn;
 	F1(tt,tn) {
         cin >> n;
         F0(i,n) cin >> x[i] >> h[i];
         cin >> X;
 
         memset(d, 0, sizeof(d));
 
         k = 0;
         if (x[0] <= h[0]) d[0] = x[0];
         for (i = 0; i < n; i++) if (d[i])
         {
             //cout << i << " " << d[i] << endl;
             for (j = i+1; j < n; j++)
             {
                 if (x[j]-x[i] > d[i]) break;
                 d[j] = max(d[j], min(x[j]-x[i],h[j]));
             }
             if (x[i] + d[i] >= X) k = 1;
         }
 
 
 		printf("Case #%d: ", tt);
 
         cout << ((k) ? ("YES") : ("NO")) << endl;
 	}
 	
 	return 0;
 }
