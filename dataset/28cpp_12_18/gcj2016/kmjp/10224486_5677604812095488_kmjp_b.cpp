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
 
 int N,K;
 double P[1010];
 double Q[1010];
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N>>K;
 	FOR(i,N) cin>>P[i];
 	double ma=0;
 	for(int mask=0;mask<1<<N;mask++) if(__builtin_popcount(mask)==K) {
 		j=0;
 		FOR(i,N) if(mask&(1<<i)) Q[j++]=P[i];
 		double t=0;
 		for(int mask2=0;mask2<1<<K;mask2++) if(__builtin_popcount(mask2)==K/2) {
 			double p=1;
 			FOR(i,K) {
 				if(mask2&(1<<i)) p *= Q[i];
 				else p *= (1-Q[i]);
 			}
 			t+=p;
 		}
 		ma=max(ma,t);
 	}
 	
 	
 	_P("Case #%d: %.12lf\n",_loop,ma);
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
 
 
