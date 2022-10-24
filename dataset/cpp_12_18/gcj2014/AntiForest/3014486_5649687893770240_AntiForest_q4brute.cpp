#include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <string>
 
 #define INF 1000000005
 using namespace std;
 
 int _T;
 int N, M;
 
 char str[100][100];
 int strL[100];
 int cP[100][100];
 int typ[100];
 
 int ans, ansW;
 
 int cAns;
 bool seen[100];
 
 void rec (int c) {
     if (c == M) {
         cAns = N;
         for (int p = 0; p < N; p++) seen[p] = false;
         for (int p = 0; p < M; p++) {
             seen[typ[p]] = true;
         }
         for (int p = 0; p < N; p++) {
             if (!seen[p]) return;
         }
         for (int p = 0; p < M; p++) {
             int maxC = 0;
             for (int t = 0; t < p; t++) {
                 if (typ[t] == typ[p]) {
                     maxC = max (maxC, cP[p][t]);
                 }
             }
             cAns += strL[p] - maxC;
         }
         if (cAns > ans) {
             ans = cAns;
             ansW = 0;
         }
         if (cAns == ans) {
             ansW++;
         }
         return;
     }
     for (int i = 0; i < N; i++) {
         typ[c] = i;
         rec (c+1);
     }
     return;
 }
 
 void reset() {
     ans = -INF;
     ansW = 0;
     return;
 }
 
     
 int main() {
     freopen ("q4.in", "r", stdin);
     freopen ("q4.out", "w", stdout);
     scanf ("%d", &_T);
     for (int _z = 1; _z <= _T; _z++) {
         printf ("Case #%d: ", _z);
         scanf ("%d %d", &M, &N);
         reset();
         for (int p = 0; p < M; p++) {
             scanf (" %s ", str[p]);
             strL[p] = strlen (str[p]);
         }
         for (int p = 0; p < M; p++) {
             for (int t = 0; t < M; t++) {
                 if (p == t) continue;
                 cP[p][t] = min (strL[p], strL[t]);
                 for (int q = 0; q < min (strL[p], strL[t]); q++) {
                     if (str[p][q] != str[t][q]) {
                         cP[p][t] = q;
                         break;
                     }
                 }
             }
         }
         rec(0);
         printf ("%d %d\n", ans, ansW);
     }
     return 0;
 }
                 
