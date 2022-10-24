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
#include <cstring>
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

const int MAXW=100;
const int MAXH=MAXW;

int w;
int cnt[MAXH];

int h;
char g[MAXH][MAXW+1];

int dst[MAXW];

bool solve() {
	if(cnt[0]==0||cnt[w-1]==0) return false;

	{ int at=0; REP(i,w) REP(j,cnt[i]) dst[at++]=i; assert(at==w); }
	//printf("dst:"); REP(i,w) printf(" %d",dst[i]); puts("");

	h=1; REP(i,w) h=max(h,1+abs(i-dst[i]));
	REP(x,h) { REP(y,w) g[x][y]='.'; g[x][w]='\0'; }
	REP(i,w) {
		if(dst[i]>i&&dst[i-1]!=dst[i]) REP(j,dst[i]-i) g[j][i+j]='\\';
		if(dst[i]<i&&dst[i+1]!=dst[i]) REP(j,i-dst[i]) g[j][i-j]='/';
	}


	return true;
}

void run(int casenr) {
	scanf("%d",&w); REP(i,w) scanf("%d",&cnt[i]);
	if(!solve()) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
	printf("Case #%d: %d\n",casenr,h); REP(x,h) printf("%s\n",g[x]);
}

int have[MAXW];
bool verify() {
	REP(x,h) REP(y,w) if((y==0||y==w-1)&&g[x][y]!='.') return false;
	REP(x,h) REP(y,w-1) if(g[x][y]=='\\'&&g[x][y+1]=='/') return false;
	REP(i,w) have[i]=0;
	REP(i,w) { int y=i; REP(x,h) if(g[x][y]=='\\') ++y; else if(g[x][y]=='/') --y; ++have[y]; }
	//printf("have:"); REP(i,w) printf(" %d",have[i]); puts("");
	REP(i,w) if(have[i]!=cnt[i]) return false;
	return true;

}

void stress() {
	REP(rep,100000) {
		w=2+rand()%(MAXW-2+1); REP(i,w) cnt[i]=0; cnt[0]=cnt[w-1]=1; REP(i,w-2) ++cnt[rand()%w];
		//printf("%d\n",w); REP(i,w) { if(i!=0) printf(" "); printf("%d",cnt[i]); } puts("");
		assert(solve());
		//REP(x,h) printf("%s\n",g[x]);
		assert(verify());
	}
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//stress();
	return 0;
}
