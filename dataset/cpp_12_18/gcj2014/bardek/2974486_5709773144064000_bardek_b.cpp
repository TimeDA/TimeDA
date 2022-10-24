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
 typedef double D;
 D C,F,X;
 
 const int MAXN = 1001;
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 scanf("%lf %lf %lf\n",&C,&F,&X);
 		 D ret=X/2.;
 		 D sum=0.;
 		 fru(i,10000000)
 		 {
 			 if(ret<sum) break;
 			 ret=min(ret,sum+X/(2+i*F));
 			 sum+=C/(2.+i*F);
 		 }
 		 printf("%.7lf\n",ret);
 	}
     return 0;
 }
