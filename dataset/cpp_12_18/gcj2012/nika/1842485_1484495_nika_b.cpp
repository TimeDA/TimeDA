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
 
 int i, j, k, m, n, l, ans, X, Y, id[1005], r[1005], x[1005], y[1005], ansx[1005], ansy[1005];
 char ss[1000002];
 int cc(int a, int b) { return r[a] > r[b]; }
 
 int main() {
 //	freopen("b.in", "r", stdin);
 
     freopen("B-small-attempt2.in", "r", stdin);
     freopen("B-small-attempt2.out", "w", stdout);
 
 //	freopen("B-large.in", "r", stdin);
 //	freopen("B-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 	F1(tt,tn) {
         cin >> n >> X >> Y;
         F0(i,n) cin >> r[i];
         F0(i,n) id[i] = i;
         sort(id, id+n, cc);
 
         memset(x, 0, sizeof(x));
         memset(y, 0, sizeof(y));
         // first line
         F1(k,n-1)
         {
             int R2 = r[id[k]], R1 = r[id[k-1]];
             if (x[k-1] + R1 + R2 <= X)
             {
                 x[k] = x[k-1] + R1 + R2;
             } else break;
         }
 
         int y1 = -r[id[0]];
         int y2 = r[id[0]];
 
         for (k; k < n; k++)
         {
             int R2 = r[id[k]], R1 = r[id[k-1]];
             if (x[k-1] + R1 + R2 <= X)
             {
                /* if (k + 1 < n && 2*(r[id[k+1]]+R2) <= y2-y1)
                 {
                     x[k] = x[k+1] = x[k-1] + R1 + R2;
                     y[k] = y1 + R2;
                     y[k+1] = y[k] + R2 + r[id[k+1]];
                     k++;
                 }*/
                 x[k] = x[k-1] + R1 + R2;
                 y[k] = y[k-1];
             } else if (y2 + R2 <= Y)
             {
                 y1 = y2;
                 y2 = y1 + 2*R1;
                 y[k] = y1 + R1;
             } else throw 9;
         }
 
         F0(i,n) { ansx[id[i]] = x[i]; ansy[id[i]] = y[i]; }
         printf("Case #%d:", tt);
         F0(i,n) cout << " " << ansx[i] << " " << ansy[i];
         cout << endl;
 	}
 	
 	return 0;
 }
