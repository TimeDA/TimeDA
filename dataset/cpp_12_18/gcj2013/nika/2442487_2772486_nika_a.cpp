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
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 typedef pair<pii, int> p3;
 int i, j, k, m, n, l;
 p3 tickets[2005];
 
 ll sum(ll k)
 {
     ll r = (n + n - k + 1) * k / 2;
     return r % MOD;
 }
 
 int main() {
 //    freopen("x.in", "r", stdin);
 
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 
 //	freopen("X-large.in", "r", stdin);
 //	freopen("X-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
         ll oldcost = 0, newcost = 0;
 
         cin >> n >> m;
         vector<p3> events;
         F0(i,m)
         {
             cin >> tickets[i].first.first >> tickets[i].first.second >> tickets[i].second;
             oldcost = (oldcost + sum(tickets[i].first.second - tickets[i].first.first) * tickets[i].second) % MOD;
             events.push_back( p3( pii(tickets[i].first.first, -1), tickets[i].second ) );
             events.push_back( p3( pii(tickets[i].first.second, 1), tickets[i].second ) );
         }
         sort(events.begin(), events.end());
         vector<p3> open;
 
         for (i = 0; i < SZ(events); i++)
         {
             if (events[i].first.second == -1)
             {
                 open.push_back(events[i]);
             }
             else
             {
                 ll x = events[i].second;
                 while (x > 0)
                 {
                     if (open.empty()) throw 9;
                     ll y = open.back().second;
                     ll z = min(x, y);
                     newcost = (newcost + sum(events[i].first.first - open.back().first.first) * z) % MOD;
                     x -= z;
                     open.back().second -= z;
                     if (open.back().second == 0) open.pop_back();
                 }
             }
         }
         if (open.size() != 0) throw 9;
 
         ll ans = (oldcost - newcost + MOD) % MOD;
 		printf("Case #%d: ", tt);
         cout << ans;
 		printf("\n");
 	}
 	
 	return 0;
 }
