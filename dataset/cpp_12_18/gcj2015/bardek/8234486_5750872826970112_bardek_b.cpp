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
 
 typedef long long ll;
 typedef long long LL;
 typedef double D;
 typedef pair<int,int> pii;
 typedef vector<int> vi;
 
 const int inft = 1000000009;
 const int MOD = 1000000007;
 const int MAXN = 106;
 D R[MAXN],C[MAXN];
 D ret,e,f;
 D eps=1e-9;
 bool iszero(D a){ return a<eps && a>-eps;}
 void probuj(){
 	D a=R[0]*C[0]+R[1]*C[1],
 	  b=R[1]*C[1],
 	  c=e*(R[0]+R[1]),
 	  d=e*R[1];
 	if(iszero(d-b)) return;
 	D u=(a-c)/(d-b);
 	if(u<0) return;
 	D q=f/(R[0]+R[1]+u*R[1]);
 	ret=min(ret,q*(u+1));
 }
 
 void solve(){
 	int n;
 	scanf("%d%lf%lf",&n,&f,&e);
 	assert(n<=2);
 	fru(i,n) scanf("%lf %lf",&R[i],&C[i]); 
 	ret=1e20;
 	fru(a,n) if(iszero(C[a]-e)) ret=min(ret,f/R[a]);
 	if(n==2) fru(o,2){
 		probuj();
 		swap(R[0],R[1]);
 		swap(C[0],C[1]);
 	}
 	if(n==2 && iszero(C[0]-C[1]) && iszero(C[0]-e)){
 		ret=min(ret,f/(R[0]+R[1]));
 	}
 	if(ret<1e15) printf("%.6lf\n",ret);
 	else printf("IMPOSSIBLE\n");
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 solve();
 	}
     return 0;
 }
