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
 ll N, K;
 int main() {
     scanf ("%d", &T);
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%lld %lld", &N, &K);
         ll doneAm = 0;
         ll highV = N+1;
         ll highAm = 1;
         ll lowV = 0;
         ll lowAm = 0;
 
         while (true) {
             //printf ("%lld %lld %lld %lld\n", highV, highAm, lowV, lowAm);
             ll newHighV, newHighAm, newLowV, newLowAm;
             newHighV = (highV+1)/2;
             newHighAm = 0;
             newLowV = newHighV-1;
             newLowAm = 0;
             if (doneAm + highAm >= K) {
                 printf ("%lld %lld\n", (highV+1)/2-1, highV/2-1);
                 break;
             }
             newHighAm += highAm;
             if (highV % 2) {
                 newLowAm += highAm;
             } else {
                 newHighAm += highAm;
             }
             doneAm += highAm;
             if (doneAm + lowAm >= K) {
                 printf ("%lld %lld\n", (lowV+1)/2-1, lowV/2-1);
                 break;
             }
             doneAm += lowAm;
             if ((lowV+1)/2 == newHighV) {
                 newHighAm += lowAm;
             } else {
                 newLowAm += lowAm;
             }
             newLowAm += lowAm;
             tie (highV, highAm, lowV, lowAm) = make_tuple(newHighV, newHighAm, newLowV, newLowAm);
         }
     }
     return 0;
 }
