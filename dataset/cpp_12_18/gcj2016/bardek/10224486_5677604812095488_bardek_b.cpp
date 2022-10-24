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
 const int MAXN = 206;
 
 D P[MAXN];
 
 D W[MAXN][2*MAXN];
 //W[i][j] - max ppb 
 
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 int n,k;
 		 scanf("%d%d",&n,&k);
 		 fru(i,n) scanf("%lf",&P[i]);
 		 D ret=0.;
 		 fru(ma,1<<n) if(__builtin_popcount(ma)==k){
 			  vi V;
 			  fru(i,n) if(ma&(1<<i)) V.pb(i);
 			  int s=V.size();
 			  fru(i,s+1) fru(j,2*s+2) W[i][j]=0;
 			  W[0][s+1]=1.;
 			  fru(i,s) fru(j,2*s+2){
 					D e=0;
 					if(j>0) e+=W[i][j-1]*P[V[i]];
 					if(j+1<2*s+2) e+=W[i][j+1]*(1.-P[V[i]]);
 					W[i+1][j]=e;
 			  }
 			  ret=max(ret,W[s][s+1]);
 		 }
 		 printf("%.6lf\n",ret);
 	}
     return 0;
 }
