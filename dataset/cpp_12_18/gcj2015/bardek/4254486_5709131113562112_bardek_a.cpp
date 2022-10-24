#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(typeof ((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
 #define x first
 #define y second
 #define pb push_back
 #define ALL(G) (G).begin(),(G).end()
 
 #if 1
 	#define DEB printf
 #else
 	#define DEB(...)
 #endif
 
 typedef long long ll;
 typedef long long LL;
 typedef double D;
 typedef pair<int,int> pii;
 typedef vector<int> vi;
 
 const int inft = 1000000009;
 const int MOD = 1000000007;
 const int MAXN = 1000006;
 int S[MAXN],M[MAXN];
 vector<int> V[MAXN];
 vector<pii> ZD;
 int d;
 void dfs(int u,int par,int mmin,int mmax){
 	mmin=min(mmin,S[u]);
 	mmax=max(mmax,S[u]);
 //	printf("u: %d:: %d %d\n",u,mmin,mmax);
 	if(mmax-mmin<=d){
 		int pocz=mmax-d;
 		assert(pocz<=mmin);
 		ZD.pb(pii(pocz,1));
 		ZD.pb(pii(mmin+1,-1));
 	}
 	tr(it,V[u]) if(*it!=par) dfs(*it,u,mmin,mmax);
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int n;
 		 scanf("%d%d",&n,&d);
 		 fru(i,n) V[i].clear();
 		 int as,cs,rs;
 		 scanf("%d%d%d%d",&S[0],&as,&cs,&rs);
 		 int am,cm,rm;
 		 scanf("%d%d%d%d",&M[0],&am,&cm,&rm);
 		 for(int i=1;i<n;++i){
 			 S[i]=(1LL*S[i-1]*as+cs)%rs;
 			 M[i]=(1LL*M[i-1]*am+cm)%rm;
 			 int e=M[i]%i;
 			 V[e].pb(i);
 			 V[i].pb(e);
 		 }
 		 ZD.clear();
 		 dfs(0,-1,S[0],S[0]);
 		 sort(ALL(ZD));
 		 int ret=0;
 		 int t=0;
 		 tr(it,ZD) {
 			 t+=it->y;
 			 ret=max(ret,t);
 		 }
 		 printf("%d\n",ret);
 	}
     return 0;
 }
