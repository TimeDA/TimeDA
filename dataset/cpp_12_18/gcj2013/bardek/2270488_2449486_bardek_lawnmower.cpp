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
 
 const int MAXN = 103;
 
 int T[MAXN][MAXN],W[MAXN],K[MAXN];
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int n,m;
 		 scanf("%d%d",&n,&m);
 		 fru(i,n) fru(j,m) scanf("%d",&T[i][j]);
 		 fru(i,n) W[i]=0;
 		 fru(j,m) K[j]=0;
 		 fru(i,n) fru(j,m)
 		 {
 			 W[i]=max(W[i],T[i][j]);
 			 K[j]=max(K[j],T[i][j]);
 		 }
 		 bool ok=1;
 		 fru(i,n) fru(j,m) if(T[i][j]!=min(W[i],K[j])) ok=0;
 		 printf("%s\n",ok?"YES":"NO");
 	}
     return 0;
 }
