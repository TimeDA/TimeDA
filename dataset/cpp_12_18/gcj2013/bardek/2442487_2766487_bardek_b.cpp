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
 int n;
 
 LL licz0(LL a)
 {
 	a=(1LL<<n)-a;
 	int ile=0;
 	for(int i=n-1;i>=0;--i)
 	{
 		if(a&(1LL<<i)) break;
 		else ++ile;
 	}
 	return (2LL<<ile)-2;
 }
 LL licz1(LL a)
 {
 	int ile=0;
 	a=(1LL<<n)-a-1;
 //	printf("a = %lld\n",a);
 	for(int i=n-1;i>=0;--i)
 	{
 		if((a&(1LL<<i))) ++ile;
 		else break;
 	}
 //printf("ile = %d\n",ile);
 	return (1LL<<n)-(2LL<<ile);
 }
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 LL p;
 		 scanf("%d %lld\n",&n,&p);
 		 if(p==(1LL<<n))
 		 {
 			 printf("%lld %lld\n",(1LL<<n)-1,(1LL<<n)-1);
 		 }
 		 else
 		 {
 //		 printf(":: %d %lld\n",n,p);
 		 LL wyn1=licz0(p);
 		 LL wyn2=licz1(p);
 		 printf("%lld %lld\n",wyn1,wyn2);
 		 }
 	}
     return 0;
 }
