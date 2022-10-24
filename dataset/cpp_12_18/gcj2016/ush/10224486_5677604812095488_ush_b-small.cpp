
 #include <cassert>
 #include <cstring>
 #include <cstdio>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
 using namespace std;
 typedef long long ll;
 
 
 double ps[210];
 double dp[210][210];
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int n, nChoose;
     scanf("%d%d", &n, &nChoose);
     REP(i, n)
       scanf("%lf", &ps[i]);
     double res = 0;
     REP(pat, 1 << n){
       if(__builtin_popcount(pat) != nChoose)
         continue;
       memset(dp, 0, sizeof dp);
       dp[0][0] = 1;
       REP(i, n){
         REP(j, n){
           if((pat>>i) & 1){
             dp[i+1][j] = j == 0 ? dp[i][j]*(1-ps[i]) : dp[i][j-1]*ps[i] + dp[i][j]*(1-ps[i]);
           }else{
             dp[i+1][j] = dp[i][j];
           }
         }
       }
         res = max(res, dp[n][nChoose/2]);
     }
     
     printf("Case #%d: %.10f\n", iCase+1, res);
     fflush(stdout);
   }
   return 0;
 }
