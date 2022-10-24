#include<cstdio>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 typedef long long ll;
 #define N 2010
 int n,a[N],b[N];
 void ff(int le,int p,double k)
 {
 	if(le>=p)return;
 	int w=-1;
 	for(int i=p-1;i>=le;i--)if(a[i]==p)w=i;
 	if(w==-1)return;
 	int la=le;
 	b[w]=(int)(b[p]-k*(p-w)-1);
 	for(int i=w+1;i<p;i++)
 		if(a[i]==p)b[i]=b[w],ff(la+1,i,(double)(b[p]-b[i])/(p-i)),la=i;
 	ff(le,w,(double)(b[p]-b[w])/(p-w));
 }
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d",&n);
 		for(int i=1;i<n;i++)scanf("%d",a+i);
 		bool F=1;
 		for(int i=1;i<n&&F;i++)
 			for(int j=i+1;j<a[i]&&F;j++)
 				if(a[j]>a[i])F=0;
 		if(!F){printf("Case #%d: Impossible\n",__);continue;}
 		memset(b,0,sizeof b),b[n]=1e9,ff(1,n,0);
 		for(int i=n-1;i>=1&&F;i--)
 		{
 			int p=i+1;
 			for(int j=i+2;j<=n;j++)
 				if((ll)(b[j]-b[i])*(p-i)>(ll)(b[p]-b[i])*(j-i))p=j;
 			if(p!=a[i])F=0;
 		}
 		if(!F)for(puts("NO");;);
 		printf("Case #%d: ",__);
 		for(int i=1;i<=n;i++)printf("%d%c",b[i],i==n?'\n':' ');
 	}
 	return 0;
 }
