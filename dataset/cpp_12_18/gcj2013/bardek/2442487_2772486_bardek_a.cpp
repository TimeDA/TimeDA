#include <cstdio>
 #include <algorithm>
 #include <cassert>
 #include <vector>
 #include <queue>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 1001,mod=1000002013;
 
 typedef pair<int,pii> LUD;
 
 int N;
 
 LUD T[MAXN*2];
 
 priority_queue<pii> PQ;
 
 int licz(int a, int b)
 {
 	int k=(b-a);
 	int w=(1LL*N*k)%mod;
 	int y=((1LL*k*(k-1))/2)%mod;
 	if(w>=y) return w-y;
 	return w-y+mod;
 }
 
 int solve()
 {
 	int n;
 	scanf("%d%d",&N,&n);
 	int koszt=0;
 	int qs=0;
 	fru(i,n) 
 	{
 		int p,k,d;
 		scanf("%d%d%d",&p,&k,&d);
 		int t=(1LL*licz(p,k)*d)%mod;
 		koszt=(koszt+t)%mod;
 		T[qs++]=LUD(p,pii(0,d));
 		T[qs++]=LUD(k,pii(1,d));
 	}
 	sort(T,T+qs);
 	int mojk=0;
 	fru(i,qs)
 	{
 		if(T[i].y.x==0)
 		{
 			PQ.push(pii(T[i].x,T[i].y.y));
 		}
 		else
 		{
 			int teraz=T[i].x,ile=T[i].y.y;
 			while(ile)
 			{
 				assert(!PQ.empty());
 				pii t=PQ.top();
 				PQ.pop();
 				int d=min(ile,t.y);
 				ile-=d;
 				t.y-=d;
 				if(t.y) PQ.push(t);
 				int cen=(1LL*d*licz(t.x,teraz))%mod;
 				mojk=(mojk+cen)%mod;
 			}
 		}
 	}
 	assert(PQ.empty());
 	int ans=koszt-mojk;
 	return ans>=0?ans:ans+mod;
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
