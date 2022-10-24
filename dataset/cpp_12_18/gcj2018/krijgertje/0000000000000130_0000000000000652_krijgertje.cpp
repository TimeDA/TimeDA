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

ll n,k;

void run(int casenr) {
	scanf("%lld%lld",&n,&k); --k;
	map<ll,ll> avail; avail[-n]++;
	while(true) {
		assert(SZ(avail)>0);
		ll cur=-avail.begin()->first,cnt=avail.begin()->second; avail.erase(avail.begin());
		ll a=(cur-1)/2,b=cur-a-1;
		//printf("\tk=%lld cnt=%lld cur=%lld a=%lld b=%lld\n",k,cnt,cur,a,b);
		if(k<cnt) {
			printf("Case #%d: %lld %lld\n",casenr,b,a);
			break;
		} else {
			if(a>0) avail[-a]+=cnt; if(b>0) avail[-b]+=cnt; k-=cnt;
		}
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
