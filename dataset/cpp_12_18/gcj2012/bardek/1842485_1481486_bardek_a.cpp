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
 
 const int MAXN = 10004;
 
 int P[MAXN];
 int X[MAXN],L[MAXN];
 int n,d;
 bool solve()
 {
 	scanf("%d",&n);
 	fru(i,n) scanf("%d%d",&X[i],&L[i]);
 	scanf("%d",&d);
 	fru(i,n) P[i]=0;
 	P[0]=X[0];
 	fru(i,n)
 	{
 		int e=P[i];
 		if(X[i]+e>=d) return 1;
 		for(int j=i+1;j<n;++j) if(X[j]-X[i]<=e) P[j]=max(P[j],min(L[j],X[j]-X[i]));
 	}
 	return 0;
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 printf("%s\n",solve()?"YES":"NO");
 	}
     return 0;
 }
