#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 #define N 1010
 #define eps 1E-2
 using namespace std;
 int r[N], u[N];
 double x[N], y[N];
 bool cmp(int i, int j) { return r[i]>r[j]; }
 int main()
 {
 	int ts, tst, w, l, n, i;
 	double X, Y;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d:", ts);
 		for(scanf("%d%d%d", &n, &w, &l), i=0; i<n; scanf("%d", &r[i]), u[i]=i, i++);
 		sort(u, u+n, cmp);
 		for(Y=-r[0], X=w+1, i=0; i<n; i++)
 		{
 			X+=r[u[i]];
 			if(X+eps<w)
 			{ 
 				x[u[i]]=X;
 				X+=r[u[i]]+eps;
 				y[u[i]]=y[u[i-1]];
 			}
 			else
 			{
 				Y+=r[u[i]];
 				X=0;
 				x[u[i]]=X;
 				X+=r[u[i]]+eps;
 				y[u[i]]=Y;
 				Y+=r[u[i]]+eps;
 			}
 		}
 		for(i=0; i<n; printf(" %.4lf %.4lf", x[i], y[i]), i++);
 		printf("\n");
 	}
 	return 0;
 }