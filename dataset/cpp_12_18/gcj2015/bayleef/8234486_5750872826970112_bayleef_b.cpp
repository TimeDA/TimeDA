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
 
 int n,i,j,k,T,ts;
 long long v,x,r[10],c[10],d1,d2,d;
 
 int main()
 {
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%lld.%d%lld.%d",&n,&v,&i,&x,&j);
 		v=v*10000+i;
 		x=x*10000+j;
 		for(i=0;i<n;i++)
 		{
 			scanf("%lld.%d%lld.%d",&r[i],&j,&c[i],&k);
 			r[i]=r[i]*10000+j;
 			c[i]=c[i]*10000+k;
 		}
 		if(n==1)
 		{
 			if(c[0]==x)
 				printf("Case #%d: %.12lf\n",++ts,1.0*v/r[0]);
 			else
 				printf("Case #%d: IMPOSSIBLE\n",++ts);
 			continue;
 		}
 		if(c[0]==x && c[1]==x)
 		{
 			printf("Case #%d: %.12lf\n",++ts,1.0*v/(r[0]+r[1]));
 			continue;
 		}
 		if(c[0]==c[1])
 		{
 			printf("Case #%d: IMPOSSIBLE\n",++ts);
 			continue;
 		}
 		d=c[1]-c[0];
 		d1=v*(c[1]-x);
 		d2=v*(x-c[0]);
 		if(d<0)
 		{
 			d=-d;
 			d1=-d1;
 			d2=-d2;
 		}
 		if(d1<0 || d2<0)
 		{
 			printf("Case #%d: IMPOSSIBLE\n",++ts);
 			continue;
 		}
 		printf("Case #%d: %.12lf\n",++ts,max(1.0*d1/d/r[0],1.0*d2/d/r[1]));
 	}
 	return 0;
 }
 /*
 5
 1 10.0000 50.0000
 0.2000 50.0000
 2 30.0000 65.4321
 0.0001 50.0000
 100.0000 99.9000
 2 5.0000 99.9000
 30.0000 99.8999
 20.0000 99.7000
 2 0.0001 77.2831
 0.0001 97.3911
 0.0001 57.1751
 2 100.0000 75.6127
 70.0263 75.6127
 27.0364 27.7990
 */