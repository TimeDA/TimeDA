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
 #include <ctime>
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
 
 int n;
 int a[20],b[20];
 
 bool d[20][20]; // isgreater
 
 bool done[20];
 int ans[20];
 
 bool dfs(int pos) {
 	if(pos>=n) return true;
 	REP(i,n) if(!done[i]) {
 		bool ok=true; REP(j,n) if(d[i][j]&&!done[j]) { ok=false; break; } if(!ok) continue;
 		done[i]=true; ans[i]=pos;
 		if(dfs(pos+1)) return true;
 		done[i]=false; ans[i]=-1;
 	}
 	return false;
 }
 
 void run(int casenr) {
 	scanf("%d",&n);
 	REP(i,n) scanf("%d",&a[i]);
 	REP(i,n) scanf("%d",&b[i]);
 	memset(d,false,sizeof(d));
 	REP(i,n) {
 		for(int j=i-1;j>=0;--j) if(a[i]==a[j]+1) { d[i][j]=true; break; }
 		REP(j,i) if(a[i]<=a[j]) d[j][i]=true;
 	}
 	REP(i,n) {
 		for(int j=i+1;j<n;++j) if(b[i]==b[j]+1) { d[i][j]=true; break; }
 		FOR(j,i+1,n) if(b[i]<=b[j]) d[j][i]=true;
 	}
 
 	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]&&d[k][j]) d[i][j]=true;
 //	REP(i,n) { REP(j,n) printf("%c",d[i][j]?'V':'.'); puts(""); }
 
 	memset(done,false,sizeof(done));
 	assert(dfs(0));
 
 	printf("Case #%d:",casenr); REP(i,n) printf(" %d",ans[i]+1); puts("");
 }
 
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
