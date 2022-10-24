#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 int dp[128][128][128];
 int N, K;
 int gao(int r1, int r2, int r3, int rr) {
     if (dp[r1][r2][r3] != -1)
         return dp[r1][r2][r3];
     int best = 0;
     if (r1 == 0 && r2 == 0 && r3 == 0) return 0;
     rr %= K;
     if (r1) 
         best = max(best, gao(r1 - 1, r2, r3, rr + 1) + (rr == 0));
     if (r2) 
         best = max(best, gao(r1, r2 - 1, r3, rr + 2) + (rr == 0));
     if (r3) 
         best = max(best, gao(r1, r2, r3 - 1, rr + 3) + (rr == 0));
     
     dp[r1][r2][r3] = best;
     return best;
 }
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         // int N, K;
         cin>>N>>K;
         assert(K <= 4);
         int r[4] = {0, 0, 0, 0};
         int res = 0;
         REP(i, N) {
             int x; cin>>x;
             x %= K;
             if (x == 0) res++;
             else r[x]++;
         }
         memset(dp, -1, sizeof dp);
         int r2 = gao(r[1], r[2], r[3], 0);
         res += r2;
         printf("Case #%d: %d\n", caseN + 1, res);
     }
     return 0;
 }