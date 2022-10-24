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
 
 int H,W,N,D;
 int Y[202],X[202],V[202];
 ll B[202][202];
 ll mo=1000000007;
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>H>>W>>N>>D;
 	FOR(y,H) FOR(x,W) B[y][x]=1LL<<60;
 	
 	FOR(i,N) {
 		cin>>Y[i]>>X[i]>>V[i];
 		Y[i]--;
 		X[i]--;
 		FOR(y,H) FOR(x,W) B[y][x]=min(B[y][x],V[i]+1LL*(abs(y-Y[i])+abs(x-X[i]))*D);
 	}
 	
 	FOR(i,N) {
 		if(B[Y[i]][X[i]]<V[i]) return _P("Case #%d: IMPOSSIBLE\n",_loop);
 		B[Y[i]][X[i]]=V[i];
 	}
 	
 	ll ret=0;
 	FOR(y,H) FOR(x,W) (ret+=B[y][x])%=mo;
 	_P("Case #%d: %lld\n",_loop,ret);
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
 
 
