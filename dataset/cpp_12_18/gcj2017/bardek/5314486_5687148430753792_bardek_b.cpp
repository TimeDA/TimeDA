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
 const int MAXN=2005;
 
 namespace MCMF {
 /*
 -dorzucanie krawędzi: addedge(int a, int b,int cap,int cost)
 -trzeba ustawić: n,s,t (ew. MAXN i INF)
 -void licz() wylicza FLOW i COST
 -czysc() czysci graf (przed ustawieniem nowego n!!!)
 */
 	const int INF=1<<30;
 	struct edge
 	{
 		int from,w,rev;
 		int flow,cap,cost;
 		int dist;
 		inline bool moge() {return flow<cap;}
 		edge(int _from, int _w, int _cap, int _cost):
 			from(_from),w(_w),flow(0),cap(_cap),cost(_cost),dist(_cost) {}
 	};
 	int n,s,t;
 	int FLOW,COST;
 	vector<edge> G[MAXN];
 	vector<edge>::iterator p[MAXN]; //jak przyszedlem
 	int d[MAXN];
 	bool inq[MAXN];
 	void bellman()
 	{
 		fru(i,n) d[i]=INF;
 		queue<int> Q;
 		Q.push(s);
 		inq[s]=1;
 		d[s]=0;
 		while(!Q.empty())
 		{
 			int u=Q.front(); Q.pop(); inq[u]=0;
 			tr(it,G[u]) if(it->moge() && d[it->w]>d[u]+it->dist)
 			{
 				d[it->w]=d[u]+it->dist;
 				p[it->w]=it;
 				if(!inq[it->w])	{inq[it->w]=1; Q.push(it->w);}
 			}
 		}
 	}
 //    TA CZESC JEST OPCJONALNYM PRZYSPIESZENIEM
 //	  Dijkstra(na secie albo ta) powinna byc szybsza, ale nie zawsze jest
 /*	void dijkstra()	{
 		fru(i,n) inq[i]=0;
 		fru(i,n) d[i]=INF;
 		d[s]=0;
 		while(1){
 			int u=-1,dl=INF;
 			fru(i,n) if(inq[i]==0 && d[i]<dl) { dl=d[i];u=i;}
 			if(dl==INF) break;
 			inq[u]=1;
 			tr(it,G[u]) if(it->moge() && d[it->w]>d[u]+it->dist){
 				d[it->w]=d[u]+it->dist;
 				p[it->w]=it;
 			}
 		}
 	}
 	void potencjaly(){	fru(u,n) tr(it,G[u]) it->dist+=d[u]-d[it->w];}*/
 	void licz()
 	{//v1- teoretycznie lepsze, w praktyce roznie
 //		bellman();//v1
 		while(1)
 		{
 //			potencjaly(); dijkstra();//v1
 			bellman(); //v2
 			if(d[t]==INF) break;
 			int cc=INF;
 			for(int u=t;u!=s;u=p[u]->from) cc=min(cc,p[u]->cap-p[u]->flow);
 			for(int u=t;u!=s;u=p[u]->from)
 			{
 				p[u]->flow+=cc;
 				COST+=cc*p[u]->cost;
 				G[p[u]->w][p[u]->rev].flow-=cc;
 			}
 			FLOW+=cc;
 		}
 	}
 	void addedge(int a, int b,int cap,int cost)
 	{
 //		 printf("%d -> %d (%d,%d)\n",a,b,cap,cost);
 		if(a==b) return;
 		G[a].push_back(edge(a,b,cap,cost));
 		G[b].push_back(edge(b,a,0,-cost));
 		G[a].back().rev=G[b].size()-1;
 		G[b].back().rev=G[a].size()-1;
 	}
 	void czysc() {
 		FLOW=COST=0;
 		fru(i,n) G[i].clear();
 	}
 /* jak przyspieszac:
 -- gdy nie ma wielokrotnych krawedzi (cala edge niepotrzebna i jak w Dinicu)
 -- gdy graf rzadki / gesty :: wtedy zastepujemy Bellmana czym innym (v1/v2)
 -- ew. mozna wywalic from oraz dist z pamieci (liczyc na biezaco)*/
 }
 
 pii T[MAXN];
 
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 int n,c,m;
 		 scanf("%d%d%d",&n,&c,&m);
 		 MCMF::czysc();
 		 MCMF::n=m+2;
 		 MCMF::s=m;
 		 MCMF::t=m+1;
 		 assert(c==2);
 		 fru(i,m) scanf("%d%d",&T[i].x,&T[i].y);
 		 fru(i,m) if(T[i].y==1) MCMF::addedge(MCMF::s,i,1,0);
 		 else MCMF::addedge(i,MCMF::t,1,0);
 		 fru(i,m) fru(j,m) if(T[i].y!=T[j].y && T[i].y==1 && max(T[i].x,T[j].x)>1) MCMF::addedge(i,j,1,T[i].x==T[j].x);
 		 MCMF::licz();
 		 printf("%d %d\n",m-MCMF::FLOW,MCMF::COST);
 	}
    return 0;
 }
