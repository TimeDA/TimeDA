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
 
 ll Hd,Ad,Hk,Ak,B,D;
 
 ll calcneed() { // how many buff+attack moves do we need
 	// min x+y s.t. y*(Ad+x*B)>=Hk 
 	ll x=0,ret=x+(Hk+Ad+x*B-1)/(Ad+x*B);
 	//printf("\tinit=%lld\n",ret);
 	for(++x;;++x) {
 		ll cur=x+(Hk+Ad+x*B-1)/(Ad+x*B);
 		//printf("\tcur=%lld %lld+%lld/%lld [%lld,%lld,%lld]\n",cur,x,Hk,Ad+x*B,Ad,x,B);
 		if(cur<ret) ret=cur; else { --x; break; }
 	}
 	//printf("\tx=%lld\n",x);
 	return ret;
 }
 
 ll calchave(ll damage, ll nd) {
 	if(Ak-nd*D<=0) return LLONG_MAX;
 	if(damage>=Hd) return 0;
 	return (Hd-damage+Ak-nd*D-1)/(Ak-nd*D);
 }
 
 ll calc(ll taken,ll damage,ll need) {
 	ll have0=calchave(damage,0);
 	if(need<=have0) return taken+need;
 	if(have0==0) return -1;
 	need-=have0-1;
 	taken+=have0;
 	damage=Ak;
 	ll have=calchave(damage,0);
 	if(need<=have) return taken+need;
 	if(have<=1) return -1;
 	ll full=need/(have-1),rem=need%(have-1); --full,rem+=have-1;
 	need-=full*(have-1);
 	taken+=full*have;
 	if(need<=have) return taken+need;
 	need-=have-1;
 	taken+=have;
 	assert(need<=have); return taken+need;
 }
 
 bool simulatedebuff(ll &taken,ll &damage,ll times) {
 	// damage+(Ak-D)+(Ak-2*D)+(Ak-x*D)>=Hd
 	// damage+x*Ak-D*x*(x+1)/2>=Hd
 	while(times>0) {
 		if(damage+Ak-D>=Hd) ++taken,damage=Ak;
 		if(damage+Ak-D>=Hd) return false;
 		ll l=1,h=2; while(h<=times&&damage+h*Ak-D*h*(h+1)/2<Hd) l=h,h+=h;
 		while(l+1<h) { ll m=l+(h-l)/2; if(m<=times&&damage+m*Ak-D*m*(m+1)/2<Hd) l=m; else h=m; }
 		ll now=min(times,h-1);
 		//printf("damage=%lld Ak=%lld D=%lld Hd=%lld -> %lld -> %lld\n",damage,Ak,D,Hd,h-1,now);
 		times-=now; taken+=now; damage+=now*Ak-D*now*(now+1)/2; Ak-=now*D; assert(times==0||damage<Hd&&damage+Ak-D>=Hd);
 	}
 	return true;
 }
 
 ll solve() {
 	//puts("");
 	ll need=calcneed();
 	//printf("need=%lld\n",need);
 
 	ll ret=-1,taken=0,damage=0;
 	// no debuf
 	{ ll cur=calc(taken,damage,need); if(ret==-1||cur<ret) ret=cur; }
 
 	// debuff so after a heal, we get more turns
 	if(D>=1) while(Ak>0) {
 		ll now=calchave(Ak,0);
 		ll once=calchave(Ak-D,1);
 		ll times;
 		if(once>now) {
 			times=1;
 		} else {
 			ll l=1,h=2; while(calchave(Ak-h*D,h)==now) l=h,h+=h;
 			while(l+1<h) { ll m=l+(h-l)/2; if(calchave(Ak-m*D,m)==now) l=m; else h=m; }
 			times=h;
 		}
 		//printf("%lld -> %lld (%lld -> %lld)\n",Ak,Ak-times*D,calchave(Ak,0),calchave(Ak-times*D,times));
 		if(!simulatedebuff(taken,damage,times)) break;
 		ll cur=calc(taken,damage,need); if(ret==-1||cur<ret) ret=cur;
 	}
 
 	return ret;
 }
 
 ll bfcalc(ll nd,ll nb) {
 	ll damage=0,taken=0,cAk=Ak,cAd=Ad,cHk=Hk;
 	//printf("bfcalc(%lld,%lld)\n",nd,nb);
 	while(cHk>0) {
 		//printf("dam=%lld taken=%lld Ak=%lld Ad=%lld Hk=%lld (nd=%lld,nb=%lld)\n",damage,taken,cAk,cAd,cHk,nd,nb);
 		if(damage>=Hd) return -1;
 		if(nd>0) {
 			if(damage+cAk-D>=Hd) { ++taken; damage=cAk; }
 			if(damage+cAk-D>=Hd) return -1;
 			++taken; cAk=max(0LL,cAk-D); damage+=cAk; --nd;
 		} else if(nb>0) {
 			if(damage+cAk>=Hd) { ++taken; damage=cAk; }
 			if(damage+cAk>=Hd) return -1;
 			++taken; cAd+=B; damage+=cAk; --nb;
 		} else {
 			if(cHk-cAd<=0) return taken+1;
 			if(damage+cAk>=Hd) { ++taken; damage=cAk; }
 			if(damage+cAk>=Hd) return -1;
 			++taken; cHk-=cAd; damage+=cAk;
 		}
 	}
 	return taken;
 }
 ll bf() {
 	ll ret=-1;
 	for(ll nd=0;;++nd) {
 		ll eAk=Ak-nd*D;
 		for(ll nb=0;;++nb) {
 			ll eAd=Ad+nb*B;
 			ll cur=bfcalc(nd,nb);
 			if(ret==-1||cur<ret) ret=cur;
 			if(eAd>=Hk||B==0) break;
 		}
 		if(eAk<=0||D==0) break;
 	}
 	return ret;
 }
 
 void run(int casenr) {
 	scanf("%lld%lld%lld%lld%lld%lld",&Hd,&Ad,&Hk,&Ak,&B,&D);
 	ll chk=bf();
 	//ll ret=solve();
 	//if(ret!=chk) fprintf(stderr,"case %d: ret=%lld vs chk=%lld\n",casenr,ret,chk);
 	ll ret=chk;
 	if(ret==-1) printf("Case #%d: IMPOSSIBLE\n",casenr); else printf("Case #%d: %lld\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
