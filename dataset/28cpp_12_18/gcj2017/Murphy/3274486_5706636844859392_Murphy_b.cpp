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
 
 int dp[1500][1500][2];
 int o[1500];
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         memset(o, 0, sizeof o);
         int ac, aj; cin>>ac>>aj;
         REP(i, ac) {
             int s, t; cin>>s>>t;
             for (int j = (s + 1); j <= t; j++)
                 o[j] = 1;
         }
         REP(i, aj) {
             int s, t; cin>>s>>t;
             for (int j = (s + 1); j <= t; j++)
                 o[j] = 2;
         }
         int optimal = 10000;
         REP(first, 2)
         {
             memset(dp, 0x3f, sizeof dp);
             dp[0][0][first] = 0;
             REP(i, 1440) REP(j, i + 1) REP(k, 2) {
                 REP(x, 2)
                     if (o[i + 1] != x + 1) {
                         dp[i + 1][j + x][x] = min(dp[i + 1][j + x][x], dp[i][j][k] + (k != x));
                     }
             }
             optimal = min(optimal, min(dp[1440][720][first], dp[1440][720][1 - first] + 1));
         }
         printf("Case #%d: %d\n", caseN + 1, optimal);
     }
     return 0;
 }