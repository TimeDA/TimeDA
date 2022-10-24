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
 
 ll guarantee(int n,ll p) {
 	if(p>=(1LL<<n)) return (1LL<<n)-1;
 	if(p<=(1LL<<(n-1))) return 0;
 	ll sub=guarantee(n-1,p-(1LL<<(n-1)));
 	return 2+2*sub;
 }
 
 ll possible(int n,ll p) {
 	if(p>=(1LL<<n)) return (1LL<<n)-1;
 	if(p>=(1LL<<(n-1))) return (1LL<<n)-2;
 	ll sub=possible(n-1,p);
 	return 2*sub;
 }
 
 
 void run(int casenr) {
 	int n; ll p; scanf("%d%lld",&n,&p);
 	printf("Case #%d: %lld %lld\n",casenr,guarantee(n,p),possible(n,p));
 }
 
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
