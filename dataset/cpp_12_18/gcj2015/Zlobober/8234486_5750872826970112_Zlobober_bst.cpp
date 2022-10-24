#include <cstdio>
 #include <cmath>
 #include <cassert>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 const int N = 105;
 
 double R[N], C[N];
 
 void solve(int cs)
 {
     int n;
     scanf("%d", &n);
     double v, x;
     scanf("%lf %lf", &v, &x);
     double sr = 0, mr = 1e100;
     double mxt = -1e100, mnt = 1e100;
     for (int i = 0; i < n; i++)
     {
         scanf("%lf %lf", &R[i], &C[i]);
         sr += R[i];
         mr = min(mr, R[i]);
         mxt = max(mxt, C[i]);
         mnt = min(mnt, C[i]);
     }
     if (n == 1)
     {
         if (fabs(C[0] - x) < 1e-5)
             printf("Case #%d: %.9lf\n", cs, v / R[0]);
         else
             printf("Case #%d: IMPOSSIBLE\n", cs);
     }
     else
     {
         if (C[0] > C[1])
             swap(C[0], C[1]), swap(R[0], R[1]);
         if (C[1] + 1e-5 < x || C[0] - 1e-5 > x)
             printf("Case #%d: IMPOSSIBLE\n", cs);
         else if (fabs(C[0] - C[1]) < 1e-5)
             printf("Case #%d: %.9lf\n", cs, v / (R[0] + R[1]));
         else
         {
             double a = (C[1] - x) / (C[1] - C[0]);
             double b = (x - C[0]) / (C[1] - C[0]);
             double av = a * v;
             double bv = b * v;
             printf("Case #%d: %.10lf\n", cs, max(av / R[0], bv / R[1]));
         }
     }
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
