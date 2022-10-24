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
 
 int _T;
 double D;
 int N;
 
 double K[1005], S[1005];
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%lf %d", &D, &N);
         FO (i,0,N) {
             scanf ("%lf %lf", &K[i], &S[i]);
         }
         double ans = 1000000000000000000000000.0;
         FO (i,0,N) {
             double cAns = (D-K[i])/S[i];
             cAns  = D/cAns;
             ans = min (ans,cAns);
         }
         printf ("%.9lf\n", ans);
     }
     return 0;
 }
