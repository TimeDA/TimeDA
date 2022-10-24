#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
   
 int n;
 double V, X;
 vector <double> v, x;
 
 /*
   t1 <= T, t2 <= T
   v1 * x1 * t1 + v2 * x1 * t2 = V * x1
   v1 * x1 * t1 + v2 * x2 * t2 = V * X
 
   v2 * t2 * (x2 - x1) = V * (X - x1);
   
    */
 
 bool check(double T) {
   return true;
 }
 
 const double eps = 1e-9;
 
 void solve() {
   assert (scanf("%d%lf%lf", &n, &V, &X) == 3);
   v.resize(n);
   x.resize(n);
   for (int i = 0; i < n; ++i) {
     assert(scanf("%lf%lf\n", &v[i], &x[i]) == 2);
   }
 
   if (n == 1) {
     v.push_back(0);
     x.push_back(x[0]);
     ++n;
   }
 
   if (fabs(x[0] - x[1]) < eps) {
     if (fabs(X - x[0]) < eps) {
       printf("%.10lf\n", V / (v[0] + v[1]));
     } else {
       printf("IMPOSSIBLE\n");
     }
   } else {
     double T2 = V * (X - x[0]) / (v[1] * (x[1] - x[0]));
     double T1 = V * (X - x[1]) / (v[0] * (x[0] - x[1]));
     if (T1 < -eps || T2 < -eps) {
       printf("IMPOSSIBLE\n");
     } else {
       printf("%.10lf\n", max(T1, T2));
     }
   }
 /*  double left = 0;
   double right = 1e7;
   for (int i = 0; i < 60; ++i) {
     int M = (left + right) / 2;
     if (check(M)) {
       right = M;
     } else {
       left = M;
     }
   }
   printf("%.10lf\n", left);*/
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     solve();
   }
 
   return 0;
 }
 
