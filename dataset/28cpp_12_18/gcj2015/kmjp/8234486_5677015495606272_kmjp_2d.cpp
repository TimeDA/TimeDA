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
 
 int R,C;
 ll mo=1000000007;
 
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>R>>C;
 	
 	if(R==2) {
 		if(C==3) x=2;
 		if(C==4) x=1;
 		if(C==5) x=1;
 		if(C==6) x=2;
 	}
 	if(R==3) {
 		if(C==3) x=2;
 		if(C==4) x=3;
 		if(C==5) x=2;
 		if(C==6) x=2;
 	}
 	if(R==4) {
 		if(C==3) x=1+2;
 		if(C==4) x=1+0;
 		if(C==5) x=1+0;
 		if(C==6) x=1+2+2;
 	}
 	if(R==5) {
 		if(C==3) x=1+1;
 		if(C==4) x=1+0;
 		if(C==5) x=1+0;
 		if(C==6) x=1+1;
 	}
 	if(R==6) {
 		if(C==3) x=1+1+1+0+0+3+0+0;
 		if(C==4) x=1+0+1+0+1+0+1+0;
 		if(C==5) x=1+0+1+0+0+0+0+0;
 		if(C==6) x=1+1+1+2+0+3+0+2;
 	}
 	
 	
 	
 	_P("Case #%d: %d\n",_loop,x);
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
 
 
