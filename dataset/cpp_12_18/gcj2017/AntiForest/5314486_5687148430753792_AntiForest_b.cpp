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
 int N, C, M;
 int degP[1005], degS[1005];
 
 void reset() {
     FO (i,0,1005) {
         degP[i] = 0;
         degS[i] = 0;
     }
 }
 
 bool canDo (int c) {
     int runAm = 0;
     for (int i = 1004; i >= 0; i--) {
         if (degS[i] > c) runAm += degS[i]-c;
         if (degS[i] < c) {
             runAm -= c-degS[i];
             runAm = max(0, runAm);
         }
     }
     return runAm == 0;
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         reset();
         scanf ("%d %d %d", &N, &C, &M);
         FO (i,0,M) {
             int pos, b;
             scanf ("%d %d", &pos, &b);
             pos--;
             b--;
             degP[b]++;
             degS[pos]++;
         }
         int lo = 0;
         int hi = 1005;
         int mid, bSoFar(0);
         while (lo <= hi) {
             mid = (lo+hi)/2;
             if (canDo(mid)) {
                 bSoFar = mid;
                 hi = mid-1;
             } else {
                 lo = mid+1;
             }
         }
         int deg = 0;
         FO (i,0,1005) {
             deg = max(deg, degP[i]);
         }
         deg = max(deg, bSoFar);
         int reloc = 0;
         FO (i,0,1005) {
             reloc += max(0, degS[i]-deg);
         }
         printf ("%d %d\n", deg, reloc);
     }
     return 0;
 }
