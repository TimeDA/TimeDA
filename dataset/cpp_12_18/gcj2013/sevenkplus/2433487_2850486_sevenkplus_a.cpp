#include<cstdio>
 #include<algorithm>
 using namespace std;
 typedef long long ll;
 #define INF 10000000000000000
 #define N 40
 ll B,a[N];int n;
 int main()
 {
 	int _;scanf("%d",&_);
 	a[37]=INF;
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%I64d%d",&B,&n);
 		for(int i=0;i<37;i++)a[i]=0;
 		for(int i=0;i<n;i++)scanf("%I64d",a+i);
 		sort(a,a+37);
 		double S=0.0;
 		for(int i=1;i<=35;i++)
 			for(int j=i+1;j<=37;j++)
 			{
 				if(a[j]==a[j-1])continue;
 				ll s=0;
 				for(int k=0;k<i;k++)
 					s+=a[i-1]-a[k];
 				ll t=0;
 				for(int k=i;k<j;k++)
 					t+=a[j-1]-a[k];
 				ll ma=a[j-1]-a[i-1]-1;
 				ll mb=a[j]-a[j-1];
 				if(a[j-1]==a[i-1])ma++,mb--,t+=(j-i);
 				ll B1=B-s-t;
 				if(B1<0)continue;
 				S=max(S,s*36.0/i-s-t);
 				ll sa=min(ma,B1/i)*i;
 				S=max(S,(s+sa)*36.0/i-(s+sa)-t);
 				B1-=sa;
 				ll sb=min(mb,B1/j);
 				S=max(S,(s+sa+sb*i)*36.0/i-(s+sa+sb*i)-(t+sb*(j-i)));
 				B1-=sb*j;
 				//if(S>1){printf("%d %d %I64d %I64d %I64d %I64d\n",i,j,s,t,sa,sb);return 0;}
 			}
 		printf("Case #%d: %.9lf\n",__,S);
 	}
 	return 0;
 }