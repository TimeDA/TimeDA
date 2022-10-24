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
 
 using namespace std;
 
 long long a[100],b,cur,sum;
 int T,n,i,j,k,m,ts;
 double ans,x;
 
 void check(long long cur,long long sum,int m)
 {
 	double x=0;
 	for(i=0;i<m;i++)
 		if(sum>=a[i])
 			x+=sum-a[i];
 		else break;
 	x*=36;
 	x/=i;
 	if(x-cur>ans)
 		ans=x-cur;
 }
 
 int main()
 {
 	freopen("a.in","r",stdin);	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%lld%d",&b,&n);
 		for(i=0;i<n;i++)
 			scanf("%lld",&a[i]);
 		for(;n<37;n++)
 			a[n]=0;
 		sort(a,a+n);
 		ans=0;
 		sum=0;
 		for(m=n-1;m;m--)
 		{
 			cur=0;
 			for(i=0;i<m;i++)
 				cur+=a[m-1]-a[i];
 			for(j=m;j<n;j++)
 				if(a[j]<=a[m-1])
 					cur+=a[m-1]+1-a[j];
 				else
 					break;
 			if(cur>b)
 				continue;
 			sum=a[m-1];
 			check(cur,sum,m);
 			while(j<n)
 			{
 				if((b-cur)/j+sum<a[j])
 				{
 					sum+=(b-cur)/j;
 					cur+=(b-cur)/j*j;
 					check(cur,sum,m);
 					break;
 				}
 				cur+=(a[j]-sum)*j;
 				for(k=j;k<n;k++)
 					if(a[j]!=a[k])
 						break;
 				if(cur+k-j>b)break;
 				cur+=k-j;
 				sum=a[j];
 				j=k;
 				check(cur,sum,m);
 			}
 		}
 		printf("Case #%d: %.12lf\n",++ts,ans);
 	}
 	return 0;
 }