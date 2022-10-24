#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define INF 1000000007
 #define N 20
 #define M 20
 int n,m,p,px[M],py[M],pa[M],pb[M],pw[M];
 int a[N][N];bool v[M];
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d%d%d",&n,&m,&p);
 		for(int i=0;i<m;i++)scanf("%d%d%d%d",px+i,py+i,pa+i,pb+i),px[i]--,py[i]--;
 		for(int i=0;i<p;i++)scanf("%d",pw+i),pw[i]--;
 		for(int i=0;i<m;i++)v[i]=0;
 		for(int w=0;w<(1<<m);w++)
 		{
 			for(int i=0;i<n;i++)
 				for(int j=0;j<n;j++)a[i][j]=(i!=j)*INF;
 			for(int i=0;i<m;i++)
 				if((w>>i)&1)a[px[i]][py[i]]=min(a[px[i]][py[i]],pb[i]);else a[px[i]][py[i]]=min(a[px[i]][py[i]],pa[i]);
 			for(int k=0;k<n;k++)
 				for(int i=0;i<n;i++)
 					for(int j=0;j<n;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
 			for(int i=0;i<m;i++)
 				if((w>>i)&1)
 				{
 					if(a[0][px[i]]+pb[i]+a[py[i]][1]==a[0][1])v[i]=1;
 				}else
 				{
 					if(a[0][px[i]]+pa[i]+a[py[i]][1]==a[0][1])v[i]=1;
 				}
 		}
 		bool F=0;
 		printf("Case #%d: ",__);
 		for(int i=0;i<p;i++)
 			if(!v[pw[i]]){printf("%d\n",pw[i]+1);F=1;break;}
 		if(!F)puts("Looks Good To Me");
 	}
 	return 0;
 }