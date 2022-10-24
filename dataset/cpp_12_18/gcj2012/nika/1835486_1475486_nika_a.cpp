#include <cstdio>
 #include <cstdlib>
 #include <cstring>
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
 #define CL(x,a) memset(a,x,sizeof(a));
 const int inf = 1000000009;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l, ans, t[1001], p[1001], id[1001];
 char ss[1000002];
 
 int cc(int x, int y)
 {
     if (p[y] * t[x] != p[x] * t[y])
         return p[y] * t[x] < p[x] * t[y];
     return x < y;
 }
 
 int main() {
 //    freopen("a.in", "r", stdin);
 
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.txt", "w", stdout);
 
 //	  freopen("A-large.in", "r", stdin);
 //	  freopen("A-large.txt", "w", stdout);
 
 	int tt, tn; cin >> tn;
 	F1(tt,tn) {
         cin >> n;
         F0(i,n) { cin >> t[i]; }
         F0(i,n) cin >> p[i];
         vector<int> v;
         k = 0;
         F0(i,n) if (p[i] == 0) v.push_back(i); else id[k++] = i;
         sort(id, id+k, cc);
         printf("Case #%d:", tt);
         F0(i,k) cout << " " << id[i];
         F0(i,SZ(v)) cout << " " << v[i];
         cout << endl;
 	}
 	
 	return 0;
 }
