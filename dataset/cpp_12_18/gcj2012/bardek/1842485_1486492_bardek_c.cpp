#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 2001;
 int G[MAXN];
 #define END {printf("Impossible\n");return;}
 int H[MAXN];
 int F[MAXN];
 
 
 LL det(pii a, pii b, pii c) {return 1LL*a.x*b.y+1LL*b.x*c.y+1LL*c.x*a.y-
 								  ( 1LL*a.x*c.y+1LL*b.x*a.y+1LL*c.x*b.y);}
 inline bool lezy(int a, int b, int c) {return det(pii(a,H[a]),pii(b,H[b]),pii(c,H[c]))<=0;}
 int n;
 inline bool moge(int e,int h)
 {
 	H[e]=h;
 	for(int i=e+1;i<G[e];++i) if(lezy(e,i,G[i])) return 0;
 	return 1;
 }
 inline bool moge2(int e,int h)
 {
 	H[e]=h;
 	for(int i=G[e]+1;i<n;++i) if(!lezy(e,G[e],i)) return 0;
 	return 1;
 }
 
 
 
 int gorne(int e)
 {
 	if(moge(e,0)) return 0;
 	int p=0,k=H[G[e]];
 	//przy k na pewno widze
 	while(p+1<k) 
 	{
 		int m=(p+k)/2;
 		if(moge(e,m)) k=m;
 		else p=m;
 	}
 	return k;
 
 
 /*
 	int a=G[e]-e;
 	int b=G[G[i]]-G[i];
 	int c=H[G[G[i]]]-H[G[i]];
 	return (1LL*a*c)/b;*/
 }
 int dolne(int e)
 {
 	int p=0,k=H[G[e]]+1;
 	if(F[G[e]]!=e) k--;
 	if(!moge2(e,0)) return -1;
 	while(p+1<k)
 	{
 		int m=(p+k)/2;
 		if(moge2(e,m)) p=m;
 		else k=m;
 	}
 	return p;
 }
 void solve()
 {
 	scanf("%d",&n);
 	fru(i,n-1) scanf("%d",&G[i]);
 	fru(i,n) G[i]--;
 	fru(i,n-1) if(G[i]<=i) END
 	int inf=1000000000;
 	fru(i,n-1) for(int j=i+1;j<G[i];++j) if(G[j]>G[i]) END
 	H[n-1]=inf;
 	H[n]=inf;
 	G[n-1]=n;
 	fru(i,n) F[i]=-1;
 	fru(i,n) if(F[G[i]]==-1) F[G[i]]=i;
 	for(int i=n-2;i>=0;--i)
 	{
 		int upp=gorne(i);//min ktore moge
 		int dow=dolne(i);//max ktore moge
 //		printf("dla i = %d min = %d, max = %d\n",i,upp,dow);
 		if(upp>dow) END;
 		H[i]=dow;
 	}
 	fru(i,n) printf("%d ",H[i]); printf("\n");
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 solve();
 	}
     return 0;
 }
