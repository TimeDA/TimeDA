#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <cassert>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 typedef long double Double;
 
 int cs;
 int n;
 long long R[105], C[105], V, X;
 void reads(LL &v) {
   double x;
   scanf("%lf", &x);
   v = (long long)(x*10000.0 + 1e-5);
   //printf("read x=%lf, v= %lld\n", x, v);
 }
 void solve() {
   scanf("%d", &n);
   reads(V); reads(X);
   for(int i=0;i<n;i++) {
     reads(R[i]);
     reads(C[i]);
   }
   printf("Case #%d: ", cs);
   if(n==1) {
     if(X != C[0]) puts("IMPOSSIBLE");
     else printf("%.9f\n",(double)( (Double)V / (Double)R[0]));
   } else if (n == 2) {
     if(X < min(C[0], C[1]) || X > max(C[0], C[1]))
       puts("IMPOSSIBLE");
     else if (C[0] == C[1]) {
       printf("%.9f\n", (double)((Double)V / (Double)(R[0]+R[1])));
     } else if (C[0] == X) {
       printf("%.9f\n", (double)((Double)V / (Double)R[0]));
     } else if (C[1] == X) {
       printf("%.9f\n", (double) ((Double)V / (Double)R[1]));
     }
     else {
       Double A = R[0], B = R[1], c = (Double)R[0]/1e4*C[0], d = (Double)R[1]/1e4*C[1];
       Double E = V, F = (Double)V/1e4*X;
       Double t1 = (E*d-F*B) / (A*d-B*c);
       Double t2 = (A*F-c*E) / (A*d-B*c);
       if (t1 < -1e-6 || t2 < -1e-6) {
         fprintf(stderr, "[%d], %lld %lld %lld %lld %lld %lld\n", cs, R[0], R[1], C[0], C[1], V, X);
         //fprintf(stderr, "[%d] t1=%f, t2=%f\n", cs, t1, t2);
         assert(false && puts("IMPOSSIBLE"));
       }
       else printf("%.9f\n", (double)max(t1, t2));
     }
   }
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
