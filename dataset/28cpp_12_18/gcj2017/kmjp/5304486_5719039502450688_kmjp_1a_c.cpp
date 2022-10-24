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
 
 int HD,AD,HK,AK,B,D;
 int memo[101][101][201];
 
 int dpdp(int H,int A,int L) {
 	if(L<=0) return 0;
 	if(H<=0) return 1000;
 	
 	if(memo[H][A][L]>=0) return memo[H][A][L];
 	memo[H][A][L]=1000;
 	int ret=1000;
 	// attack
 	ret=min(ret,1+dpdp(H-A,A,L-1));
 	// debuff
 	if(D) ret=min(ret,1+dpdp(H-max(0,A-D),max(0,A-D),L));
 	// cure
 	ret=min(ret,1+dpdp(HD-A,A,L));
 	return memo[H][A][L]=ret;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>HD>>AD>>HK>>AK>>B>>D;
 	
 	int mia=1010;
 	FOR(i,100) {
 		int at=AD+B*i;
 		mia=min(mia,i+(HK+(at-1))/at);
 	}
 	MINUS(memo);
 	int ret=dpdp(HD,AK,mia);
 	if(ret>=1000) _P("Case #%d: IMPOSSIBLE\n",_loop);
 	else _P("Case #%d: %d\n",_loop,ret);
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
 
 
