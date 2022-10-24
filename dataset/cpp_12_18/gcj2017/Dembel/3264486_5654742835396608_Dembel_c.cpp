#ifdef DBG1
   #define _GLIBCXX_DEBUG
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__)
 #else
     #define dbg(...)
 #endif
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 void solve() {
   ll n, k;
   scanf("%lld%lld", &n, &k);
   map <ll, ll> q;
   q[n] = 1;
   while (k > 0) {
     auto it = q.rbegin();
     n = it->first;
     assert(n > 0);
     ll cnt = it->second;
     q.erase(n);
     dbg("n %lld cnt %lld k %lld\n", n, cnt, k);
     ll Ls = (n - 1) / 2;
     ll Rs = n - 1 - Ls;
     if (k <= cnt) {
       printf("%lld %lld", max(Ls, Rs), min(Ls, Rs));
       return;
     }
     k -= cnt;
     q[Ls] += cnt;
     q[Rs] += cnt;
   }
   assert(0);
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
 //    dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     printf("\n");
     fflush(stdout);
   }
   return 0;
 }
