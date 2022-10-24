#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
 #define x first
 #define y second
 #define pb push_back
 #define ALL(G) (G).begin(),(G).end()
 
 #if 1
 #define DEB printf
 #else
 #define DEB(...)
 #endif
 
 typedef long long LL;
 typedef double D;
 typedef pair<int,int> pii;
 typedef vector<int> vi;
 const int inft = 1000000009;
 const int MOD = 1000000007;
 const int MAXN = 106;
 
 LL W[MAXN][MAXN],inf=1LL<<60;
 pii H[MAXN];
 bool byl[MAXN];
 D dis[MAXN];
 int n;
 
 D licz(){
 	 int p,k;
 	 scanf("%d%d",&p,&k);
 	 --p;--k;
 	 fru(i,n) dis[i]=1e100;
 	 fru(i,n) byl[i]=0;
 	 dis[p]=0.;
 	 fru(_,n){
 		  int u=-1;
 		  fru(i,n) if(!byl[i]) if(u==-1 || dis[u]>dis[i]) u=i;
 		  byl[u]=1;
 		  fru(i,n) if(i!=u && W[u][i]<=H[u].x){
 				dis[i]=min(dis[i],dis[u]+1.*W[u][i]/H[u].y);
 		  }
 	 }
 	 return dis[k];
 }
 
 void solve(){
 	 int q;
 	 scanf("%d%d",&n,&q);
 	 fru(i,n) scanf("%d%d",&H[i].x,&H[i].y);
 	 fru(i,n) fru(j,n) scanf("%lld",&W[i][j]);
 	 fru(i,n) fru(j,n) if(W[i][j]==-1) W[i][j]=inf;
 	 fru(i,n) W[i][i]=0;
 	 fru(k,n) fru(i,n) fru(j,n) W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
 	 fru(_,q) printf(" %.7lf",licz());
 	 printf("\n");
 }
 
 int main(){
 	 int o;
 	 scanf("%d",&o);
 	 fru(oo,o){
 		  printf("Case #%d:",oo+1);
 		  solve();		 
 	 }
 	 return 0;
 }
