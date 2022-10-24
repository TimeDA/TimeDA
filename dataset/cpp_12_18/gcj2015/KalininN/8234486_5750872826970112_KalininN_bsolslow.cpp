#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const ld eps = 1e-8;
 
 pair<double, double> s[10];
 int n;
 double V, T;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T_ = 1; T_ <= NT; T_++)
     {
         printf("Case #%d:", T_);
 
         scanf("%d%lf%lf", &n, &V, &T);
         for (int i = 0; i < n; i++) scanf("%lf%lf", &s[i].second, &s[i].first);
         if (n == 1)
         {
             if (abs(s[0].first - T) > eps) printf(" IMPOSSIBLE\n");
             else printf(" %.20lf\n", (double)V / s[0].second);
         } else
         {
             if (abs(s[1].first - s[0].first) < eps)
             {
                 if (abs(s[0].first - T) > eps) printf(" IMPOSSIBLE\n");
                 else printf(" %.20lf\n", (double)V / (s[0].second + s[1].second));
             } else
             {
                 ld v0 = V * (T - s[1].first) / (s[0].first - s[1].first);
                 ld v1 = V - v0;
                 if (v0 < 0 || v1 < 0) printf(" IMPOSSIBLE\n");
                 else printf(" %.20lf\n", (double)max(v0 / s[0].second, v1 / s[1].second));
             }
         }
 
         fprintf(stderr, "%d/%d cases done!\n", T_, NT);
     }
     return 0;
 }
