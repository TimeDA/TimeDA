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
 
 const int MAXN = 1001;
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int n;
 		 scanf("%d",&n);
 		 int A[n];
 		 fru(i,n) scanf("%d",&A[i]);
 		 int ret=12345;
 		 for(int c=1;c<=1000;++c){
 			 int q=0;
 			 fru(i,n) q+=(A[i]-1)/c;
 			 ret=min(ret,q+c);
 		 }
 		 printf("%d\n",ret);
 	}
     return 0;
 }
