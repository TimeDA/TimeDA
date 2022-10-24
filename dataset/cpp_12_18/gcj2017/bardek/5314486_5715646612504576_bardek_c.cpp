#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
 #define x first
 #define y second
 #define pb push_back
 #define ALL(G) (G).begin(),(G).end()
 
 #if 0
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
 
 namespace SCC{
 	 const int MAXN = 5005; //USTAW, potem init !!
 	 int tin[MAXN],ct,n;
 	 vi V [MAXN],Q;
 	 int scc[MAXN],SCC;//out: 0<=scc[u]<SCC  - numer scc w ktorej jest u
 
 	 void przetworz(vi &R){ //zrob cos z ta SCC
 		  tr(it,R) scc[*it]=SCC;
 		  //		  printf("w scc o nr %d sa wierzcholki:\n",SCC);		  tr(it,R) printf("%d\n",*it);
 		  ++SCC;
 	 }
 
 	 int dfs(int u){
 		  tin[u]=ct++;
 		  Q.pb(u);
 		  int m=tin[u];
 		  tr(it,V[u]) if(scc[*it]==-1)  {
 				if(tin[*it]!=-1) m=min(m,tin[*it]);
 				else m=min(m,dfs(*it));
 		  }
 		  if(m==tin[u])  {
 				vi R;
 				do{
 					 R.pb(Q.back());
 					 Q.pop_back();
 				}while(R.back()!=u);
 				przetworz(R);
 		  }
 		  return m;
 	 }
 	 void init(int _n) //to na poczatku
 	 {
 		  n=_n;
 		  fru(i,n) V[i].clear();
 		  fru(i,n) scc[i]=tin[i]=-1;
 		  SCC=0;
 		  ct=0;
 	 }
 	 void krawedz(int a,int b){//0<=a,b<n
 		  assert(min(a,b)>=0 && max(a,b)<n);
 		  V[a].push_back(b);
 	 }
 	 void go(){
 		  fru(i,n) if(tin[i]==-1) dfs(i);
 	 }
 	 void oorr(int a,int b=-1){
 		  DEB("%d or %d\n",a,b);
 		  if(b==-1) b=a;
 		  krawedz(a^1,b);
 		  krawedz(b^1,a);
 	 }
 	 /*
 2SAT:
 gdy mamy graf implikacji to istnieje wartosciowanie zmiennych
 wtw gdy dla kazdej zm. z, z i ~z sa w roznych scc
 konstrukcja:
 bierzemy ten literal o mniejszym numerze scc
 	  */
 }
 
 const int MAXN = 55;
 
 char S[MAXN][MAXN];
 
 int tak(int a){return 2*a;}
 int nie(int a){return 2*a+1;}
 
 vector<pii> X;
 vector<int> T[MAXN][MAXN];
 int n,m;
 
 int dx[]={-1,0,1,0};
 int dy[]={0,1,0,-1};
 vector<pii> LAS;
 
 bool dasie(){
 	 SCC::init(X.size()*2);
 	 fru(i,n) fru(j,m) if(S[i][j]=='.'){
 		  DEB("%d %d: rozmiar: %lu\n",i,j,T[i][j].size());
 		  if(T[i][j].empty()) return 0;
 		  assert(T[i][j].size()<=2);
 		  if(T[i][j].size()==1) SCC::oorr(T[i][j][0]);
 		  else SCC::oorr(T[i][j][0],T[i][j][1]);
 	 }
 	 tr(it,LAS) SCC::oorr(it->x,it->y);
 	 SCC::go();
 	 fru(i,X.size()) if(SCC::scc[nie(i)]==SCC::scc[tak(i)]) return 0;
 	 fru(i,X.size()) if(SCC::scc[nie(i)]<SCC::scc[tak(i)]) S[X[i].x][X[i].y]^='-'^'|';
 	 return 1;
 }
 pii R[MAXN*MAXN];
 bool laser(int a,int b){
 	 vector<int> EE;
 	 int e=X.size();
 	 X.pb(pii(a,b));
 	 DEB("jestem w gosciu %d %d\n",a,b);
 	 fru(o,2){
 		  int qs=0;
 		  bool ok=1;
 		  int ja=tak(e);
 		  if(o==1) ja=nie(e);
 		  int dir[]={0,2};
 		  if(S[a][b]=='-') fru(i,2) dir[i]++;
 		  fru(oo,2){
 				int k=dir[oo];
 				int steps=0;
 				for(int x=a,y=b;x>=0 && x<n && y>=0 && y<m && S[x][y]!='#'; x+=dx[k],y+=dy[k]){
 					 ++steps;
 					 if(S[x][y]=='-' || S[x][y]=='|'){
 						  if(x==a && y==b && steps==1) continue;
 						  else{
 								ok=0;
 								break;
 						  }
 					 }
 					 else if(S[x][y]=='.') R[qs++]=(pii(x,y));
 					 else if(S[x][y]=='/') k^=1;
 					 else if(S[x][y]=='\\')k^=3;
 					 else{
 						  printf("dziwny znaczek: %c\n",S[x][y]);
 						  assert(0);
 					 }
 				}
 		  }
 		  if(ok) {
 				EE.pb(ja);
 				DEB("%d jest ok wiec ustawiam: \n",ja);
 				fru(i,qs) DEB("%d %d\n",R[i].x,R[i].y);
 				fru(i,qs) T[R[i].x][R[i].y].pb(ja);
 		  }
 		  S[a][b]^='-'^'|';
 	 }
 	 if(EE.empty()) return 0;
 	 LAS.pb({EE[0],EE.size()==1?-1:EE[1]});
 	 return 1;
 }
 
 int main(){
 	 int o;
 	 scanf("%d",&o);
 	 fru(oo,o){
 		  printf("Case #%d: ",oo+1);
 		  scanf("%d%d",&n,&m);
 		  fru(i,n) scanf("%s",S[i]);
 		  fru(i,n) fru(j,m) T[i][j].clear();
 		  X.clear();
 		  LAS.clear();
 		  bool ok=1;
 		  fru(i,n) fru(j,m) if(S[i][j]=='-' || S[i][j]=='|') ok&=laser(i,j);
 		  if(ok==false || !dasie()) printf("IMPOSSIBLE\n");
 		  else{
 				printf("POSSIBLE\n");
 				fru(i,n) printf("%s\n",S[i]);
 		  }
 	 }
 	 return 0;
 }
