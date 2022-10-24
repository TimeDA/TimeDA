#include <stdio.h>
 #include <math.h>
 #include <iostream>
 #include <sstream>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <vector>
 #include <set>
 #include <algorithm>
 #include <map>
 #include <queue>
 #include <string>
 
 using namespace std;
 
 int a[2000],h[2000],i,j,n,T,ts,p[2000],per,v[2000],k;
 
 int main()
 {
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d",&n);
 		for(i=0;i<n-1;i++)
 		{
 			scanf("%d",&a[i]);
 			a[i]--;
 		}
 		for(i=0;i<n-1;i++)
 		{
 			for(j=i+1;j<a[i];j++)
 				if(a[j]>a[i])
 					break;
 			if(j<a[i])
 				break;
 		}
 		if(i<n-1)
 		{
 			printf("Case #%d: Impossible\n",++ts);
 			continue;
 		}
 		memset(h,0,sizeof(h));
 		memset(p,0,sizeof(p));
 		for(i=0;i<n-1;i=a[i])
 			h[i]=1000000000;
 		h[n-1]=1000000000;
 		for(i=1;i<n;i++)
 			if(!h[i])
 			{
 				k=0;
 				for(j=i;!h[j];j=a[j])
 					v[k++]=j;
 				v[k]=j;
 				p[j]++;
 				per=p[j];
 				for(j=k-1;j>=0;j--)
 				{
 					h[v[j]]=h[v[j+1]]-(v[j+1]-v[j])*per;
 					p[v[j]]=per;
 				}
 			}
 		for(i=0;i<n-1;i++)
 		{
 			for(j=i+1;j<a[i];j++)
 				if((long long)(j-i)*(h[a[i]]-h[i])<=(long long)(h[j]-h[i])*(a[i]-i))
 					break;
 			if(j!=a[i])
 			{
 				printf("%d sees %d not %d\n",i,j,a[i]);
 				break;
 			}
 			for(j=a[i]+1;j<n;j++)
 				if((long long)(j-i)*(h[a[i]]-h[i])<(long long)(h[j]-h[i])*(a[i]-i))
 					break;
 			if(j!=n)
 			{
 				printf("%d sees %d not %d\n",i,j,a[i]);
 				break;
 			}
 		}
 		printf("Case #%d:",++ts);
 		for(i=0;i<n;i++)
 			printf(" %d",h[i]);
 		printf("\n");
 	}
 	return 0;
 }