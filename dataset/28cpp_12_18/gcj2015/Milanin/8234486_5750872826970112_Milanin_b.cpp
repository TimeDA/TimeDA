#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 using namespace std;
 void solve()
 {
 	int n;
 	double a, v, t, r0, r1, t0, t1;
 	scanf("%d%lf%lf", &n, &v, &t);
 	if(n==1)
 	{
 		scanf("%lf%lf", &r0, &t0);
 		if(fabs(t-t0)<1E-7) a=v/r0;
 		else a=-10;
 	}
 	else
 	{
 		scanf("%lf%lf", &r0, &t0);
 		scanf("%lf%lf", &r1, &t1);
 		if(fabs(t0-t1)<1E-7)
 		{
 			r0+=r1;
 			if(fabs(t-t0)<1E-7) a=v/r0;
 			else a=-10;
 		}
 		else
 		{
 			if(t+1E-7<min(t0, t1) || t-1E-7>max(t0, t1)) a=-10;
 			else
 			{
 				double x1=(v*t-v*t0)/(t1-t0);
 				double x0=v-x1;
 				a=max(x0/r0, x1/r1);
 			}
 		}
 	}
 	if(a<-1) printf("IMPOSSIBLE\n");
 	else printf("%.13lf\n", a);
 }
 int main()
 {
 	int tst;
 	scanf("%d", &tst);
 	for(int ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		solve();
 	}
 	return 0;
 }