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
 
 int C;
 int E[2020],L[2020],D[2020];
 ll ret;
 
 void dfs(int cur,int mask,ll tim) {
 	if(mask==0 && cur==0) {
 		ret=min(ret,tim);
 		return;
 	}
 	
 	int tar=2*cur;
 	if(mask&(1<<tar)) {
 		ll nex=tim;
 		if(nex%24>L[tar]) nex+=24-(nex%24);
 		if(nex%24<L[tar]) nex+=L[tar]-(nex%24);
 		dfs(E[tar],mask^(1<<tar),nex+D[tar]);
 	}
 	tar=2*cur+1;
 	if(mask&(1<<tar)) {
 		ll nex=tim;
 		if(nex%24>L[tar]) nex+=24-(nex%24);
 		if(nex%24<L[tar]) nex+=L[tar]-(nex%24);
 		dfs(E[tar],mask^(1<<tar),nex+D[tar]);
 	}
 	
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>C;
 	FOR(i,2*C) {
 		cin>>E[i]>>L[i]>>D[i];
 		E[i]--;
 	}
 	
 	ret=1LL<<60;
 	dfs(0,(1<<(2*C))-1,0);
 	
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
 
 
