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
 	vector<int> x(n),len(n); REP(i,n) scanf("%d%d",&x[i],&len[i]);
 	int tx; scanf("%d",&tx);
 
 	deque<pair<int,int> > q; q.push_back(MP(2*x[0],x[0])); // (upto x,leftmost prev)
 	FOR(i,1,n) {
 		while(SZ(q)>0&&q.front().first<x[i]) q.pop_front();
 		if(SZ(q)==0) continue;
 		int px=q.front().second;
 		int nupto=x[i]+min(x[i]-px,len[i]);
 //		printf("%d (%d) -> %d\n",x[i],px,nupto);
 		if(nupto>q.back().first) q.push_back(MP(nupto,x[i]));
 	}
 	while(SZ(q)>0&&q.front().first<tx) q.pop_front();
 
 	printf("Case #%d: %s\n",casenr,SZ(q)>0?"YES":"NO");
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
 
  
