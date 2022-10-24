#include <cstdio>
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 ll reverse(ll a) {
   ll b = 0;
   while (a) {
     b = b * 10 + a % 10;
     a /= 10;
   }
   return b;
 }
 
 ll solve() {
   ll n;
   cin >> n;
   if (n <= 10) {
     return n;
   }
   vector <int> dist(10 * n + 1, -1);
   vector <int> par(10 * n + 1);
   vector <int> q;
   q.push_back(1);
   dist[1] = 1;
   for (int i = 0; i < int(q.size()) && dist[n] == -1; ++i) {
     int a = q[i];
     if (dist[a + 1] == -1) {
       dist[a + 1] = dist[a] + 1;
       par[a + 1] = a;
       q.push_back(a + 1);
     }
     int ra = reverse(a);
     if (dist[ra] == -1) {
       dist[ra] = dist[a] + 1;
       par[ra] = a;
       q.push_back(ra);
     }
   }
   for (int i = (int)n; i != 1; i = par[i]) {
     dbg("%d ", i);
   }
   dbg("1\n");
   return dist[n];
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     dbg("Case #%d: ", ii);
     cout << solve() << "\n";
   }
 
   return 0;
 }
 
