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
 const int MAXN = 1006;
 
 pii P[MAXN];
 pii IN[MAXN];
 
 
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 int d,n;
 		 scanf("%d%d",&d,&n);
 		 D t=0.;
 		 fru(i,n){
 			  int k,s;
 			  scanf("%d %d",&k,&s);
 			  t=max(t,1.*(d-k)/s);
 		 }
 		 printf("%.7lf\n",d/t);
 
 /*
 		 fru(i,n) scanf("%d%d",&IN[i].x,&IN[i].y);
 		 IN[n++]=pii(d,0);
 		 sort(IN,IN+n);
 		 int qs=0;
 		 fru(i,n) if(qs==0 || IN[i].y<P[qs-1].y) P[qs++]=IN[i];
 		 n=qs;
 		 fru(i,n-1){
 
 		 }*/
 	}
     return 0;
 }
