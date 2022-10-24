#define _USE_MATH_DEFINES
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <queue>
 #include <map>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 int main()
 {
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	int T,ts,i,j,n,sta,fin,q;
 	long long e[200];
 	int s[200];
 	long long d[200][200],dist;
 	double ans[200];
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d",&n,&q);
 		for(i=0;i<n;i++)
 			scanf("%lld%d",&e[i],&s[i]);
 		for(i=0;i<n;i++)
 			for(j=0;j<n;j++)
 				scanf("%lld",&d[i][j]);
 		printf("Case #%d:",ts);
 		while(q--)
 		{
 			scanf("%d%d",&sta,&fin);
 			sta--;
 			fin--;
 
 			//small
 			ans[0]=0;
 			for(i=1;i<n;i++)
 			{
 				dist=0;
 				ans[i]=1E18;
 				for(j=i-1;j>=0;j--)
 				{
 					dist+=d[j][j+1];
 					if(e[j]>=dist)
 						ans[i]=min(ans[i],ans[j]+1.0*dist/s[j]);
 				}
 			}
 			printf(" %.12lf",ans[n-1]);
 		}
 		puts("");
 	}
 	return 0;
 }