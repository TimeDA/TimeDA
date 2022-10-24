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
 
 const int MAXN=1000000;
 
 int n,maxdiff;
 int sal[MAXN],man[MAXN];
 int head[MAXN],nxt[MAXN];
 
 pair<int,int> osal[MAXN];
 
 int cur;
 bool ok[MAXN];
 bool have[MAXN];
 
 void init() {
 	cur=0;
 	REP(i,n) ok[i]=have[i]=false;
 }
 
 void dfs(int at,bool val) {
 	have[at]=val; cur+=val?+1:-1;
 	for(int to=head[at];to!=-1;to=nxt[to]) if(ok[to]) dfs(to,val);
 }
 
 void enable(int at) {
 	ok[at]=true;
 	if(man[at]!=-1&&!have[man[at]]) return;
 	dfs(at,true);
 }
 
 void disable(int at) {
 	ok[at]=false;
 	if(man[at]!=-1&&!have[man[at]]) return;
 	dfs(at,false);
 }
 
 
 int Asal,Csal,Rsal,Aman,Cman,Rman;
 
 void run(int casenr) {
 	scanf("%d%d",&n,&maxdiff);
 	scanf("%d%d%d%d",&sal[0],&Asal,&Csal,&Rsal);
 	scanf("%d%d%d%d",&man[0],&Aman,&Cman,&Rman);
 	FOR(i,1,n) sal[i]=((ll)sal[i-1]*Asal+Csal)%Rsal;
 	FOR(i,1,n) man[i]=((ll)man[i-1]*Aman+Cman)%Rman; man[0]=-1;
 	FOR(i,1,n) man[i]%=i;
 
 	REP(i,n) head[i]=-1;
 	REP(i,n) { nxt[i]=head[man[i]]; head[man[i]]=i; }
 
 	REP(i,n) osal[i]=MP(sal[i],i); sort(osal,osal+n);
 
 	init();
 	int a=0,b=0,ret=0; 
 	while(a<n) {
 		while(b<n&&osal[b].first<=osal[a].first+maxdiff) {
 			enable(osal[b].second);
 			++b;
 		}
 		if(ok[0]&&cur>ret) ret=cur;
 		disable(osal[a].second);
 		++a;
 	}
 	printf("Case #%d: %d\n",casenr,ret);
 
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
