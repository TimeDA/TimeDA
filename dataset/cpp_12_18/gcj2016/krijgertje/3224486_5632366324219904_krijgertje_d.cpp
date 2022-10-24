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
 
 const int MAXN=100;
 const int MAXLEN=50;
 
 int n,len;
 char g[MAXN][MAXLEN+1];
 char b[MAXLEN+1];
 
 void run(int casenr) {
 	scanf("%d%d",&n,&len);
 	REP(i,n) scanf("%s",g[i]);
 	scanf("%s",b);
 	REP(i,n) if(strcmp(g[i],b)==0) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 	
 	printf("Case #%d: ",casenr);
 	if(len==1) {
 		printf("0? 0\n");
 	} else {
 		REP(i,len-1) printf("?"); printf(" "); REP(i,(len-1+1)/2) printf("01"); printf("0?"); REP(i,(len-1+1)/2) printf("01"); puts("");
 	}
 }
 
 int main() {
 
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
