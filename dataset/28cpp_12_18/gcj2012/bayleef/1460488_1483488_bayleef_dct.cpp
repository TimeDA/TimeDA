#include <stdio.h>
 
 int T,p10[10],ans,a,b,n,m,l,ts;
 
 int main()
 {
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	p10[0]=1;
 	for(l=1;l<10;l++)
 		p10[l]=p10[l-1]*10;
 	while(T--)
 	{
 		scanf("%d%d",&a,&b);
 		ans=0;
 		for(n=a;n<=b;n++)
 		{
 			m=n;
 			l=0;
 			while(m)
 			{
 				m/=10;
 				l++;
 			}
 			m=n;
 			do
 			{
 				if(m>n && m<=b)
 					ans++;
 				m=(m%10)*p10[l-1]+m/10;
 			}
 			while(m!=n);
 		}
 		printf("Case #%d: %d\n",++ts,ans);
 	}
 	return 0;
 }