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
 
 const int MAXN = 1000006;
 
 //LL SP[MAXN];
 int T[MAXN];
 int n;
 bool dasie(LL s)
 {
 	int q=0;
 	LL t=0;
 	fru(i,n)
 	{
 		if(T[i]>s) return 0;
 		if(T[i]+t>s)
 		{
 			++q;
 			t=T[i];
 		}
 		else t+=T[i];
 	}
 	return q<=2;
 }
 
 
 D solve()
 {
 	int p,q,r,s;
 	scanf("%d%d%d%d%d",&n,&p,&q,&r,&s);
 	fru(i,n) T[i]=(1LL*i*p+q)%r+s;
 	//fru(i,n) SP[i]=T[i]+(i?SP[i-1]:0);
 	LL sum=0;
 	fru(i,n) sum+=T[i];
 	LL pocz=0,kon=sum;
 	while(pocz+1<kon)
 	{
 		LL m=(pocz+kon)/2;
 		if(dasie(m)) kon=m;
 		else pocz=m;
 	}
 	return 1.0*(sum-kon)/sum;	
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 printf("%.9lf\n",solve());
 	}
     return 0;
 }
