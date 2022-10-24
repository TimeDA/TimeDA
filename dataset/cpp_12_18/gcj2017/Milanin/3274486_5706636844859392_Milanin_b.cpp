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
 const int N=1440;
 int d[N+1][N+1][2], a[N], b[N];
 void solve()
 {
 	for(int i=0; i<N; a[i]=0, b[i]=0, i++);
 	int na, nb;
 	scanf("%d%d", &na, &nb);
 	for(; na--; )
 	{
 		int i, j;
 		scanf("%d%d", &i, &j);
 		for(; i<j; a[i]=1, i++);
 	}
 	for(; nb--; )
 	{
 		int i, j;
 		scanf("%d%d", &i, &j);
 		for(; i<j; b[i]=1, i++);
 	}
 	int ans=N;
 	for(int i=0; i<=N; i++)
 		for(int j=0; j<=N; d[i][j][0]=N, d[i][j][1]=N, j++);
 	d[0][0][0]=0;
 	for(int i=0; i<N; i++)
 		for(int j=0; j<=N; j++)
 		{
 			if(!a[i])
 			{
 				d[i+1][j+1][0]=min(d[i+1][j+1][0], d[i][j][0]);
 				d[i+1][j+1][0]=min(d[i+1][j+1][0], d[i][j][1]+1);
 			}
 			if(!b[i])
 			{
 				d[i+1][j][1]=min(d[i+1][j][1], d[i][j][0]+1);
 				d[i+1][j][1]=min(d[i+1][j][1], d[i][j][1]);
 			}
 		}
 	ans=min(ans, d[N][N/2][0]);
 	for(int i=0; i<=N; i++)
 		for(int j=0; j<=N; d[i][j][0]=N, d[i][j][1]=N, j++);
 	d[0][0][1]=0;
 	for(int i=0; i<N; i++)
 		for(int j=0; j<=N; j++)
 		{
 			if(!a[i])
 			{
 				d[i+1][j+1][0]=min(d[i+1][j+1][0], d[i][j][0]);
 				d[i+1][j+1][0]=min(d[i+1][j+1][0], d[i][j][1]+1);
 			}
 			if(!b[i])
 			{
 				d[i+1][j][1]=min(d[i+1][j][1], d[i][j][0]+1);
 				d[i+1][j][1]=min(d[i+1][j][1], d[i][j][1]);
 			}
 		}
 	ans=min(ans, d[N][N/2][1]);
 	printf("%d\n", ans);
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