#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define N 110
 int n,a[N],w,p;
 int ff(int x){return (x+2)/3;}
 int gg(int x){return (x+4)/3;}
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d%d%d",&n,&w,&p);
 		for(int i=0;i<n;i++)scanf("%d",a+i);
 		sort(a,a+n);
 		int S=0;
 		for(int i=0;i<=n-w;i++)
 		{
 			bool F=1;
 			for(int j=i;j<i+w;j++)if(a[j]<2||a[j]>28){F=0;break;}
 			if(!F)continue;
 			int T=0;
 			for(int j=0;j<n;j++)if(i<=j&&j<i+w)T+=(gg(a[j])>=p);else T+=(ff(a[j])>=p);
 			S=max(S,T);
 		}
 		printf("Case #%d: %d\n",__,S);
 	}
 	return 0;
 }
