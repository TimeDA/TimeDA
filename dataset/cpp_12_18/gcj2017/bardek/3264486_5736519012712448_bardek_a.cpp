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
 const int MAXN = 1000006;
 char S[MAXN];
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 int k;
 		 scanf("%s %d",S,&k);
 		 int d=strlen(S);
 		 int ret=0;
 		 fru(i,d-k+1) if(S[i]=='-'){
 			  fru(j,k) S[i+j]^='-'^'+';
 			  ++ret;
 		 }
 		 fru(i,d) if(S[i]=='-') ret=-1;
 		 if(ret==-1) printf("IMPOSSIBLE\n");
 		 else printf("%d\n",ret);
 	}
     return 0;
 }
