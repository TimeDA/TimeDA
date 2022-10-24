#include <cstdio>
 #include <algorithm>
 
 #define MAX_N 10005
 using namespace std;
 
 int _T;
 int N, S, a[MAX_N];
 int numHas[MAX_N];
 
 int ans;
 
 void reset() {
     for (int i = 0; i < 1000; i++) {
         numHas[i] = 0;
     }
     ans = 0;
     return;
 }
 
 
 int main() {
     freopen ("q1.in", "r", stdin);
     freopen ("q1.out", "w", stdout);
     scanf ("%d", &_T);
     for (int _z=1; _z <= _T; _z++) {
         printf ("Case #%d: ", _z);
         reset();
         scanf ("%d %d", &N, &S);
         if (N == 1) {
             scanf ("%d", &a[0]);
             printf ("1\n");
             continue;
         }
         for (int i = 0; i < N; i++) {
             scanf ("%d", &a[i]);
         }
         sort (a, a+N);
         for (int i = 0; i < N; i++) {
             numHas[a[i]]++;
         }
         for (int p = 0; p < N; p++) {
             if (numHas[a[p]] == 0) continue;
             else {
                 numHas[a[p]]--;
                 ans++;
                 for (int t = S-a[p]; t >= a[p]; t--) {
                     if (numHas[t]) {
                         numHas[t]--;
                         break;
                     }
                 }
             }
         }
         printf ("%d\n", ans);
     }
     return 0;
 }
             
                 
