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
 
 const int MAXN = 1005;
 int ALL[MAXN],T[MAXN];
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int n,ret=0;
 		 scanf("%d",&n);
 		 fru(i,n) scanf("%d",&T[i]);
 		 fru(i,n) ALL[i]=T[i];
 		 sort(ALL,ALL+n);
 		 fru(i,n) 
 		 {
 			 int ja=ALL[i];
 			 int wcz=0;
 			 fru(j,n) if(T[j]==ja) break;
 			 else if(T[j]>ja) ++wcz;
 			 ret+=min(wcz,n-i-1-wcz);
 		 }
 		 printf("%d\n",ret);
 	}
     return 0;
 }
