#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 20
 char s[N];
 int h[N];
 double d[1<<N], p[1<<N];
 int main()
 {
 	int i, j, k, n, l, v;
 	int ts, tst;
 	double r;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		for(scanf("%s", s), n=0; s[n]; n++);
 		for(i=0; i<(1<<n); d[i]=0, p[i]=0, i++);
 		r=0;
 		for(i=0; i<(1<<n)-1; i++)
 		{
 			for(j=0; j<n; j++)
 				if(!((i>>j)&1) && s[j]=='X') break;
 			if(j<n) continue;
 			for(j=0; j<n; j++)
 				if(((i>>j)&1) != (s[j]=='X')) break;
 			if(j==n) p[i]=1;
 			
 			for(j=0; j<n; h[j]=0, j++);
 			v=0;
 			for(j=0; j<n; j++)
 			{
 				if((i>>j)&1)
 				{
 					k=-1;
 					for(l=j+1; l<2*n; l++)
 						if(!((i>>(l%n))&1)) break;
 					h[l%n]++;
 					v+=n-l+j;
 				}
 				else { h[j]++; v+=n; }
 			}
 			r+=v*p[i]/n;
 			for(j=0; j<n; j++)
 				if(h[j])
 				{
 					k=i^(1<<j);
 					p[k]+=p[i]*h[j]/n;
 				}
 		}
 		printf("%.13lf\n", r);
 	}
 	return 0;
 }