#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cassert>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 int w,h;
 
 const int MAXN=100005;
 
 vector<pii> E [MAXN];
 
 void odwroc(int u, int p)
 {
 	int tam=E[u][p].y;
 	E[E[u][p].x][tam].y=p;
 //printf("krawedz z %d o nrze %d jest to %d / %d\n",u,p,E[u][p].x,E[u][p].y);
 	E[u][p].y=-1;
 //	printf("a potem te
 	assert(E[E[u][p].x][tam].x==u);
 }
 
 int pocz[MAXN]; //numer krawedzi od ktorej powinienem zaczac poszukiwania
 int n,ujscie,zrodlo;
 int war[MAXN]; //warstwa po krawedziach nieujemnych
 void pisz(int a)
 {
 	printf("(%d, %d %s)",a/(2*h),a%(2*h)/2,(a%(2*h))%2?"out":"in");
 }
 int dfs(int u) //ile moge max puscic, ale <=ile
 {
 	if(u==ujscie) return 1;
 	int ans=0;
 	for(int k=pocz[u];k<E[u].size();++k,++pocz[u]) if((war[E[u][k].x]==(war[u]+1)) && E[u][k].y!=-1)
 	{
 		if(dfs(E[u][k].x))
 		{
 //			printf("idzie przeplyw od pola");pisz(u);printf("do:");pisz(E[u][k].x);	printf("\n");
 			odwroc(u,k);
 			if(u==zrodlo) ++ans;
 			else return 1;
 		}
 	}
 	return ans;
 }
 int Q[MAXN]; //queue
 bool bfs()
 {
 	for(int i=0;i<n;++i) war[i]=-1;
 	int ct=0;
 	Q[ct++]=zrodlo;
 	war[zrodlo]=1;
 	for(int i=0;i<ct;++i) tr(it,E[Q[i]]) if((war[it->x]==-1) && (it->y!=-1))
 	{
 		Q[ct++]=it->x;
 		war[it->x]=war[Q[i]]+1;
 	}
 	return war[ujscie]!=-1;
 }
 int maxflow()
 {
 	int ans=0;
 	while(bfs())
 	{
 		for(int i=0;i<n;++i) pocz[i]=0;
 		ans+=dfs(zrodlo);
 //		printf("teraz ans = %d\n",ans);
 	}
 	return ans;
 }
 
 void dodajkrawedz(int a, int b)
 {
 //	printf("krawedz od "); pisz(a); printf("do "); pisz(b); printf("\n");
 	E[a].push_back(pii(b,E[b].size()));
 	E[b].push_back(pii(a,-1));
 }
 bool CZY[505][505];
 int nr(int a,int b,int c) {return a*h*2+b*2+c;}
 int dx[]={0,1,0,-1};
 int dy[]={1,0,-1,0};
 bool ok(int a, int b)
 {
 	return a>=0 && b>=0 && a<w && b<h && CZY[a][b];
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		printf("Case #%d: ",oo+1);
 		int b;
 		scanf("%d%d%d",&w,&h,&b);
 		n=w*h*2;
 		fru(i,w) fru(j,h) CZY[i][j]=1;
 		zrodlo=n++;
 		ujscie=n++;
 		fru(i,n) E[i].clear();
 //		printf("zrodlo:"); pisz(zrodlo);printf("\n");
 //		printf("ujscie:"); pisz(ujscie);printf("\n");
 		fru(e,b)
 		{
 			int xl,xh,yl,yh;
 			scanf("%d%d%d%d",&xl,&yl,&xh,&yh);
 			for(int i=xl;i<=xh;++i) for(int j=yl;j<=yh;++j) CZY[i][j]=0;
 		}
 	/*	printf("\n");
 		fru(i,h)
 		{
 			fru(j,w) printf("%d ",CZY[j][i]); printf("\n");
 		}*/
 		fru(i,w) fru(j,h) if(ok(i,j)) fru(k,4) if(ok(i+dx[k],j+dy[k]))
 			dodajkrawedz(nr(i,j,1),nr(i+dx[k],j+dy[k],0));
 		fru(i,w) dodajkrawedz(zrodlo,nr(i,0,0));
 		fru(i,w) dodajkrawedz(nr(i,h-1,1),ujscie);
 		fru(i,w) fru(j,h) if(CZY[i][j]) dodajkrawedz(nr(i,j,0),nr(i,j,1));
 		printf("%d\n",maxflow());
 	}
 	return 0;
 }
