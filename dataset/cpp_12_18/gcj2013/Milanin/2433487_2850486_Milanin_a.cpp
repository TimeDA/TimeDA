#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 100
 int n;
 long long a[N], v[N];
 double cost()
 {
 	int i, l;
 	double x;
 	x=0;
 	for(i=0; i+1<n && a[i+1]+v[i+1]==a[i]+v[i]; i++);
 	for(l=i+1; i>=0; x+=v[i]*36, i--);
 	x/=l;
 	for(i=0; i<n; x-=v[i], i++);
 	return x;
 }
 int main()
 {
 	int i, j, k, l;
 	int ts, tst;
 	long long b, x;
 	double r;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		n=37;
 		for(i=0; i<n; a[i]=0, i++);
 		for(scanf("%lld%d", &b, &k), i=0; i<k; scanf("%lld", &a[i]), i++);
 		sort(a, a+n);
 		r=0;
 		if(n==1) printf("0.0\n");
 		else
 		{
 			for(k=1; k<n; k++)
 			{
 				x=b;
 				for(i=0; i<k; x-=a[k-1]-a[i], i++);
 				if(x<0) continue;
 				if(x<=(a[k]-1-a[k-1])*i)
 				{
 					for(i=0; i<k; v[i]=a[k-1]+x/k-a[i], i++);
 					for(; i<n; v[i]=0, i++);
 					r=max(r, cost());
 				}
 				else
 				{
 					if(a[k-1]==a[k])
 					{
 						for(j=0; j<k; v[j]=a[k]-a[j], x-=a[k]-a[j], j++);
 						for(j=k; j<n && a[j]==a[k]; v[j]=1, x--, j++);
 						for(; j<n; v[j]=0, j++);
 						if(x<0) continue;
 					}
 					else
 					{
 						for(i=0; i<k; v[i]=a[k]-1-a[i], x-=a[k]-1-a[i], i++);
 						for(; i<n; v[i]=0, i++);
 					}
 					r=max(r, cost());
 					j=k;
 					for(; ; )
 					{
 						for(j++; j<n && a[j]==a[j-1]; j++);
 						if(j<n)
 						{
 							if(x/j<=a[j]+v[j]-a[j-1]-v[j-1])
 							{
 								for(l=0; l<j; v[l]+=x/j, l++);
 								r=max(r, cost());
 								break;
 							}
 							else
 							{
 								for(l=0; l<j; v[l]+=a[j]+v[j]-a[j-1]-v[j-1], x-=a[j]+v[j]-a[j-1]-v[j-1], l++);
 								r=max(r, cost());
 							}
 						}
 						else break;
 					}
 				}
 			}
 			printf("%.13lf\n", r);
 		}
 	}
 	return 0;
 }