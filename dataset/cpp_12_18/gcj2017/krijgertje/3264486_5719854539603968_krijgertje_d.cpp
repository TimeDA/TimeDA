#include <algorithm>  
 #include <iostream>  
 #include <sstream>  
 #include <string>  
 #include <vector>  
 #include <queue>  
 #include <set>  
 #include <map>  
 #include <cstdio>  
 #include <cstdlib>  
 #include <cctype>  
 #include <cmath>  
 #include <list>  
 #include <climits>
 #include <cassert>
 using namespace std;  
 
 #define PB push_back  
 #define MP make_pair  
 #define SZ(v) ((int)(v).size())  
 #define FOR(i,a,b) for(int i=(a);i<(b);++i)  
 #define REP(i,n) FOR(i,0,n)  
 #define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
 #define REPE(i,n) FORE(i,0,n)  
 #define FORSZ(i,a,v) FOR(i,a,SZ(v))  
 #define REPSZ(i,v) REP(i,SZ(v))  
 typedef long long ll;  
 
 const int MAXN=100;
 const int MAXBM=2*MAXN-1;
 
 
 typedef struct BM {
 	int nl,nr;
 	bool donel[MAXBM];
 	int matchl[MAXBM];
 	int matchr[MAXBM];
 	bool fixedr[MAXBM];
 	vector<int> adj[MAXBM];
 	void init(int _nl,int _nr) { nl=_nl,nr=_nr; REP(i,nl) matchl[i]=-1; REP(i,nr) matchr[i]=-1,fixedr[i]=false; REP(i,nl) adj[i].clear(); }
 	bool augment(int at) {
 		if(donel[at]) return false; else donel[at]=true;
 		REPSZ(i,adj[at]) {
 			int to=adj[at][i];
 			if(matchr[to]==-1||!fixedr[to]&&augment(matchr[to])) { matchr[to]=at,matchl[at]=to; return true; }
 		}
 		return false;
 	}
 	int solve() {
 		//REP(i,nl) { printf("%d:",i); REPSZ(j,adj[i]) printf(" %d",adj[i][j]); puts(""); }
 		memset(donel,false,sizeof(donel));
 		REP(i,nl) if(matchl[i]==-1&&augment(i)) memset(donel,false,sizeof(donel));
 		int ret=0; REP(i,nl) if(matchl[i]!=-1) ++ret; return ret;
 	}
 	void fix(int x,int y) {
 		assert(matchl[x]==-1&&matchr[y]==-1); matchl[x]=y,matchr[y]=x,fixedr[y]=true;
 	}
 } BM;
 
 int n,nfix;
 BM orth,diag;
 char retc[MAXN*MAXN]; int retx[MAXN*MAXN],rety[MAXN*MAXN]; int nret=0;
 
 
 void run(int casenr) {
 	scanf("%d%d",&n,&nfix);
 	orth.init(n,n); REP(i,n) REP(j,n) orth.adj[i].PB(j);
 	diag.init(2*n-1,2*n-1); REP(i,n) REP(j,n) diag.adj[i+j].PB(i-j+n-1);
 	REP(i,nfix) {
 		char c; int x,y; scanf(" %c%d%d",&c,&x,&y); --x,--y;
 		if(c!='+') orth.fix(x,y);
 		if(c!='x') diag.fix(x+y,x-y+n-1);
 	}
 	int ret1=orth.solve(),ret2=diag.solve();
 	nret=0;
 	REP(x,n) REP(y,n) {
 		bool change=false,o=false,d=false;
 		if(orth.matchl[x]==y) { o=true; if(!orth.fixedr[y]) change=true; }
 		if(diag.matchl[x+y]==x-y+n-1) { d=true; if(!diag.fixedr[x-y+n-1]) change=true; }
 		if(change) retc[nret]=o&&d?'o':o?'x':d?'+':'.',retx[nret]=x,rety[nret]=y,++nret;
 	}
 
 	printf("Case #%d: %d %d\n",casenr,ret1+ret2,nret);
 	REP(i,nret) printf("%c %d %d\n",retc[i],retx[i]+1,rety[i]+1);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
