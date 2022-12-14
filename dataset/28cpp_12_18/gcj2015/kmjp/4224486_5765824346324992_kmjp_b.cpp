#include <bits/stdc++.h>
 #include <sys/time.h>
 using namespace std;
 typedef signed long long ll;
 
 #undef _P
 #define _P(...) (void)printf(__VA_ARGS__)
 #define FOR(x,to) for(x=0;x<to;x++)
 #define FORR(x,arr) for(auto& x:arr)
 #define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
 #define ALL(a) (a.begin()),(a.end())
 #define ZERO(a) memset(a,0,sizeof(a))
 #define MINUS(a) memset(a,0xff,sizeof(a))
 //-------------------------------------------------------
 
 int B,M[1010];
 ll N;
 
 ll numnum(ll tim) {
 	ll tot=0;
 	int i;
 	if(tim<0) return 0;
 	FOR(i,B) tot+=tim/M[i]+1;
 	return tot;
 }
 
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>B>>N;
 	FOR(i,B) cin>>M[i];
 	
 	ll tt=(1LL<<61)-1;
 	for(i=60;i>=0;i--) if(numnum(tt-(1LL<<i))>=N) tt -= (1LL<<i);
 	N-=numnum(tt-1);
 	FOR(i,B) if(tt%M[i]==0) {
 		if(--N==0) return _P("Case #%d: %d\n",_loop,i+1);
 	}
 	
 	_P("Case #%d:\n",_loop);
 }
 
 void init() {
 }
 
 int main(int argc,char** argv){
 	int loop,loops;
 	long long span;
 	char tmpline[1000];
 	struct timeval start,end,ts;
 	
 	if(argc>1) freopen(argv[1], "r", stdin);
 	gettimeofday(&ts,NULL);
 	cin>>loops;
 	init();
 	
 	for(loop=1;loop<=loops;loop++) {
 		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
 		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
 		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
 	}
 	
 	start = ts;
 	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
 	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
 	
 	return 0;
 }
 
 
