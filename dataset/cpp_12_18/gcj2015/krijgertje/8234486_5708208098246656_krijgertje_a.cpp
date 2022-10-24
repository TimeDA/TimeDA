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
 
 const int MAXH=100;
 const int MAXW=100;
 const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
 const char DC[]={'^','>','v','<'};
 
 int h,w;
 char g[MAXH][MAXW];
 
 
 void run(int casenr) {
 	scanf("%d%d",&h,&w);
 	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
 	int ret=0; bool ok=true;
 	REP(x,h) REP(y,w) if(g[x][y]!='.') {
 		int can=0;
 		REP(k,4) {
 			int nx=x+DX[k],ny=y+DY[k];
 			while(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]=='.') nx+=DX[k],ny+=DY[k];
 			if(0<=nx&&nx<h&&0<=ny&&ny<w) can|=1<<k;
 		}
 		int ck=0; while(ck<4&&DC[ck]!=g[x][y]) ++ck;
 		if(can&(1<<ck)) continue;
 		if(can==0) ok=false; else ++ret;
 	}
 	if(!ok) printf("Case #%d: IMPOSSIBLE\n",casenr); else printf("Case #%d: %d\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
