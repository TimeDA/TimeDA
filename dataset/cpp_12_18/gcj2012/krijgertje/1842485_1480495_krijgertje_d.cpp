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
 #include <deque>
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
 
 int RDX[]={-1,0,0},RDY[]={0,-1,+1};
 
 int h,w;
 char g[60][60];
 bool ok[60][60];
 bool at[60][60];
 
 
 void run(int casenr) {
 	scanf("%d%d",&h,&w);
 	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
 	printf("Case #%d:\n",casenr);
 	REP(qq,10) {
 		int sx=-1,sy=-1; bool qexists=false;
 		REP(x,h) REP(y,w) if(g[x][y]=='0'+qq) { sx=x; sy=y; qexists=true; }
 		if(!qexists) continue;
 		memset(at,false,sizeof(at));
 		queue<pair<int,int> > q; at[sx][sy]=true; q.push(MP(sx,sy));
 		while(!q.empty()) {
 			int x=q.front().first,y=q.front().second; q.pop();
 			REP(k,3) {
 				int nx=x+RDX[k],ny=y+RDY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#'||at[nx][ny]) continue;
 				at[nx][ny]=true; q.push(MP(nx,ny));
 			}
 		}
 		int scnt=0; REP(x,h) REP(y,w) if(at[x][y]) ++scnt;
 		REP(x,h) REP(y,w) ok[x][y]=at[x][y];
 		
 		while(true) {
 			// move to the left as far as possible
 			REP(x,h) for(int y=w-1;y>=0;--y) if(at[x][y]&&y-1>=0&&g[x][y-1]!='#') { at[x][y]=false; at[x][y-1]=true; }
 //			if(qq==3) { REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } puts("");  }
 			ll cannotmovedown=0,movedownchangesthings=0;
 			REP(x,h) REP(y,w) if(at[x][y]) {
 				int at=0;
 				while(y+at+1<w&&g[x][y+at+1]!='#') {
 					if(x+1<h&&g[x+1][y+at]!='#') {
 						if(ok[x+1][y+at]) {
 							movedownchangesthings|=1LL<<at;
 						} else {
 							cannotmovedown|=1LL<<at;
 						}
 					}
 					++at;
 				}
 				if(x+1<h&&g[x+1][y+at]!='#') {
 					if(ok[x+1][y+at]) {
 						movedownchangesthings|=~((1LL<<at)-1);
 					} else {
 						cannotmovedown|=~((1LL<<at)-1);
 					}
 				}
 			}
 			ll okmask=movedownchangesthings&~cannotmovedown;
 //			if(qq==3) { printf("%llx %llx %llx\n",cannotmovedown,movedownchangesthings,okmask); REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } }
 			if(okmask!=0) {
 				int steps=0; while((okmask&(1LL<<steps))==0) ++steps;
 				REP(x,h) for(int y=w-1;y>=0;--y) if(at[x][y]) {
 					int nx=x,ny=y;
 					REP(i,steps) if(ny+1<w&&g[nx][ny+1]!='#') ++ny;
 					at[x][y]=false; at[nx][ny]=true;
 				}
 	//			REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } puts(""); 
 				for(int x=h-1;x>=0;--x) REP(y,w) if(at[x][y]&&x+1<h&&g[x+1][y]!='#') { at[x][y]=false; at[x+1][y]=true; assert(ok[x+1][y]); }
 				continue;
 			}
 			// move to the right as far as possible
 			REP(x,h) REP(y,w) if(at[x][y]&&y+1<w&&g[x][y+1]!='#') { at[x][y]=false; at[x][y+1]=true; }
 //			if(qq==3) { REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } puts("");  }
 			cannotmovedown=0,movedownchangesthings=0;
 			REP(x,h) REP(y,w) if(at[x][y]) {
 				int at=0;
 				while(y-at-1>=0&&g[x][y-at-1]!='#') {
 					if(x+1<h&&g[x+1][y-at]!='#') {
 						if(ok[x+1][y-at]) {
 							movedownchangesthings|=1LL<<at;
 						} else {
 							cannotmovedown|=1LL<<at;
 						}
 					}
 					++at;
 				}
 				if(x+1<h&&g[x+1][y-at]!='#') {
 					if(ok[x+1][y-at]) {
 						movedownchangesthings|=~((1LL<<at)-1);
 					} else {
 						cannotmovedown|=~((1LL<<at)-1);
 					}
 				}
 			}
 			okmask=movedownchangesthings&~cannotmovedown;
 //			if(qq==3) { printf("%llx %llx %llx\n",cannotmovedown,movedownchangesthings,okmask); REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } }
 			if(okmask!=0) {
 				int steps=0; while((okmask&(1LL<<steps))==0) ++steps;
 				REP(x,h) REP(y,w) if(at[x][y]) {
 					int nx=x,ny=y;
 					REP(i,steps) if(ny-1>=0&&g[nx][ny-1]!='#') --ny;
 					at[x][y]=false; at[nx][ny]=true;
 				}
 	//			REP(x,h) { REP(y,w) printf("%c",at[x][y]?'x':ok[x][y]?'-':g[x][y]); puts(""); } puts(""); 
 				for(int x=h-1;x>=0;--x) REP(y,w) if(at[x][y]&&x+1<h&&g[x+1][y]!='#') { at[x][y]=false; at[x+1][y]=true; assert(ok[x+1][y]); }
 				continue;
 			}
 			break;
 		}
 		int tcnt=0; REP(x,h) REP(y,w) if(at[x][y]) ++tcnt;
 		printf("%d: %d %s\n",qq,scnt,tcnt==1?"Lucky":"Unlucky");
 	}
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
 
  
