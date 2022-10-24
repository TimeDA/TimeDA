#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 #define EPS 1e-9
 
 /*~~~~TEMPLATE END~~~~*/
 
 int T;
 
 int N;
 double _V, _X;
 long double temX;
 long double V, X, r[105], c[105];
 
 long double v[105], val[105];
 
 long double ans;
 
 int main() {
     freopen ("b.in", "r", stdin);
     freopen ("b.out", "w", stdout);
     scanf ("%d", &T);
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         double _X, _V;
         scanf ("%d %lf %lf", &N, &_V, &_X);
         X = _X;
         V = _V;
         FO (i,0,N) {
             double _a, _b;
             scanf ("%lf %lf", &_a, &_b);
             r[i] = _a;
             c[i] = _b;
         }
         if (N == 2) {
             if (c[0] > c[1]) {
                 swap (r[0],r[1]);
                 swap (c[0],c[1]);
             }
         }
         if (c[0] == c[1]) {
             N = 1;
             r[0] += r[1];
         }
         if (N == 1) {
             if (c[0] < X-EPS || c[0] > X+EPS) {
                 printf ("IMPOSSIBLE\n");
             } else {
                 double ans = V/r[0];
                 printf ("%.10lf\n", ans);
             }
             continue;
         }
         if (c[0] > X+EPS || c[1] < X-EPS) {
             printf ("IMPOSSIBLE\n");
             continue;
         }
         long double tem = X-c[1];
         long double a = tem/(c[0]-c[1]);
         long double amA = a*V;
         ans = amA/r[0];
         ans = max (ans, (V-amA)/r[1]);
         double printAns = ans;
         printf ("%.10lf\n", printAns);
     }
     return 0;
 }
         
         
         
         
         
         
 
 
 
