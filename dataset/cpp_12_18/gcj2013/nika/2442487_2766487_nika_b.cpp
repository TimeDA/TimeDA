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
 
 int i, j, k, m, n, l;
 ll p;
 
 int main() {
 //    freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 
 //	freopen("X-large.in", "r", stdin);
 //	freopen("X-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
         cin >> n >> p;
         ll ans1 = 0, ans2 = 0;
 
         ll P, Q, R;
 
         P = 0; Q = (1LL << n) - 1;
         while (P < Q)
         {
             R = (P + Q + 1) / 2;
             // check if R will win
             ll x = R;
             ll y = p;
             for (i = n-1; i >= 0; i--)
             {
                // he loses, strongers lose
                if (x == 0) break;
                if (y <= (1LL<<i)) { x = 1; break; }
                y -= (1LL<<i);
                x = (x-1) / 2;
             }
             if (x == 0) P = R; else Q = R-1;
         }
         ans1 = P;
 
         P = 0; Q = (1LL << n) - 1;
         while (P < Q)
         {
             R = (P + Q + 1) / 2;
             // check if R can win
             ll x = R;
             ll y = p;
             for (i = n-1; i >= 0; i--)
             {
                if (x == (1LL<<(i+1))-1)
                {
                    if (y >= (1LL<<(i+1))) x = 0; else x = 1;
                    break;
                }
                // he wins, weakests win
                x = (x+1) / 2;
             }
             if (x == 0) P = R; else Q = R-1;
         }
         ans2 = P;
 
 		printf("Case #%d: ", tt);
         cout << ans1 << " " << ans2;
 		printf("\n");
 	}
 	
 	return 0;
 }
