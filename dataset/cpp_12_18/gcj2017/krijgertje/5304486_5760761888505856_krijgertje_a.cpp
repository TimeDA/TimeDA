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
 
 const int MAXH=25;
 const int MAXW=25;
 
 int h,w;
 char g[MAXH][MAXW+1];
 bool any[MAXH];
 
 void run(int casenr) {
 	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
 	REP(x,h) any[x]=false; REP(x,h) REP(y,w) if(g[x][y]!='?') any[x]=true;
 	for(int at=0,to=at;at<h;at=to) {
 		int mid=at; while(!any[mid]) ++mid; to=mid+1; while(to<h&&!any[to]) ++to;
 		for(int at2=0,to2=at2;at2<w;at2=to2) {
 			int mid2=at2; while(g[mid][mid2]=='?') ++mid2; to2=mid2+1; while(to2<w&&g[mid][to2]=='?') ++to2;
 			//printf("%d..%d %d..%d (%d,%d) %c\n",at,to-1,at2,to2-1,mid,mid2,g[mid][mid2]);
 			FOR(i,at,to) FOR(j,at2,to2) g[i][j]=g[mid][mid2];
 		}
 	}
 	printf("Case #%d:\n",casenr);
 	REP(x,h) printf("%s\n",g[x]);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
