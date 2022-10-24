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
 
 const int MAXH=200;
 const int MAXW=200;
 const int MAXV=1000000000;
 const int MOD=1000000007;
 const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
 
 int h,w,n,dst;
 
 int fix[MAXH][MAXW];
 ll mx[MAXH][MAXW];
 pair<int,int> q[MAXH*MAXW]; int qhead,qtail;
 
 void process(int sx,int sy,int sv) {
 	qhead=qtail=0; if(sv<mx[sx][sy]) mx[sx][sy]=sv,q[qhead++]=MP(sx,sy);
 	while(qtail<qhead) {
 		int x=q[qtail].first,y=q[qtail].second; ++qtail;
 		REP(k,4) {
 			int nx=x+DX[k],ny=y+DY[k]; ll nv=mx[x][y]+dst;
 			if(0<=nx&&nx<h&&0<=ny&&ny<w&&nv<mx[nx][ny]) mx[nx][ny]=nv,q[qhead++]=MP(nx,ny);
 		}
 	}
 }
 
 void run(int casenr) {
 	scanf("%d%d%d%d",&h,&w,&n,&dst);
 	REP(i,h) REP(j,w) fix[i][j]=0,mx[i][j]=LLONG_MAX;
 	REP(i,n) {
 		int sx,sy,sv; scanf("%d%d%d",&sx,&sy,&sv); --sx,--sy;
 		process(sx,sy,sv);
 		fix[sx][sy]=max(fix[sx][sy],sv);
 	}
 	REP(x,h) REP(y,w) if(mx[x][y]<fix[x][y]) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 	int ret=0; REP(x,h) REP(y,w) ret=(ret+mx[x][y])%MOD; printf("Case #%d: %d\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
