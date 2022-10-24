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

const int MAXN=26;

int n;
int cnt[MAXN];

void run(int casenr) {
	scanf("%d",&n); REP(i,n) scanf("%d",&cnt[i]);
	int a=-1,b=-1; REP(i,n) if(a==-1||cnt[i]>cnt[a]) b=a,a=i; else if(b==-1||cnt[i]>cnt[b]) b=i;
	printf("Case #%d:",casenr);
	while(cnt[a]>cnt[b]) printf(" %c",'A'+a),--cnt[a]; 
	REP(i,n) if(i!=a&&i!=b) while(cnt[i]>0) printf(" %c",'A'+i),--cnt[i];
	while(cnt[a]>0||cnt[b]>0) printf(" %c%c",'A'+a,'A'+b),--cnt[a],--cnt[b];
	puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
