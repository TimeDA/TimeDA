#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 #define MAX_N 1005
 int T;
 
 int N, S, x[MAX_N], y[MAX_N], z[MAX_N], vx[MAX_N], vy[MAX_N], vz[MAX_N];
 
 bool canDo(long long dist) {
     bool seen[MAX_N];
     memset(seen,0,sizeof(seen));
     queue <int> bfs;
     bfs.push(0);
     seen[0] = true;
     while (!bfs.empty()) {
         int cN = bfs.front();
         bfs.pop();
         FO (i,0,N) {
             //fprintf (stderr, "%d %d: %d\n",i, cN, (x[i]-x[cN])*(x[i]-x[cN])+(y[i]-y[cN])*(y[i]-y[cN])+(z[i]-z[cN])*(z[i]-z[cN]));
             if ((x[i]-x[cN])*(x[i]-x[cN])+(y[i]-y[cN])*(y[i]-y[cN])+(z[i]-z[cN])*(z[i]-z[cN]) <= dist) {
                 if (!seen[i]) {
                     seen[i] = true;
                     bfs.push(i);
                 }
             }
         }
     }
     return seen[1];
 }
 
 int main() {
     scanf ("%d", &T);
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &N, &S);
         FO (i,0,N) {
             scanf ("%d %d %d %d %d %d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
         }
         long long maxAns = 3000005;
         long long minAns = 0;
         long long bAns = INF;
         while (minAns <= maxAns) {
             long long midAns = (minAns+maxAns)/2;
             if (canDo(midAns)) {
                 bAns = midAns;
                 maxAns = midAns-1;
             } else {
                 minAns = midAns+1;
             }
         }
         printf ("%.6lf\n", sqrt(1.0*bAns));
     }
     return 0;
 }
