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
 int T[MAXN];
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int n,X,ret=0;
 		 scanf("%d%d",&n,&X);
 		 fru(i,n) scanf("%d",&T[i]);
 		 sort(T,T+n);
 		 for(int i=n-1;i>=0;--i) if(T[i])
 		 {
 			 int s=T[i];
 			 T[i]=0;
 			 for(int j=i-1;j>=0;--j) if(T[j] && T[j]+s<=X)
 			 {
 				 T[j]=0;
 				 break;
 			 }
 			 ++ret;
 		 }
 		 printf("%d\n",ret);
 
 
 	}
     return 0;
 }
