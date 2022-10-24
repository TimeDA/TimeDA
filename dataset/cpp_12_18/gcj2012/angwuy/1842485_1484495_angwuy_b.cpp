#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std ;
 
 const int MAXN = 1010;
 
 int n;
 double x, y;
 double a[1010];
 
 void init()
 {
 	scanf("%d %lf %lf", &n, &x, &y);
 	for (int i = 0; i < n; ++i)
 		scanf("%lf", &a[i]);
 }
 
 void solve()
 {
 	printf("%.10lf %.10lf", 0.0, 0.0);
 	int i, j;
 	double t = a[0], l = 0, r = 0;
 	double z = ((x > y) ? x : y);
 	
 	for (i = 1; i < n; ++i)
 	if (t < a[i])
 		t = a[i];
 	for (i = 1; i < n; ++i)
 	{
 		l += a[i - 1] + a[i];
 		if (l > z)
 		{
 			l = 0;
 			r += t * 2;
 		}
 		if (x >= y)
 			printf(" %.10lf %.10lf", l, r);
 		else
 			printf(" %.10lf %.10lf", r, l);
 	}
 	printf("\n");
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	int ii, tt;
 	scanf("%d", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		init();
 		solve();
 	}
 	return 0;
 }
