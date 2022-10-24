#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define frp(j,n) for(int j=1;j<=n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 103;
 bool Q[31][2]; //0 -czy jest ok gdy nie surp 1 - gdy  sur
 int D[MAXN][MAXN];
 int n,s,p;
 int T[MAXN];
 int brut()
 {
 	int ret=0;
 	fru(i,1<<n) if(__builtin_popcount(i)==s)
 	{
 		int t=0;
 		fru(j,n) if((1<<j)&i) 
 		{
 			t+=Q[T[j]][1];
 			if(T[j]<2) t-=1000;
 		}
 		else t+=Q[T[j]][0];
 		ret=max(ret,t);
 	}
 	return ret;
 }
 
 int solve()
 {
 	scanf("%d%d%d",&n,&s,&p);
 	fru(i,31) fru(j,2) Q[i][j]=0;
 	for(int i=p;i<=10;++i) fru(j,i+1) fru(k,j+1)
 	{
 		if(k+1>=i) Q[i+j+k][0]=1;
 		if(k+2==i) Q[i+j+k][1]=1;
 	}
 	fru(i,n+1) fru(j,n+1) D[i][j]=-2*MAXN;
 	D[0][0]=0;
 //	printf("\n");
 	frp(i,n)
 	{
 		int a;
 		scanf("%d",&a);
 		T[i-1]=a;
 		fru(j,s+1) D[i][j]=D[i-1][j];
 		if(Q[a][0]) fru(j,s+1) D[i][j]++;
 		if(a>=2) fru(j,s) D[i][j+1]=max(D[i][j+1],D[i-1][j]+Q[a][1]);
 //		fru(j,s+1) printf("%d ",D[i][j]); printf("\n");
 	}
 //	printf("brut : %d\n",brut());
 //	if(brut()!=max(D[n][s],0)) exit(0);
 	return max(D[n][s],0);
 }
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 printf("%d\n",solve());
 	}
     return 0;
 }
