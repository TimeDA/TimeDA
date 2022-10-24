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
 const int MAXN=202;
 
 int h,w,n;
 int match[MAXN];
 bool done[MAXN];
 char g[MAXH][MAXW+1];
 
 int getx(int idx) {
 	if(idx<w) return 0; else idx-=w;
 	if(idx<h) return idx; else idx-=h;
 	if(idx<w) return h-1; else idx-=w;
 	if(idx<h) return h-idx-1; else idx-=h;
 	assert(false); return -1;
 }
 int gety(int idx) {
 	if(idx<w) return idx; else idx-=w;
 	if(idx<h) return w-1; else idx-=h;
 	if(idx<w) return w-idx-1; else idx-=w;
 	if(idx<h) return 0; else idx-=h;
 	assert(false); return -1;
 }
 int getz(int idx) {
 	if(idx<w) return 0; else idx-=w;
 	if(idx<h) return 1; else idx-=h;
 	if(idx<w) return 2; else idx-=w;
 	if(idx<h) return 3; else idx-=h;
 	assert(false); return -1;
 }
 bool augment(int sx,int sy,int sz,int tx,int ty,int tz) {
 	//printf("augment(%d,%d,%d -> %d,%d,%d)\n",sx,sy,sz,tx,ty,tz);
 	//REP(x,h) printf("%s\n",g[x]);
 	while(true) {
 		if(g[sx][sy]=='?') g[sx][sy]=sz%2==0?'\\':'/';
 		if(g[sx][sy]=='\\') sz=sz^1; else sz=3-sz;
 		if(sx==tx&&sy==ty&&sz==tz) return true;
 		if(sz==0) --sx; else if(sz==1) ++sy; else if(sz==2) ++sx; else if(sz==3) --sy; else assert(false);
 		if(sx<0||sx>=h||sy<0||sy>=w) return false;
 		sz^=2;
 		//printf("\t(%d,%d,%d)\n",sx,sy,sz);
 	}
 }
 
 
 void solve() {
 	REP(i,n) done[i]=false;
 	REP(x,h) { REP(y,w) g[x][y]='?'; g[x][w]='\0'; }
 	while(true) {
 		bool found=false;
 		REP(i,n) if(!done[i]) {
 			int j=(i+1)%n; while(done[j]&&j!=match[i]) j=(j+1)%n;
 			if(j!=match[i]) continue;
 			//printf("%d to %d\n",i,j);
 			found=true;
 			if(!augment(getx(i),gety(i),getz(i),getx(j),gety(j),getz(j))) return;
 			done[i]=done[j]=true;
 			break;
 		}
 		if(!found) return;
 	}
 }
 
 void run(int casenr) {
 	scanf("%d%d",&h,&w); n=2*(h+w); REP(i,n/2) { int a,b; scanf("%d%d",&a,&b); --a,--b; match[a]=b; match[b]=a; }
 	solve();
 	printf("Case #%d:\n",casenr);
 	REP(i,n) if(!done[i]) { printf("IMPOSSIBLE\n"); return; }
 	REP(x,h) REP(y,w) if(g[x][y]=='?') g[x][y]='\\';
 	REP(x,h) printf("%s\n",g[x]);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
