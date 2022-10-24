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
 ll N;
 ll p10[20], all1[20];
 
 int main() {
     scanf ("%d", &T);
     p10[0] = 1;
     FO (i,1,19) {
         p10[i] = p10[i-1]*10;
     }
     all1[0] = 1;
     FO (i,1,19) {
         all1[i] = all1[i-1]+p10[i];
     }
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%lld", &N);
         ll soFar = 0;
         for (int i = 18; i >= 0; i--) {
             for (int j = 9; j >= 0; j--) {
                 if (i == 18 && j > 1) continue;
                 ll newSoFar = soFar+j*all1[i];
                 if (newSoFar <= N) {
                     soFar += j*p10[i];
                     break;
                 }
             }
         }
         printf ("%lld\n", soFar);
     }
     return 0;
 }
 
