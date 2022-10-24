#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 int T,n,ans,i,j,ts;
 double a[2000],b[2000];
 
 int main()
 {
 	freopen("d.in","r",stdin);
 	freopen("d.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		ans=0;
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 			scanf("%lf",&a[i]);
 		for(i=0;i<n;i++)
 			scanf("%lf",&b[i]);
 		sort(a,a+n);
 		sort(b,b+n);
 		j=0;
 		for(i=0;i<n;i++)
 			if(a[i]>b[j])
 			{
 				ans++;
 				j++;
 			}
 		printf("Case #%d: %d",++ts,ans);
 		j=0;
 		for(i=0;i<n;i++)
 		{
 			for(;j<n && b[j]<a[i];j++);
 			if(j==n)break;
 			j++;
 		}
 		printf(" %d\n",n-i);
 	}
 	return 0;
 }
