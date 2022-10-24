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
 #include <fstream>
 using namespace std;
 const int N=50;
 double p[N];
 void solve()
 {
 	int n, k;
 	double u;
 	scanf("%d%d%lf", &n, &k, &u);
 	for(int i=0; i<n; scanf("%lf", &p[i]), i++);
 	double l=0, r=1, c;
 	for(int j=0; j<100; j++)
 	{
 		c=(l+r)/2;
 		double x=u;
 		for(int i=0; i<n; i++)
 			if(p[i]<c) x-=c-p[i];
 		if(x>0) l=c;
 		else r=c;
 	}
 	double x=1;
 	for(int i=0; i<n; x*=max(r, p[i]), i++);
 	printf("%.10lf\n", x);
 }
 int main()
 {
 	int ts;
 	scanf("%d", &ts);
 	for(int t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		solve();
 	}
 	return 0;
 }