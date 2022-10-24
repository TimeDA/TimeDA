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
 
 ll n,k;
 map<ll,ll> mp;
 
 void run(int casenr) {
 	scanf("%lld%lld",&n,&k);
 	mp.clear(); mp[n]=1; ll left=k;
 	while(SZ(mp)>0) {
 		map<ll,ll>::iterator it=mp.end(); --it; ll sz=it->first,cnt=it->second; mp.erase(it);
 		ll lsz=(sz-1)/2,rsz=sz/2;
 		if(left<=cnt) { printf("Case #%d: %lld %lld\n",casenr,rsz,lsz); return; }
 		left-=cnt; if(lsz>0) mp[lsz]+=cnt; if(rsz>0) mp[rsz]+=cnt;
 	}
 	assert(false);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
