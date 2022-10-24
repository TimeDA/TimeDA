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
 
 const int MAXN=25;
 const int MAXG=12;
 
 int n;
 char g[MAXN][MAXN+1];
 bool done[MAXN];
 
 int gr[MAXG],gc[MAXG],ng;
 int mem[1<<MAXG][MAXN][MAXN];
 int go(int mask,int rleft,int cleft) {
 	if(mask==0) { assert(rleft==cleft); return rleft; }
 	int &ret=mem[mask][rleft][cleft];
 	if(ret==-1) {
 		ret=INT_MAX;
 		int other=(1<<ng)-1-mask;
 		for(int sub=(other+1)&~other;sub<(1<<ng);sub=(sub+other+1)&~other) {
 			int rsum=0,csum=0;
 			REP(i,ng) if(sub&(1<<i)) rsum+=gr[i],csum+=gc[i];
 			int mx=max(rsum,csum);
 			if(mx-rsum>rleft||mx-csum>cleft) continue;
 			int cur=go(mask-sub,rleft-(mx-rsum),cleft-(mx-csum));
 			if(cur==INT_MAX) continue;
 			cur+=mx*mx;
 			if(cur<ret) ret=cur;
 		}
 	}
 	return ret;
 }
 
 
 int bcnt(int x) { int ret=0; while(x>0) ret+=x&1,x>>=1; return ret; }
 void run(int casenr) {
 	scanf("%d",&n); REP(i,n) scanf("%s",g[i]);
 	REP(i,n) done[i]=false;
 	int need=0,cleft=n,rleft=n; ng=0;
 	REP(x,n) fprintf(stderr,"%s\n",g[x]);
 	REP(i,n) if(!done[i]) {
 		int rmask=1<<i,cmask=0; done[i]=true;
 		while(true) {
 			bool change=false;
 			REP(x,n) REP(y,n) if(g[x][y]=='1'&&(((rmask>>x)&1)==1||((cmask>>y)&1)==1)&&(((rmask>>x)&1)==0||((cmask>>y)&1)==0)) { change=true; done[x]=true; rmask|=1<<x; cmask|=1<<y; }
 			if(!change) break;
 		}
 		int rcnt=bcnt(rmask),ccnt=bcnt(cmask);
 		if(ccnt==0) continue;
 		fprintf(stderr,"\t%d*%d\n",rcnt,ccnt);
 		rleft-=rcnt; cleft-=ccnt;
 		if(rcnt==ccnt) { need+=rcnt*ccnt; continue; }
 		gr[ng]=rcnt,gc[ng]=ccnt,++ng;
 	}
 	memset(mem,-1,sizeof(mem));
 	need+=go((1<<ng)-1,rleft,cleft);
 	int have=0; REP(x,n) REP(y,n) if(g[x][y]=='1') ++have;
 	printf("Case #%d: %d\n",casenr,need-have);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
