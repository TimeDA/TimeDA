#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int _T;
 int N, K;
 double p[205];
 
 double ans;
 
 double newArr[205];
 double dp[205][205];
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         ans = 0;
         scanf ("%d %d", &N, &K);
         FO (i,0,N) scanf ("%lf", &p[i]);
         sort (p, p+N);
         FO (i,-1,K) {
             memset (newArr, 0, sizeof(newArr));
             int firstCutoff = i;
             int stuffIn = 0;
             FO (i,0,N) {
                 if (i <= firstCutoff) {
                     newArr[stuffIn++] = p[i];
                 }
             }
             for (int i = N-1; i >= 0; i--) {
                 if (stuffIn < K) {
                     newArr[stuffIn++] = p[i];
                 }
             }
             sort (newArr, newArr+K);
             // do dp:
             memset (dp, 0, sizeof(dp));
             dp[0][0] = 1;
             FO (i,1,K+1) {
                 FO (p,0,i+1) {
                     if (p != 0) dp[i][p] = newArr[i-1]*dp[i-1][p-1];
                     dp[i][p] += (1-newArr[i-1])*dp[i-1][p];
                 }
             }
             ans = max (ans, dp[K][K/2]);
         }
         printf ("%.8lf\n", ans);
     }
     return 0;
 }
