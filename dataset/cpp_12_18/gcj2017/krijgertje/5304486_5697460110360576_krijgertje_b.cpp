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
 
 const int MAXN=50;
 const int MAXM=50;
 
 int n,m;
 int need[MAXN];
 int have[MAXN][MAXM];
 int at[MAXN];
 int l[MAXN],r[MAXN];
 
 void run(int casenr) {
 	scanf("%d%d",&n,&m); REP(i,n) scanf("%d",&need[i]); REP(i,n) REP(j,m) scanf("%d",&have[i][j]);
 	REP(i,n) sort(have[i],have[i]+m);
 	REP(i,n) at[i]=0;
 	int ret=0;
 	while(true) {
 		REP(i,n) while(at[i]<m) {
 			int cur=have[i][at[i]];
 			// x*need[i]*1.1>=cur x*need[i]*0.9<=cur
 			l[i]=(10*cur+11*need[i]-1)/(11*need[i]),r[i]=10*cur/(9*need[i]);
 			//printf("\t%d -> %d..%d\n",cur,l[i],r[i]);
 			if(l[i]<=r[i]) break; else ++at[i];
 		}
 		//REP(i,n) if(at[i]>=m) printf("X "); else printf("%d-%d ",l[i],r[i]); puts("");
 		bool done=false; REP(i,n) if(at[i]>=m) done=true; if(done) break;
 		int mxl=l[0],mnr=r[0]; FOR(i,1,n) mxl=max(mxl,l[i]),mnr=min(mnr,r[i]);
 		if(mxl<=mnr) {
 			++ret; REP(i,n) ++at[i];
 		} else {
 			REP(i,n) if(r[i]<mxl) ++at[i];
 		}
 	}
 	printf("Case #%d: %d\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
