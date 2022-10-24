#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 int cmp(double x , double y)
 {
     if (x - y < -1e-7) return -1;
     else if (x - y > 1e-7) return 1;
     else return 0;
 }
 int main()
 {
 	freopen("B-small-attempt0.in" , "r" , stdin);
 	freopen("B-small-attempt0.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         int n;
         double v , x;
         double r[105];
         double c[105];
         scanf("%d %lf %lf" , &n , &v , &x);
         for (int i = 0; i < n; i ++) scanf("%lf %lf" , &r[i] , &c[i]);
     
         if (n == 1)
         {
             if (c[0] != x) printf("IMPOSSIBLE\n");
             else printf("%lf\n" , v/r[0]);
         }
         else
         {
             if ((cmp(c[0] , x) > 0 && cmp(c[1] , x) > 0) || (cmp(c[0] , x) < 0 && cmp(c[1] , x) < 0)) printf("IMPOSSIBLE\n");
             else if (cmp(c[0] , x) == 0 && cmp(c[1] , x) != 0) printf("%lf\n" , v/r[0]);
             else if (cmp(c[0] , x) != 0 && cmp(c[1] , x) == 0) printf("%lf\n" , v/r[1]);
             else if (cmp(c[0] , x) == 0 && cmp(c[1] , x) == 0) printf("%lf\n" , v/(r[0]+r[1]));
             else {
                 double t1 = (x * v - c[0]*v) / (r[1]*c[1] - c[0]*r[1]);
                 double t2 = (v - r[1]*t1) / r[0];
                 printf("%lf\n" , max(t1,t2));
             }
         }
     }
     return 0;
 }