#include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <cassert>
 
 const int MAXN = 110;
 const int MAXT = MAXN * 12;
 int h[MAXN], g[MAXN];
 int dp[MAXN][MAXT];
 int P, Q, n;
 
 int solve(int tot) {
   int tmp = 0;
   for (int c = 0 ; ; ++c, tmp += P) {
     if (tmp >= tot) {
       return c;
     }
     if ((tot - tmp) % Q <= P && (tot - tmp) % Q != 0)
       return c;
   }
   return -1;
 }
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int ca = 1 ; ca <= T ; ++ca) {
     scanf("%d%d%d",&P, &Q, &n);
     for (int i = 0 ; i < n ; ++i) {
       scanf("%d%d", &h[i], &g[i]);
     }
     memset(dp, -1, sizeof(dp));
     dp[0][0] = 0;
     for (int i = 0 ; i < n ; ++i) {
       for (int j = 0 ; j < MAXT ; ++j) {
         if (dp[i][j] == -1) continue;
         // doable
         if (j * P >= h[i]) {
           int cost = (h[i]+P-1)/P;
           dp[i+1][j-cost] = std::max(dp[i+1][j-cost], dp[i][j] + g[i]);
         }
         int next = i;
         int flg = 0, old;
         if (i != 0) {
           flg = 1; old = h[i];
           h[i] -= Q;
           if (h[i] <= 0) ++next;
         }
         int pre_spare = j;
         for ( ; next < n ; ++next) {
           int nhit = solve(h[next]);
           if (nhit == -1) {
             pre_spare += (h[next] + Q - 1) / Q;
             continue;
           }
           if ((nhit - pre_spare) * (P + Q) < h[next]) {
             
             int spare = (h[next] - nhit * P) / Q - nhit;
             if (pre_spare + spare < 0) {
               // printf("=== %d\n", pre_spare + spare)
                spare = -pre_spare;
             }
             assert(pre_spare + spare >= 0);
             dp[next+1][pre_spare+spare] = std::max(dp[next+1][pre_spare+spare], dp[i][j] + g[next]);
           }
           pre_spare += (h[next] + Q - 1) / Q;
         }
         if (flg) {
           h[i] = old;
         }
       }
     }
     int best = 0;
     for (int j = 0 ; j < MAXT ; ++j)
       if (dp[n][j] > best) best = dp[n][j];
     /*
     for (int i = 0 ; i <= n ; ++i)
       for (int j = 0 ; j < MAXT ; ++j)
         if (dp[i][j] != -1) printf("dp[%d][%d]:%d\n", i,j, dp[i][j]);
     */
     printf("Case #%d: %d\n", ca, best);
   }
   return 0;
 }
 
 
