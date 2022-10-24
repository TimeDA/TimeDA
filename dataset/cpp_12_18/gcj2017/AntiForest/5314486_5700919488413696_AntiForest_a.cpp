#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<62)-5)
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
 #define SZ(v) int(v.size())
 #define pb push_back
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int _T;
 
 int dp[5][105][105][105][5];
 int N, P, am[5];
 
 void calcDP() {
     FO (k,2,5) {
         FO (i,0,105) {
             FO (j,0,105) {
                 FO (p,0,105) {
                     FO (t,0,k) {
                         int bst = 0;
                         if (i > 0) bst = max(bst, dp[k][i-1][j][p][(t+1)%k]);
                         if (j > 0) bst = max(bst, dp[k][i][j-1][p][(t+2)%k]);
                         if (p > 0) bst = max(bst, dp[k][i][j][p-1][(t+3)%k]);
                         if (t == 0 && i+j+p > 0) bst++;
                         dp[k][i][j][p][t] = bst;
                     }
                 }
             }
         }
     }
 }
 
 void reset() {
     FO (i,0,5) am[i] = 0;
 }
 
 int main() {
     calcDP();
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &N, &P);
         reset();
         FO (i,0,N) {
             int _g;
             scanf ("%d", &_g);
             am[_g % P]++;
         }
         int ans = am[0];
         printf ("%d\n", ans+dp[P][am[1]][am[2]][am[3]][0]);
     }
     return 0;
 }
