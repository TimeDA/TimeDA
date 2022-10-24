#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<60)-5)
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
 
 #define MAX_N 105
 //const ll INF = 100000000000000005;
 
 int _T;
 int N, Q;
 ll E[MAX_N], S[MAX_N];
 
 ll d[MAX_N][MAX_N];
 
 double actD[MAX_N][MAX_N];
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &N, &Q);
         FO (i,0,N) {
             scanf ("%lld %lld", &E[i], &S[i]);
         }
         FO (i,0,N) {
             FO (j,0,N) {
                 scanf ("%lld", &d[i][j]);
                 if (d[i][j] == -1) {
                     d[i][j] = INFLL;
                 }
             }
         }
         FO (k,0,N) {
             FO (i,0,N) {
                 FO (j,0,N) {
                     d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                 }
             }
         }
         FO (i,0,N) {
             FO (j,0,N) {
                 if (d[i][j] == INFLL) actD[i][j] = INFLL;
                 else if (d[i][j] > E[i]) actD[i][j] = INFLL;
                 else {
                     actD[i][j] = d[i][j]*1.0/S[i];
                 }
             }
         }
         FO (k,0,N) {
             FO (i,0,N) {
                 FO (j,0,N) {
                     actD[i][j] = min(actD[i][j], actD[i][k]+actD[k][j]);
                 }
             }
         }
         FO (i,0,Q) {
             int u, v;
             scanf ("%d %d", &u, &v);
             u--;
             v--;
             printf ("%.9lf ", actD[u][v]);
         }
         printf ("\n");
     }
     return 0;
 }
