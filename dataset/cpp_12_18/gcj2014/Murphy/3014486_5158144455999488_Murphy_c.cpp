#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 const int MAXN=110000,MAXM=440000; 
 
 
 //Dinic module from ZJU ACM ICPC team
 struct Dinic{
 	struct edge { 
 		int x,y;
 		int c;int f; 
 		edge *next,*back; 
 		edge(int x,int y,int c,edge *next):x(x),y(y),c(c),f(0),next(next),back(0) {} 
 		void *operator new(size_t, void *p) {
 		return p; }
 	} *E[MAXN],*data; 
 	char storage[2*MAXM *sizeof(edge)];
 	int S,T; 
 	int Q[MAXN];
 	int D[MAXN]; 
 	void DFS() {
 		memset(D,-1,sizeof(D)); 
 		int head=0,tail=0; Q[tail++]=S;
 		D[S]=0;
 		for(;;) {
 			int i=Q[head++];
 			for(edge *e=E[i]; e; e=e->next) { 
 				if(e->c==0)continue;
 				int j=e->y;
 				if(D[j]==-1) {
 					D[j]=D[i]+1; Q[tail++]=j; if(j==T)return;
 				} 
 			}
 			if(head==tail)break; 
 		}
 	}
 	edge *cur[MAXN];
 	edge *path[MAXN];
 	int flow() { 
 	int res=0;
 	int path_n;
 	for(;;) { 
 		DFS();
 		if(D[T]==-1)break; 
 		memcpy(cur,E,sizeof(E)); path_n=0;
 		int i=S;
 		for(;;) {
 			if(i==T) { 
 				int mink=0;
 				int delta=INT_MAX;
 				for(int k=0; k<path_n; ++k) {
 					if(path[k]->c < delta) { 
 						delta = path[k]->c; mink=k;
 					} 
 				}
 				for(int k=0; k<path_n; ++k) {
 					path[k]->c -= delta;
 					path[k]->back->c += delta;
 				}
 				path_n=mink; 
 				i=path[path_n]->x; res+=delta;
 			}
 		edge *e;
 		for(e=cur[i]; e; e=e->next) {
 			if(e->c==0)continue; int j=e->y;
 			if(D[i]+1==D[j])break; 
 		}
 		cur[i]=e;
 		 if(e) {
 		    path[path_n++]=e;
 		    i=e->y;
 		} else { 
 			D[i]=-1;
 			if(path_n==0)break; path_n--; i=path[path_n]->x;
 			}
 		}
 	}
 		return res; 
 	}
 
 	void init(int _S,int _T) {
 	S=_S,T=_T;
 	data=(edge *)storage; 
 	memset(E,0,sizeof(E));
 	}
 	void add_edge(int x,int y,int w) { 
 		// cout<<x<<' '<<y<<' '<<w<<endl;
 		E[x]=new((void *)data++) edge(x,y,w,E[x]); 
 		E[y]=new((void *)data++) edge(y,x,0,E[y]); 
 		E[x]->back = E[y];
 		E[y]->back = E[x];
 	} 
 };
 
 
 
 Dinic dinic;
 int M[128][512];
     	int W, H, B;
 
 inline int  ID(int x, int y) {
 	return x * H + y;
 }
 
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>W>>H>>B;
     	memset(M, 0, sizeof M);
     	int WH = W * H;
     	REP(i, B) {
     		int x0, y0, x1, y1;
     		cin>>x0>>y0>>x1>>y1;
     		for (int x = x0; x <= x1; x++) {
     			for (int y = y0; y <= y1; y++) {
     				M[x][y] = 1;
     			}
     		}
     	}
     	dinic.init(2 * WH, 2 * WH + 1);
     	REP(i, W) {
     		REP(j, H) {
     			if (i)
     				dinic.add_edge(ID(i, j),ID(i - 1, j) + WH,WH);
     			if (i != W - 1)
     				dinic.add_edge(ID(i, j),ID(i + 1, j) + WH,WH);
     			if (j)
     				dinic.add_edge(ID(i, j),ID(i, j - 1) + WH,WH);
     			if (j != H - 1)
     				dinic.add_edge(ID(i, j),ID(i, j + 1) + WH,WH);
     			if (!M[i][j])
     				dinic.add_edge(ID(i, j)+ WH,ID(i, j) ,1);
     		}
     	}
     	REP(i, W) {
     		if (!M[i][0])
     			dinic.add_edge(2 * WH ,ID(i, 0),1);
     		if (!M[i][H - 1])
     			dinic.add_edge(ID(i, H - 1) + WH, 2 * WH + 1,1);
     	}
     	int rst=dinic.flow();
     	printf("Case #%d: %d\n", caseN + 1, rst);
     }
     return 0;
 }