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
 
 int i, j, k, m, n, l, ans, x[2005];
 ll h[2005];
 char ss[1000002];
 
 void solve()
 {
     ll L = 0, R = 1000000000;
 
     h[n] = 1000000000;
     h[n-1] = 0;
     for (i = n-2; i >= 1; i--)
     {
         k = x[i];
         for (j = i+1; j < k; j++)
         {
             ll dh = h[k]-h[j];
             R = min(R, dh*(k-i)/(k-j));
         }
         for (j = k+1; j < n; j++)
         {
             ll dh = h[k]-h[j];
             L = max(R, dh*(k-i)/(k-j)+1);
         }
         //if (L > R) throw 9;
         L = (L+R)/2;
         h[i]=h[k]-L;
         if (h[i] < 0) h[i] = 0;
         if (h[i] > 1000000000) h[i] = 1000000000;
     }
     F1(i,n) cout << " " << h[i];
     cout << endl;
 }
 
 int main() {
 //	freopen("c.in", "r", stdin);
 
     freopen("C-small-attempt1.in", "r", stdin);
     freopen("C-small-attempt1.out", "w", stdout);
 
 //	freopen("C-large.in", "r", stdin);
 //	freopen("C-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 	F1(tt,tn) {
         cin >> n;
         F1(i,n-1) cin >> x[i];
         int good = 1;
         F1(j,n-1) F1(i,j-1)
         {
             if (x[i] > j && x[i] < x[j]) good = 0;
         }
 
         printf("Case #%d:", tt);
 
         if (!good)
             cout << " Impossible" << endl;
         else solve();
 	}
 	
 	return 0;
 }
