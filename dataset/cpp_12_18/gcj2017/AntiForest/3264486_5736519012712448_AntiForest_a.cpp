#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<62)-5)
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
 #define SZ(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int T;
 int N, K;
 bool pan[1005];
 
 int main() {
     scanf ("%d", &T);
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         char inp[1005];
         scanf (" %s ", inp);
         scanf ("%d ", &K);
         N = strlen(inp);
         FO (i,0,N) {
             pan[i] = (inp[i] == '+');
         }
         int ans = 0;
         FO (i,0,N-K+1) {
             if (!pan[i]) {
                 ans++;
                 FO (j,i,i+K) {
                     pan[j] = !pan[j];
                 }
             }
         }
         FO (i,0,N) {
             if (!pan[i]) {
                 ans = -1;
             }
         }
         if (ans == -1) {
             // DO IMPOSSIBLE CASE
             printf ("IMPOSSIBLE\n");
         } else {
             printf ("%d\n", ans);
         }
     }
     return 0;
 }
 
