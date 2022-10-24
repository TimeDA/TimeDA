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
 
 int T,n,i,m,j,k,ts,l;
 int a[100];
 double p[2000000],ans;
 char s[100];
 
 int main()
 {
 	freopen("d.in","r",stdin);
 	freopen("d.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%s",&s);
 		m=0;
 		for(n=0;s[n];n++)
 			if(s[n]=='X')
 				m|=1<<n;
 		for(i=0;i<1<<n;i++)
 			p[i]=0;
 		p[m]=1;
 		ans=0;
 		for(i=m;i<(1<<n)-1;i++)
 		{
 			if((i&m)!=m)continue;
 			k=0;
 			for(j=0;j<n;j++)
 				if(!(i>>j&1))
 					a[k++]=j;
 			a[k]=a[0]+n;
 			l=0;
 			for(j=1;j<=k;j++)
 			{
 				p[i|1<<a[j]%n]+=p[i]*(a[j]-a[j-1])/n;
 				l+=(a[j]-a[j-1])*(a[j]-a[j-1]-1)/2;
 			}
 			ans+=p[i]*(n-1.0*l/n);
 		}
 		printf("Case #%d: %.12lf\n",++ts,ans);
 	}
 	return 0;
 }