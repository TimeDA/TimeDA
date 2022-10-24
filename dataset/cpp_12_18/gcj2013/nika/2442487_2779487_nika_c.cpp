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
 #define F0(i,n) for(i=0;i<n;i++)
 #define F1(i,n) for(i=1;i<=n;i++)
 const int inf = 1000000009;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l, p[2005], a[2005], b[2005], na[2005], nb[2005];
 
 int z[2005];
 void gen()
 {
     n = 20;
     F0(i,n) z[i] = i+1;
     random_shuffle(z,z+n);
     F0(i,n)
     {
         a[i]=1;
         F0(j,i) if (z[j]<z[i]) a[i]=max(a[i],a[j]+1);
     }
     for(i=n-1;i>=0;i--)
     {
         b[i]=1;
         for(j=i+1;j<n;j++) if (z[i]>z[j]) b[i]=max(b[i],b[j]+1);
     }
 }
 
 bool go(int k)
 {
     if (k == n+1) return 1;
 
     int a2 = 1;
     F0(i,n)
     {
         if (p[i] != -1) a2 = max(a2, a[i] + 1);
         na[i] = a2;
     }
     int b2 = 1;
     for (i = n-1; i >= 0; i--)
     {
         if (p[i] != -1) b2 = max(b2, b[i] + 1);
         nb[i] = b2;
     }
     vector<int> v;
     F0(i,n) if (p[i] == -1 && a[i] == na[i] && b[i] == nb[i])
     {
         v.push_back(i);
     }
     for (int x = 0; x < SZ(v); x++)
     {
         p[v[x]] = k;
         if (go(k+1)) return true;
         p[v[x]] = -1;
     }
     return false;
 }
 
 int main() {
 
 //    freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt0.in", "r", stdin);
 	freopen("C-small-attempt0.out", "w", stdout);
 
 //	freopen("X-large.in", "r", stdin);
 //	freopen("X-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
         cin >> n;
         F0(i,n) cin >> a[i];
         F0(i,n) cin >> b[i];
 //        gen();
         F0(i,n) p[i] = -1;
 
         if (!go(1)) throw 9;
 
 		printf("Case #%d:", tt);
         for (i = 0; i < n; i++) cout << " " << p[i];
 		printf("\n");
 	}
 	
 	return 0;
 }
