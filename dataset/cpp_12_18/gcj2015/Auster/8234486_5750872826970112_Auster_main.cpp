#pragma comment(linker, "/STACK:134217728")
 
 #include <cstdio>
 #include <iostream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <string>
 #include <algorithm>
 #include <numeric>
 #include <functional>
 #include <cmath>
 #include <complex>
 #include <memory.h>
 #include <time.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int t;
 
 int n;
 double v, x;
 double r[1 << 7], c[1 << 7];
 
 const double eps = 1e-9;
 
 int main()
 {
 	freopen("B-small-attempt4.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	scanf("%d", &t);
 	for(int test = 1; test <= t; ++test)
 	{
 		scanf("%d%lf%lf", &n, &v, &x);
 		for(int i = 0; i < n; ++i)
 			scanf("%lf%lf", &r[i], &c[i]);
 
 		if (n > 2)
 			continue;
 
 		printf("Case #%d: ", test);
 
 		if (n == 1)
 		{
 			if (fabs(c[0] - x) < eps)
 				printf("%.10lf\n", v / r[0]);
 			else
 				printf("IMPOSSIBLE\n");
 		}
 		else
 		{
 			double res = 1e9;
 			if (fabs(c[0] - x) < eps)
 				res = min(res, v / r[0]);
 			if (fabs(c[1] - x) < eps)
 				res = min(res, v / r[1]);
 
 			if (fabs(c[0] - c[1]) > eps)
 			{
 				double lambda = (x - c[1]) / (c[0] - c[1]);
 				if (lambda > -eps && lambda < 1.0 + eps) 
 					res = min(res, max((v * lambda) / r[0], (v * (1.0 - lambda)) / r[1]));
 			}
 
 			if (res == 1e9)
 				printf("IMPOSSIBLE\n");
 			else
 				printf("%.10lf\n", res);
 
 		}
 
 	}
 	return 0;
 }