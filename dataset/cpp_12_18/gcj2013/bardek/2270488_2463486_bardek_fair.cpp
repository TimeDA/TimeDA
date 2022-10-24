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
 vector<LL> PAL;
 
 
 bool pal(LL t)
 {
 	vector<int> V,E;
 	while(t) 
 	{
 		V.push_back(t%10);
 		t/=10;
 	}
 	E=V;
 	reverse(E.begin(),E.end());
 	return E==V;	
 }
 
 int main()
 {
 	for(int i=1;i<=10000000;i++)
 	{
 		LL t=1LL*i*i;
 		if(pal(1LL*i) && pal(t)) PAL.push_back(t);
 	}
 //	printf("all = %d\n",PAL.size());
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		LL a,b;
 		scanf("%lld %lld",&a,&b);
 		int ret=0;
 		tr(it,PAL) if(*it>=a && *it<=b) ++ret;
 		 printf("Case #%d: %d\n",oo+1,ret);
 	}
     return 0;
 }
