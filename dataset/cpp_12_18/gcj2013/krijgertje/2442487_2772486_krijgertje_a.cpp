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
 
 const int MOD=1000002013;
 
 typedef struct Pass { int start,end,cnt; } Pass;
 bool operator<(const Pass &a,const Pass &b) {
 	if(a.end!=b.end) return a.end<b.end;
 	if(a.start!=b.start) return a.start<b.start;
 	return false;
 }
 
 
 
 
 int nstop,npass;
 Pass pass[100];
 
 ll getcost(int d) { ll ret=(ll)d*(nstop+nstop-d+1)/2; return ret; }
 
 
 void run(int casenr) {
 	scanf("%d%d",&nstop,&npass);
 	REP(i,npass) scanf("%d%d%d",&pass[i].start,&pass[i].end,&pass[i].cnt);
 
 	vector<pair<int,int> > order; REP(i,npass) order.PB(MP(pass[i].start,i)); sort(order.begin(),order.end());
 
 	vector<Pass> ontrain;
 	REPSZ(i,order) {
 		int at=order[i].second;
 		sort(ontrain.begin(),ontrain.end());
 		vector<Pass> toadd;
 		int left=pass[at].cnt;
 		REPSZ(j,ontrain) {
 			if(left==0) break;
 			if(ontrain[j].end<pass[at].start) continue;
 			if(ontrain[j].end>=pass[at].end) continue;
 			if(ontrain[j].cnt<=left) {
 				Pass nxt; nxt.start=ontrain[j].start; nxt.end=pass[at].end; nxt.cnt=ontrain[j].cnt; toadd.PB(nxt);
 				ontrain[j].start=pass[at].start;
 				left-=ontrain[j].cnt;
 			} else {
 				Pass nxt1; nxt1.start=ontrain[j].start; nxt1.end=pass[at].end; nxt1.cnt=left; toadd.PB(nxt1);
 				Pass nxt2; nxt2.start=pass[at].start; nxt2.end=ontrain[j].end; nxt2.cnt=left; toadd.PB(nxt2);
 				ontrain[j].cnt-=left;
 				left=0;
 			}
 		}
 		if(left>0) {
 			Pass nxt; nxt.start=pass[at].start; nxt.end=pass[at].end; nxt.cnt=left; toadd.PB(nxt);
 		}
 		REPSZ(j,toadd) ontrain.PB(toadd[j]);
 	}
 	ll have=0;
 	REPSZ(j,ontrain) have=(have+ontrain[j].cnt*getcost(ontrain[j].end-ontrain[j].start))%MOD;
 //	REPSZ(j,ontrain) printf("%d times %d->%d\n",ontrain[j].cnt,ontrain[j].start,ontrain[j].end);
 	ll want=0;
 	REP(i,npass) want=(want+pass[i].cnt*getcost(pass[i].end-pass[i].start))%MOD;
 	ll ret=want-have; if(ret<0) ret+=MOD;
 	printf("Case #%d: %lld\n",casenr,ret);
 }
 
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
