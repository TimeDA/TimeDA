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
 
 int n,m;
 char S[MAXN][MAXN];
 bool ok(int a,int b){return a>=0 && b>=0 && a<n && b<m;}
 #define X i+dx[k]
 #define Y j+dy[k]
 
 int dx[]={-1,0,1,0};
 int dy[]={0,1,0,-1};
 bool dojde(int i,int j,int k){
 	while(1){
 		if(ok(X,Y)==0) return 0;
 		if(S[X][Y]!='.') return 1;
 		i=X;
 		j=Y;
 	}
 }
 
 int solve(){
 	scanf("%d%d",&n,&m);
 	fru(i,n) scanf("%s",S[i]);
 	int ret=0;
 	fru(i,n) fru(j,m) if(S[i][j]!='.'){
 		int kk=0;
 		if(S[i][j]=='v') kk=2;
 		if(S[i][j]=='<') kk=3;
 		if(S[i][j]=='>') kk=1;
 		if(S[i][j]=='^') kk=0;
 		if(dojde(i,j,kk)) continue;
 		++ret;
 		bool ok=0;
 		fru(k,4) if(dojde(i,j,k)) ok=1;
 		if(ok==0) return -1;
 	}
 	return ret;
 }
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int a=solve();
 		 if(a==-1) printf("IMPOSSIBLE\n");
 		 else printf("%d\n",a);
 	}
     return 0;
 }
