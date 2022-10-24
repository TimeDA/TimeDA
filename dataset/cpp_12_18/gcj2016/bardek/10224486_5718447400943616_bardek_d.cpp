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
 const int MAXN = 4;
 
 bool dobra[MAXN+1][1<<(MAXN*MAXN)];
 
 void solve(){
 	 int n;
 	 scanf("%d",&n);
 	 int IN=0;
 	 fru(i,n*n) {
 		  char c;
 		  scanf(" %c",&c);
 		  if(c=='1') IN+=1<<i;
 	 }
 	 int ret=n*n;
 	 fru(ma,1<<n*n) if(((ma&IN)==IN) && __builtin_popcount(ma^IN)<ret) 
 		  if(dobra[n][ma]) ret=__builtin_popcount(ma^IN);
 	 printf("%d\n",ret);
 }
 
 namespace TM{ //Turbo Matching O(nm)
 	//-----------------te ustawiamy przed uzyciem------------------
 	const int MAXN = 10;  //musi zmiescic c+d
 	vector<int> V[MAXN];   //wystarczy tylko od chlopcow
 	int c,d;               //chlopcy 0..c-1, dziewczyny: c..c+d-1
 	//-----------------te sa wynikowe------------------------------
 	int M[MAXN];           //z kim jest skojarzony lub -1 jak z nikim
 	//----------------te sa pomocniczne-----------------------------
 	bool odw[MAXN];
 	queue<int> Q;
 	inline bool dfs(int u)
 	{
 		odw[u]=1;
 		Q.push(u);
 		tr(it,V[u]) if((M[*it]==-1) || (!odw[M[*it]] && dfs(M[*it])))
 		{
 			M[u]=*it;
 			M[*it]=u;
 			return 1;
 		}
 		return 0;
 	}//to do zbioru niezaleznego/pokrycia wierzch
 	vi IS,VC;bool TT[MAXN];
 	void d2(int u){
 		if(TT[u]) return;
 		TT[u]=1; tr(it,V[u]) TT[*it]=1,d2(M[*it]);}
 	int matching() //zwraca rozmiar matchingu
 	{
 		fru(i,c) odw[i]=0;
 		fru(i,c+d) M[i]=-1;
 		bool czy=1;
 		while(czy)
 		{
 			for(czy=0;!Q.empty();Q.pop()) odw[Q.front()]=0;
 			fru(i,c) if(M[i]==-1 && !odw[i]) czy|=dfs(i);
 		}
 		int ret=0;
 		fru(i,c) if(M[i]!=-1) ++ret;
 		if(1){ //zbior niezal / pokrycie wierzcholkowe
 			fru(i,c+d) TT[i]=0;
 			fru(i,c) if(M[i]==-1) d2(i);
 			fru(i,c) if(TT[i]==1) IS.pb(i);	else VC.pb(i);
 			fru(i,d) if(TT[i+c]==1) VC.pb(i+c);else IS.pb(i+c);
 		}//Dilworth: wez takie ktorych we i wy sa w IS
 		return ret;
 	}
 }
 
 bool sprawdz(int n,int ma){
 	 bool b[n][n];
 	 int ct=0;
 	 fru(i,n) fru(j,n) {
 		  if(ma&(1<<ct)) b[i][j]=1;
 		  else b[i][j]=0;
 		  ++ct;
 	 }
 	 fru(nie,n) {
 		  fru(i,n) TM::V[i].clear();
 		  TM::c=TM::d=n;
 		  int w=0;
 		  fru(i,n) if(b[nie][i]) ++w;
 		  fru(i,n) if(i!=nie) fru(k,n) if(b[nie][k] && b[i][k]) TM::V[i].pb(n+k);
 		  if(TM::matching()==w) return 0;
 	 }
 	return 1;
 }
 int main(){
 	for(int n=1;n<=4;++n) fru(ma,1<<(n*n)) dobra[n][ma]=sprawdz(n,ma);
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);		 
 		 solve();
 	}
     return 0;
 }
