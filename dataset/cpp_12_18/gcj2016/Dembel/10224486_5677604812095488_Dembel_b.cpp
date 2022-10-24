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
 
 double brute(int n, int k, int curN, int curK, const vector <double> & p, const vector <double> & dp) {
   if (curN == n) {
     if (curK < k) {
       return 0;
     }
     return dp[k];
   }
   double res = brute(n, k, curN + 1, curK, p, dp);
   if (curK < k) {
     vector <double> dp2(dp.size(), 0.0);
     for (int i = 0; i < int(dp.size()) - 1; ++i) {
       dp2[i + 1] += dp[i] * p[curN];
       dp2[i] += dp[i + 1] * (1.0 - p[curN]);
     }
     res = max(res, brute(n, k, curN + 1, curK + 1, p, dp2));
   }
   return res;
 }
 
 void solve() {
   int n, k;
   scanf("%d%d", &n, &k);
   vector <double> p(n);
   for (int i = 0; i < n; ++i) {
     scanf("%lf", &p[i]);
   }
   vector <double> dp(2 * k + 1, 0.0);
   dp[k] = 1.0;
   printf("%.10lf\n", brute(n, k, 0, 0, p, dp));
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
 
