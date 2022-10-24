#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <math.h>
 #include <queue>
 #include <list>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stack>
 #include <ctime>
 using namespace std;
 
 #define ALL(c) (c).begin(),(c).end()
 #define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
 #define REP(i,n) for (int i=0;i<(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define FORD(i,a,b) for (int i=(a);i>=(b);i--)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 // Dinitz max-flow
 
 namespace MF {
 
 #define N 100009
 #define M N*4
 #define INF 1000000000
 
 typedef struct {
 	int v1; int v2; int cap; int orig; int next;
 } edge;
 
 typedef struct {
 	int first; int last; int cur; int dist;
 } node;
 
 int n,m;
 node nodes[N];
 edge edges[2*M];
 
 void init(int nn) {
 	n=nn; m=0;
 	for (int i=0;i<n;i++) nodes[i].first=-1;
 }
 
 void addEdge(int f, int t, int c, int directed=1) {
 	node &nf=nodes[f];
 	edges[m]=(edge){f,t,c,c,-1};
 	if (nf.first==-1) { nf.first=m; nf.last=m; }
 	else { edges[nf.last].next=m; nf.last=m; }
 	m++;
 	node &nt=nodes[t];
 	edges[m]=(edge){t,f,directed?0:c,directed?0:c,-1};
 	if (nt.first==-1) { nt.first=m; nt.last=m; }
 	else { edges[nt.last].next=m; nt.last=m; }
 	m++;
 }
 
 int q[N],head,tail;
 
 int bfs(int source, int sink) { // build implicit layered graph
 	for (int i=0;i<n;i++) nodes[i].dist=-1;
 	nodes[source].dist=0;
 	q[0]=source; head=0; tail=1;
 	while (head<tail) {
 		int x=q[head++];
 		for (int i=nodes[x].first;i!=-1;i=edges[i].next) if (edges[i].cap>0) {
 			int y=edges[i].v2;
 			if (nodes[y].dist==-1) {
 				nodes[y].dist=nodes[x].dist+1;
 				q[tail++]=y;
 			}
 		}
 	}
 	return nodes[sink].dist!=-1;
 }
 
 int dfs(int x, int sink, int flow=INF) {
 	if (x==sink) return flow;
 	for (int &i=nodes[x].cur;i!=-1;i=edges[i].next) if (edges[i].cap>0) {
 		int y=edges[i].v2;
 		if (nodes[y].dist!=nodes[x].dist+1) continue;
 		int df = dfs(y,sink,min(flow,edges[i].cap));
 		if (df>0) {
 			edges[i].cap-=df;
 			edges[i^1].cap+=df;
 			return df;
 		}
 	}
 	return 0;
 }
 
 long long maxFlow(int source, int sink) {
 	long long flow=0;
 	while (bfs(source, sink)) {
 		for (int i=0;i<n;i++) nodes[i].cur=nodes[i].first;
 		while (1) {
 			long long df = dfs(source, sink);
 			if (df==0) break;
 			flow += df;
 		}
 	}
 	return flow;
 }
 
 }
 
 int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
 
 int w,h,b;
 int block[1000][1000];
 
 int in(int y, int x) { return 2*(y*w+x); }
 int out(int y, int x) { return 2*(y*w+x)+1; }
 
 int main() {
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C-small-attempt0.out","w",stdout);
 	//freopen("C.in","r",stdin);
 	//freopen("C.out","w",stdout);
 	int tests;
 	scanf("%d",&tests);
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		scanf("%d %d %d",&w,&h,&b);
 		INIT(block,0);
 		REP (i,b) {
 			int x0,y0,x1,y1;
 			scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
 			FOR (x,x0,x1) FOR (y,y0,y1) block[y][x]=1;
 		}
 		int source=2*w*h, sink=2*w*h+1;
 		MF::init(2*w*h+2);
 		REP (y,h) REP (x,w) if (!block[y][x]) {
 			MF::addEdge(in(y,x),out(y,x),1,1);
 			REP (d,4) {
 				int y2=y+dir[d][0], x2=x+dir[d][1];
 				if (0<=y2 && y2<h && 0<=x2 && x2<w) {
 					MF::addEdge(out(y,x),in(y2,x2),1,1);
 				}
 			}
 		}
 		REP (x,w) {
 			MF::addEdge(source,in(0,x),1,1);
 			MF::addEdge(out(h-1,x),sink,1,1);
 		}
 		int f = MF::maxFlow(source,sink);
 		printf("Case #%d: %d\n",test,f);
 	}
 	return 0;
 }
