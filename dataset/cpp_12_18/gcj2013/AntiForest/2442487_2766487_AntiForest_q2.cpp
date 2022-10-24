#include <cstdio>
 #include <algorithm>
 
 using namespace std;
 
 int T;
 int N;
 long long P;
 long long cP, temP, lP;
 long long cPlc;
 long long fPlc, cGap;
 
 int main() {
     freopen ("q2.in", "r", stdin);
     freopen ("q2.out", "w", stdout);
     scanf ("%d", &T);
     for (int _z=1; _z <= T; _z++) {
         printf ("Case #%d: ", _z);
         scanf ("%d %lld", &N, &P);
         lP = 1;
         for (int i = 0; i < N; i++) {
             lP *= 2;
         }
         //Find largest guaranteed, so worst case
         cP = 1;
         cGap = lP;
         fPlc = 0;
         for (int i = 0;; i++) {
             temP = fPlc + max (cGap/2,1ll);
             //printf ("%lld %lld\n", temP, cP);
             if (temP >= P) {
                 //This is the ans
                 printf ("%lld ", min(lP-1, cP*2-2));
                 break;
             }
             cP *= 2;
             cGap /= 2;
             fPlc += cGap;
         }
         //Find largest that can, so best case
         cP = 1;
         cPlc = lP;
         for (int i = 0;; i++) {
             temP = cP;
             if (cPlc <= P) {
                 printf ("%lld\n", lP-temP);
                 break;
             }
             cP *= 2;
             cPlc /= 2;
         }
     }
     return 0;
 }
