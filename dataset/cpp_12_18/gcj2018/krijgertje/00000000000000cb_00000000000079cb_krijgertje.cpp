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

const int MAXN=100000;

int n;
int v[MAXN];

int o[MAXN],no;
int e[MAXN],ne;

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&v[i]);

	no=ne=0; REP(i,n) if(i%2==0) e[ne++]=v[i]; else o[no++]=v[i];
	sort(e,e+ne); sort(o,o+no);
	REP(i,n) v[i]=i%2==0?e[i/2]:o[i/2];
	REP(i,n-1) if(v[i]>v[i+1]) { printf("Case #%d: %d\n",casenr,i); return; }
	printf("Case #%d: OK\n",casenr);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
