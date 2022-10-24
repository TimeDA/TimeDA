#include <cstdio>
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
 
 struct Event {
   int x, diff;
 
   Event (int x, int diff) : x(x), diff(diff) {}
 
   bool operator < (const Event & e) const {
     if (x != e.x) {
       return x < e.x;
     }
     return diff > e.diff;
   }
 };
 
 void solve() {
   int n, D;
   assert (scanf("%d%d", &n, &D) == 2);
   int s0, as, cs, rs;
   assert (scanf("%d%d%d%d", &s0, &as, &cs, &rs) == 4);
   int m0, am, cm, rm;
   assert (scanf("%d%d%d%d", &m0, &am, &cm, &rm) == 4);
   vector <int> s(n), par(n);
   s[0] = s0;
   par[0] = m0;
   for (int i = 1; i < n; ++i) {
     s[i] = (s[i - 1] * ll(as) + cs) % rs;
     par[i] = (par[i - 1] * ll(am) + cm) % rm;
   }
   par[0] = -1;
   for (int i = 1; i < n; ++i) {
     par[i] %= i;
   }
 
   for (int i = 0; i < n; ++i) {
     dbg("%d %d\n", par[i], s[i]);
   }
 
   vector <int> maxS(n), minS(n);
   maxS[0] = minS[0] = s[0];
   for (int i = 1; i < n; ++i) {
     maxS[i] = max(s[i], maxS[par[i]]);
     minS[i] = min(s[i], minS[par[i]]);
   }
 
   vector <Event> events;
   for (int i = 1; i < n; ++i) {
     if (minS[i] + D < maxS[i]) {
       continue;
     }
     events.push_back(Event(minS[i], -1));
     events.push_back(Event(maxS[i] - D, 1));
   }
   sort(events.begin(), events.end());
   int cnt = 0;
   int ans = 1;
   for (int i = 0; i < int(events.size()); ++i) {
     dbg("i = %d, e = (%d, %d)\n", i, events[i].x, events[i].diff);
     if (events[i].diff > 0) {
       cnt += events[i].diff;
     }
     int x = events[i].x;
     dbg("x = %d, cnt = %d\n", x, cnt);
     if (x <= s[0] && s[0] <= x + D) {
       ans = max(ans, cnt + 1);
     }
     if (events[i].diff < 0) {
       cnt += events[i].diff;
     }
   }
   printf("%d\n", ans);
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case #%d\n", ii);
     printf("Case #%d: ", ii);
     solve();
   }
 
   return 0;
 }
 
