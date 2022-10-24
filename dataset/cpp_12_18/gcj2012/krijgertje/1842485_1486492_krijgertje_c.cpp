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
 #include <deque>
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
 
 void run(int casenr) {
 	int n; scanf("%d",&n);
 	vector<int> see(n-1); REP(i,n-1) { scanf("%d",&see[i]); --see[i]; }
 	vector<vector<int> > seen(n); REP(i,n-1) seen[see[i]].PB(i);
 
 	vector<int> minseenby(n,-1);
 	vector<int> y(n,-1); y[n-1]=100000000; minseenby[n-1]=0;
 	queue<int> q; q.push(n-1);
 	while(!q.empty()) {
 		int at=q.front(); q.pop();
 		if(SZ(seen[at])==0) continue;
 		int first=seen[at][0];
 		//y[first]+(see[at]-first)/(at-first)*(y[at]-y[first])>=y[see[at]]
 		//y[first]<=((see[at]-first)*y[at]-y[see[at]]*(at-first))/(see[at]-at)
 		int ny;
 		if(at==n-1) {
 			ny=y[at]-1;
 		} else {
 			ll num=(ll)(see[at]-first)*y[at]-(ll)y[see[at]]*(at-first),den=see[at]-at;
 			assert(num>=0); assert(den>0);
 			ny=num/den;
 		}
 		REPSZ(i,seen[at]) {
 			int to=seen[at][i]; y[to]=ny; q.push(to);
 			minseenby[to]=i==0?minseenby[at]:seen[at][i-1]+1;
 		}
 	}
 	REP(i,n) if(SZ(seen[i])>0) {
 		if(seen[i][0]<minseenby[i]||seen[i].back()>i-1) {
 				printf("Case #%d: Impossible\n",casenr);
 				return;
 		}
 	}
 
 	int ly=y[0]; REP(i,n) if(y[i]<ly) ly=y[i]; REP(i,n) y[i]-=ly;
 	printf("Case #%d:",casenr); REP(i,n) printf(" %d",y[i]); puts("");
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
 
  
