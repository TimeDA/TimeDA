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

const int MAXN=100;

int n;
int a[MAXN][MAXN];

vector<pair<int,int> > e[2*MAXN+1];

vector<int> adj[MAXN];

int match[MAXN],mark[MAXN];

bool augment(int at,int curmark) {
	if(mark[at]==curmark) return false; else mark[at]=curmark;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(match[to]==-1||augment(match[to],curmark)) {
			//printf("match %d to %d\n",at,to);
			match[to]=at;
			return true;
		}
	}
	return false;
}

int maxmatch() {
	REP(i,n) match[i]=-1,mark[i]=-1;
	int ret=0;
	REP(i,n) if(augment(i,ret)) ++ret;
	return ret;
}

int solve() {
	REP(i,n) REP(j,n) e[a[i][j]+n].PB(MP(i,j));
	int keep=0;
	REPE(i,2*n) if(SZ(e[i])>0) {
		//printf("%d\n",i-n);
		REPSZ(j,e[i]) adj[e[i][j].first].PB(e[i][j].second);
		//REP(j,n) REPSZ(k,adj[j]) printf("%d-%d\n",j,adj[j][k]);
		keep+=maxmatch();
		REP(j,n) adj[j].clear();
	}
	REPE(i,2*n) e[i].clear();
	return n*n-keep;
}

void run(int casenr) {
	scanf("%d",&n); REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
	printf("Case #%d: %d\n",casenr,solve());
}

void stress() {
	REP(rep,100) {
		n=MAXN; REP(i,n) REP(j,n) a[i][j]=(rand()%2?-1:+1)*(rand()%n+1);
		printf("%d\n",solve());
	}
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//stress();
	return 0;
}
