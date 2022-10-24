#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
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
 
 namespace DD{
 	//---------ta czesc ustawiamy------------------
 	typedef int type;	  //do trzymania pojemnosci i przeplywu calk.
 	const type inf = 1LL<<20; //maksymalny sum. przeplyw
 	const int MAXN = 8016;
 	vector<int> V [MAXN];
 	int n,ujscie,zrodlo;
 	//---------reszta------------------------------
 	type M [MAXN][MAXN];
 	int pocz[MAXN],w[MAXN],Q[MAXN];
 
 	type dfs(int u, type ile) //ile moge max puscic, ale <=ile
 	{
 		if(u==ujscie || ile==0) return ile;
 		type t,ans=0;
 #define ne V[u][k]
 		for(int k=pocz[u];k<V[u].size();++k,++pocz[u]) if(w[ne]==w[u]+1 && M[u][ne]>0)
 		{
 			t=dfs(V[u][k],min(M[u][ne],ile));
 			M[u][ne]-=t;
 			M[ne][u]+=t;
 			ile-=t; ans+=t;
 			if(ile==0) break;
 		}
 		return ans;
 	}
 	bool bfs()
 	{
 		for(int i=0;i<n;++i) w[i]=-1;
 		int ct=0;
 		Q[ct++]=zrodlo;
 		w[zrodlo]=1;
 		for(int i=0;i<ct;++i) tr(it,V[Q[i]]) if(w[*it]==-1 && M[Q[i]][*it]>0)
 		{
 			Q[ct++]=*it;
 			w[*it]=w[Q[i]]+1;
 		}
 		return w[ujscie]!=-1;
 	}
 	type maxflow()//z zew.
 	{
 		type ans=0;
 		while(bfs())
 		{
 			for(int i=0;i<n;++i) pocz[i]=0;
 			ans+=dfs(zrodlo,inf);
 		}
 		return ans;
 	}
 
 	void ae(int a, int b, type k) //z zew.
 	{
 		assert(max(a,b)<MAXN);
 		if(a==b) return;
 		M[a][b]+=k;
 		V[a].push_back(b);
 		V[b].push_back(a);
 	}
 	void czysc(){
 		fru(i,MAXN) fru(j,MAXN) M[i][j]=0;
 		fru(i,n) V[i].clear();
 	}
 }
 vi V[505];
 map<string,int> M;
 char S[500005];
 int numer(string a){
 //	cout<<a<<endl;
 	if(M.find(a)!=M.end()) return M[a];
 	int e=M.size();
 	return M[a]=e;
 }
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		printf("Case #%d: ",oo+1);
 		M.clear();
 		M["-s"]=0;
 		M["-t"]=1;
 		int n;
 		scanf("%d\n",&n);
 		fru(i,n) V[i].clear();
 		fru(i,n){
 			scanf("%[^\n]\n",S);
 			int d=strlen(S);
 			S[d++]=' ';
 			int pocz=0;
 			for(int j=0;j<d;++j){
 				if(S[j]==' '){
 					V[i].pb(numer(string(S+pocz,S+j)));
 					pocz=j+1;
 				}
 			}
 //			tr(it,V[i]) printf("%d ",*it); printf("\n");
 		}
 		int r=M.size();
 		DD::czysc();
 		DD::n=2*r+5;
 		DD::zrodlo=0;
 		DD::ujscie=1;
 		tr(it,V[0]) DD::ae(0,2**it,1<<20);
 		tr(it,V[1]) DD::ae(2**it+1,1,1<<20);
 		for(int i=2;i<r;++i) DD::ae(2*i,2*i+1,1);
 		for(int i=2;i<n;++i){
 			tr(ia,V[i]) tr(ib,V[i]) if(*ia!=*ib){
 				DD::ae(2**ia+1,2**ib,1<<20);
 			}
 		}
 		printf("%d\n",DD::maxflow());
 	}
 	return 0;
 }
