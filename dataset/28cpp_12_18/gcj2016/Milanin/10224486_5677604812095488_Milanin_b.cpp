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
 #define N 210
 double d[N][N], p[N], a[N];
 void sol()
 {
 	int n, l, i, j, k;
 	scanf("%d%d", &n, &k);
 	for(i=0; i<n; scanf("%lf", &p[i]), i++);
 	sort(p, p+n);
 	double r=0;
 	for(l=0; l<=k; l++)
 	{
 		for(i=0; i<l; a[i]=p[i], i++);
 		for(i=0; i<k-l; a[l+i]=p[n-1-i], i++);
 		for(i=0; i<=k; i++)
 			for(j=0; j<=k; d[i][j]=0, j++);
 		d[0][0]=1.0;
 		for(i=0; i<k; i++)
 			for(j=0; j<=i; d[i+1][j+1]+=a[i]*d[i][j], d[i+1][j]+=(1-a[i])*d[i][j], j++);
 		r=max(r, d[k][k/2]);
 	}
 	printf("%.13lf\n", r);
 }
 int main()
 {
 	int ts;
 	scanf("%d", &ts);
 	for(int t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		sol();
 	}
 	return 0;
 }