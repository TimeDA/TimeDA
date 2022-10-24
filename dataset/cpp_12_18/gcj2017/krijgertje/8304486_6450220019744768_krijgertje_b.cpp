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
 
 const int MAXN=1000;
 const int MAXM=2000;
 
 int n,m;
 int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gdeg[MAXN];
 bool dead[MAXM];
 
 int ret[MAXM];
 
 int back[MAXN];
 int q[MAXN],qhead,qtail;
 
 vector<vector<int> > paths;
 vector<vector<int> > cycles;
 int cycleid[MAXN],fstcycleoff[MAXN];
 
 void buildcycle(int at,vector<int> &cycle,int d=0) {
 	//REP(i,d) printf("  "); printf("buildcycle(%d)\n",at);
 	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!dead[x>>1]) {
 		int to=gto[x]; dead[x>>1]=true; buildcycle(to,cycle,d+1); cycle.PB(x^1);
 	}
 }
 
 
 bool solve() {
 	REP(i,n) if(gdeg[i]==1) return false;
 
 	paths.clear();
 	REP(i,m) dead[i]=false;
 	REP(s,n) if(gdeg[s]%2==1) {
 		qhead=qtail=0; q[qhead++]=s; REP(i,n) back[i]=-1; back[s]=-2; int t=-1;
 		while(qtail<qhead&&t==-1) {
 			int at=q[qtail++];
 			for(int x=ghead[at];x!=-1&&t==-1;x=gnxt[x]) {
 				int to=gto[x]; if(back[to]!=-1) continue;
 				back[to]=x^1;
 				if(gdeg[to]%2==1) t=to; else q[qhead++]=to;
 			}
 		}
 		assert(t!=-1);
 		vector<int> path;
 		for(int at=t;at!=s;at=gto[back[at]]) {
 			--gdeg[at],--gdeg[gto[back[at]]]; path.PB(back[at]);
 			dead[back[at]>>1]=true;
 		}
 		paths.PB(path);
 	}
 
 	cycles.clear();
 	REP(s,n) {
 		vector<int> cycle;
 		buildcycle(s,cycle);
 		if(SZ(cycle)>0) cycles.PB(cycle);
 	}
 	//printf("npaths=%d cycles=%d\n",SZ(paths),SZ(cycles));
 
 	REP(i,n) cycleid[i]=-1,fstcycleoff[i]=-1;
 	REPSZ(i,cycles) REPSZ(j,cycles[i]) {
 		int x=cycles[i][j],b=gto[x],a=gto[x^1];
 		if(cycleid[a]==-1) cycleid[a]=i,fstcycleoff[a]=j; else assert(cycleid[a]==i);
 	}
 	//REP(i,n) printf("%d: %d %d\n",i,cycleid[i],fstcycleoff[i]);
 
 	REP(i,m) ret[i]=0;
 	REPSZ(i,cycles) REPSZ(j,cycles[i]) {
 		int x=cycles[i][j],b=gto[x],a=gto[x^1];
 		if(x%2==0) ++ret[x>>1]; else --ret[x>>1];
 	}
 	//REPSZ(i,cycles) { printf("c%d:",i); REPSZ(j,cycles[i]) printf(" %d",cycles[i][j]); puts(""); }
 	REPSZ(i,paths) {
 		int s=gto[paths[i][0]^1],t=gto[paths[i][SZ(paths[i])-1]];
 		assert(cycleid[s]!=-1&&cycleid[t]!=-1); if(cycleid[s]!=cycleid[t]) return false;
 		int ii=cycleid[s],j1=fstcycleoff[s],j2=fstcycleoff[t],dir=1; if(j1>j2) swap(j1,j2),dir=0;
 		//printf("s=%d t=%d ii=%d j1=%d j2=%d dir=%d\n",s,t,ii,j1,j2,dir);
 		FOR(j,j1,j2) {
 			int x=cycles[ii][j],b=gto[x],a=gto[x^1];
 			if(x%2==0) ++ret[x>>1]; else --ret[x>>1];
 		}
 		REPSZ(j,paths[i]) {
 			int x=paths[i][j],b=gto[x],a=gto[x^1];
 			if(x%2==dir) ++ret[x>>1]; else --ret[x>>1];
 		}
 	}
 	return true;
 }
 
 int chk[MAXN];
 void check() {
 	REP(i,m) if(ret[i]==0) printf("ret[%d]=0\n",i); else if(abs(ret[i])>n*n) printf("ret[%d] is too large (%d)\n",ret[i],n*n);
 	REP(i,n) chk[i]=0; REP(i,m) chk[gto[2*i+0]]+=ret[i],chk[gto[2*i+1]]-=ret[i]; REP(i,n) if(chk[i]!=0) printf("chk[%d]=%d\n",i,chk[i]);
 }
 
 
 
 void run(int casenr) {
 	scanf("%d%d",&n,&m);
 	REP(i,n) ghead[i]=-1,gdeg[i]=0;
 	REP(i,m) {
 		int a,b; scanf("%d%d",&a,&b); --a,--b;
 		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++gdeg[a];
 		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++gdeg[b];
 	}
 	//printf("%d %d\n",n,m); REP(i,m) printf("%d %d\n",gto[2*i+1]+1,gto[2*i+0]+1);return;
 	if(!solve()) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 	printf("Case #%d:",casenr); REP(i,m) printf(" %d",ret[i]); puts("");
 	check();
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
