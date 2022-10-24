#include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstdint>
 #include <climits>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 struct info {
   int r, c, b;
 };
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int r, c, n, d;
     scanf("%d%d%d%d", &r, &c, &n, &d);
     vector<vector<long long>> board(r, vector<long long>(c, LLONG_MAX));
     vector<info> points;
     for (int pointIndex = 0; pointIndex < n; pointIndex++) {
       int ri, ci, bi;
       scanf("%d%d%d", &ri, &ci, &bi);
       ri--, ci--;
       {
         info ff;
         ff.r = ri;
         ff.c = ci;
         ff.b = bi;
         points.emplace_back(ff);
       }
       for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
           long long dist = abs(i - ri) + abs(j - ci);
           board[i][j] = min(board[i][j], bi + dist * d);
         }
       }
     }
 
     bool impossible = false;
     for (int i = 0; i < points.size(); i++) {
       if (board[points[i].r][points[i].c] != points[i].b) {
         impossible = true;
         break;
       }
     }
     long long ans = 0;
     const int mod = 1000000007;
     for (int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
         ans += board[i][j] % mod;
         ans %= mod;
       }
     }
     if (impossible) {
       printf("Case #%d: IMPOSSIBLE\n", testcase);
     } else {
       printf("Case #%d: %lld\n", testcase, ans);
     }
   }
   return 0;
 }