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
 
 double d[201][101];
 double p[201],ans,q[201];
 int i,j,k,l,m,n,T,ts;
 
 int main()
 {
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d",&n,&k);
 		for(i=0;i<n;i++)
 			scanf("%lf",&q[i]);
 		sort(q,q+n);
 		ans=0;
 		k/=2;
 		for(i=0;i<2*k;i++)
 			p[i]=q[i];
 		for(i=0;i<=2*k;i++)
 		{
 			for(j=0;j<=k;j++)
 				d[0][j]=0;
 			d[0][0]=1;
 			for(j=1;j<=2*k;j++)
 				for(l=0;l<=j && l<=k;l++)
 				{
 					d[j][l]=0;
 					if(l)
 						d[j][l]+=d[j-1][l-1]*p[j-1];
 					if(l<j)
 						d[j][l]+=d[j-1][l]*(1-p[j-1]);
 				}
 			ans=max(ans,d[2*k][k]);
 			if(i<2*k)
 				p[2*k-1-i]=q[n-1-i];
 		}
 		printf("Case #%d: %.12lf\n",ts,ans);
 	}
 	return 0;
 }