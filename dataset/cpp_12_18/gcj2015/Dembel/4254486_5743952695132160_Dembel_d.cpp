#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 #include <iostream>
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
 typedef pair <ll, ll> pll;
 
 bool extractOne(const vector <pll> & e, vector <pll> & newE, ll x) {
   newE.clear();
   int n = int(e.size());
   if (x == 0) {
     for (int i = 0; i < n; ++i) {
       if (e[i].second % 2 != 0) {
         return 0;
       }
     }
     for (int i = 0; i < n; ++i) {
       newE.push_back(pll(e[i].first, e[i].second / 2));
     }
     return 1;
   }
   {
     vector <pll> e2 = e;
     for (int i = 0, j = 0; i < n; ++i) {
       if (!e2[i].second) {
         continue;
       }
       while (j < n && e2[j].first < e2[i].first + abs(x)) {
         ++j;
       }
       if (j == n || e2[j].first != e2[i].first + abs(x)) {
         return 0;
       }
       if (e2[j].second < e2[i].second) {
         return 0;
       }
       e2[j].second -= e2[i].second;
       newE.push_back(pll(e2[i].first + (x < 0 ? -x : 0), e2[i].second));
     }
     return 1;
   }
 }
 
 bool brute(const vector <pll> & e, vector <ll> & ans) {
   int n = int(e.size());
   for (int i = 0; i < n; ++i) {
     dbg("(%lld %lld), ", e[i].first, e[i].second);
   }
   dbg("\n");
   if (n == 1) {
     if (e[0].first) {
       return 0;
     }
     if (e[0].second == 1) {
       return 1;
     }
   }
   for (int i = 0; i < n; ++i) {
     assert (e[i].second > 0);
     vector <pll> newE;
     dbg("tryExtract %lld\n", e[i].first);
     if (extractOne(e, newE, e[i].first)) {
       if (brute(newE, ans)) {
         ans.push_back(e[i].first);
         return 1;
       }
     }
   }
   return 0;
 }
 
 void solve() {
   int n;
   cin >> n;
   vector <pll> e(n);
   for (int i = 0; i < n; ++i) {
     cin >> e[i].first;
   }
   for (int i = 0; i < n; ++i) {
     cin >> e[i].second;
   }
   vector <ll> ans;
   if (!brute (e, ans)) {
     printf("IMPOSSIBLE\n");
     assert (0);
   }
   reverse(ans.begin(), ans.end());
   for (int i = 0; i < int(ans.size()); ++i) {
     if (i) {
       cout << " ";
     }
     cout << ans[i];
   }
   cout << "\n";
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     fflush(stdout);
   }
 
   return 0;
 }
 
