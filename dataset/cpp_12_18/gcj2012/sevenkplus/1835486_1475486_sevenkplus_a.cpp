#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define N 1010
 int n,a[N],b[N],p[N];
 bool cmp(int x,int y){return a[x]*(10000-b[x]*b[y])+a[y]*(100-b[y])*100<a[y]*(10000-b[x]*b[y])+a[x]*(100-b[x])*100||a[x]*(10000-b[x]*b[y])+a[y]*(100-b[y])*100==a[y]*(10000-b[x]*b[y])+a[x]*(100-b[x])*100&&x<y;}
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d",&n);
 		for(int i=0;i<n;i++)scanf("%d",a+i);
 		for(int i=0;i<n;i++)scanf("%d",b+i),b[i]=100-b[i],p[i]=i;
 		sort(p,p+n,cmp);
 		printf("Case #%d: ",__);
 		for(int i=0;i<n;i++)printf("%d%c",p[i],i==n-1?'\n':' ');
 	}
 	return 0;
 }
