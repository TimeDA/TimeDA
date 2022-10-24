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
 
 int brute(int p, vector <int> & a, map<vector<int>,int> & cache) {
   auto it = cache.find(a);
   if (it != cache.end()) {
     return it->second;
   }
   
   int res = 0;
   int mod = a[0];
   for (int i = 1; i < p; ++i) {
     if (a[i]) {
       a[i]--;
       a[0] = (mod + i) % p;
       res = max(res, brute(p, a, cache) + (mod == 0 ? 1 : 0));
       a[i]++;
     }
   }
   a[0] = mod;
   return cache[a] = res;
 }
 
 void solve() {
   int n, p;
   scanf("%d%d", &n, &p);
   vector <int> a(p, 0);
   for (int i = 0; i < n; ++i) {
     int x;
     scanf("%d", &x);
     a[x % p]++;
   }
   int res = a[0];
   a[0] = 0;
   map<vector<int>, int> cache;
   res += brute(p, a, cache);
   printf("%d", res);
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
