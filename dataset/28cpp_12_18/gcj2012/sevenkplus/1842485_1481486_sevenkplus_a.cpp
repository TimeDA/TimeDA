#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define N 10010
 int f[N],n,a[N],b[N];
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d",&n);
 		for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i),f[i]=0;
 		f[1]=a[1];
 		for(int i=1;i<n;i++)
 			for(int j=i+1;j<=n;j++)
 				if(a[j]-a[i]<=f[i])
 					f[j]=max(f[j],min(a[j]-a[i],b[j]));
 		int p;scanf("%d",&p);bool F=0;
 		for(int i=1;i<=n;i++)if(a[i]+f[i]>=p)F=1;
 		printf("Case #%d: %s\n",__,F?"YES":"NO");
 	}
 	return 0;
 }
