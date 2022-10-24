#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define N 1010
 int n,w,h,a[N],p[N],wx[N],wy[N],px,py;
 bool cmp(int x,int y){return a[x]>a[y];}
 void chk(int x,int y,int z)
 {
 	if(x<0||y<0||x>w||y>h)return;
 	for(int i=1;i<z;i++)
 		if(max(abs(wx[p[i]]-x),abs(wy[p[i]]-y))<a[p[i]]+a[p[z]])return;
 	if(px==-1||(y<py||y==py&&x<px))px=x,py=y;
 }
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d%d%d",&n,&w,&h);
 		for(int i=1;i<=n;i++)scanf("%d",a+i),p[i]=i;
 		sort(p+1,p+n+1,cmp);
 		for(int i=1;i<=n;i++)
 		{
 			px=py=-1,chk(0,0,i);
 			for(int j=1;j<i;j++)
 				chk(wx[p[j]]+a[p[j]]+a[p[i]],wy[p[j]]-a[p[j]]+a[p[i]],i),
 				chk(wx[p[j]]-a[p[j]]+a[p[i]],wy[p[j]]+a[p[j]]+a[p[i]],i),
 				chk(wx[p[j]]+a[p[j]]+a[p[i]],0,i),
 				chk(0,wy[p[j]]+a[p[j]]+a[p[i]],i);
 			if(px==-1)for(puts("NO");;);
 			wx[p[i]]=px,wy[p[i]]=py;
 		}
 		printf("Case #%d: ",__);
 		for(int i=1;i<=n;i++)printf("%d %d%c",wx[i],wy[i],i==n?'\n':' ');
 	}
 	return 0;
 }
