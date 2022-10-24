#include<cstdio>
 #include<algorithm>
 using namespace std;
 typedef long long ll;
 #define P 1000002013
 #define N 1010
 int n,px[N],py[N],pz[N],p[N*2],L,st[N],sp[N],sn;
 bool cmp(int x,int y)
 {
 	int tx,ty;
 	if(x<0)tx=py[-x-1];else tx=px[x];
 	if(y<0)ty=py[-y-1];else ty=px[y];
 	if(tx!=ty)return tx<ty;
 	return x>y;
 }
 int main()
 {
 	int _;scanf("%d",&_);int wy;
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d%d",&wy,&n);L=0;
 		int S=0,T=0;
 		for(int i=0;i<n;i++)
 			scanf("%d%d%d",px+i,py+i,pz+i),p[L++]=i,p[L++]=-i-1;
 		for(int i=0;i<n;i++)
 			(T+=(ll)(py[i]-px[i])*(py[i]-px[i]-1)/2%P*pz[i]%P)%=P;
 		sort(p,p+L,cmp);
 		sn=0;
 		for(int i=0;i<L;i++)
 		{
 			int x=p[i];int y;
 			if(x<0)y=-x-1;else y=x;
 			if(x>=0)
 			{
 				st[sn]=px[y];sp[sn]=pz[y];
 				sn++;
 			}else
 			{
 				int w=pz[y];
 				while(w>0)
 				{
 					int s=min(sp[sn-1],w);
 					w-=s,sp[sn-1]-=s;
 					(S+=(ll)(py[y]-st[sn-1])*(py[y]-st[sn-1]-1)/2%P*s%P)%=P;
 					if(sp[sn-1]==0)sn--;
 				}
 			}
 		}
 		S-=T;S%=P;S+=P;S%=P;
 		printf("Case #%d: %d\n",__,S);
 	}
 	return 0;
 }
