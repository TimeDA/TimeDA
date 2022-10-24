#include <bits/stdc++.h>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 const int N = 27;
 int n;
 char a[N][N];
 bool used1[N], used2[N];
 
 bool check(int cur) {
   if (cur == n) {
     return true;
   }
   for (int x = 0; x < n; ++x) {
     if (used1[x]) { continue; }
     used1[x] = true;
     int cnt = 0;
     for (int y = 0; y < n; ++y) {
       if (used2[y] || a[x][y] == '0') { continue; }
       cnt++;
       used2[y] = true;
       if (!check(cur + 1)) {
         return false;
       }
       used2[y] = false;
     }
     if (cnt == 0) { return false; }
     used1[x] = false;
   }
   return true;
 }
 
 int brute(int k, int cost) {
   if (k == n * n) {
     memset(used1, 0, sizeof(used1));
     memset(used2, 0, sizeof(used2));
     if (check(0)) {
       return cost;
     }
     return n * n;
   }
 
   int res = brute(k + 1, cost);
   int x = k / n;
   int y = k % n;
   if (a[x][y] == '0') {
     a[x][y] = '1';
     res = min(res, brute(k + 1, cost + 1));
     a[x][y] = '0';
   }
   return res;
 }
 
 void solve() {
   scanf("%d", &n);
   for (int i = 0; i < n; ++i) {
     scanf("%s", a[i]);
   }
   printf("%d\n", brute(0, 0));
 }
 
 int main()
 {
 #ifdef DBG1
   assert(freopen("input.txt", "r", stdin));
   assert(freopen("output.txt", "w", stdout));
   assert(freopen("err.txt", "w", stderr));
 #endif
 
   int tt;
   assert (scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case %d\n", ii);
     printf("Case #%d: ", ii);
     solve();
     fflush(stdout);
   }
 
   return 0;
 }
 
