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
 
 
 int N,C,M;
 int P[1010],B[1010];
 vector<int> PP[1010];
 
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N>>C>>M;
 	FOR(i,C) PP[i].clear();
 	FOR(i,M) {
 		cin>>P[i]>>B[i];
 		PP[B[i]-1].push_back(P[i]-1);
 	}
 	
 	if(C>2) return;
 	
 	int ma=max({(int)PP[0].size(),(int)PP[1].size(),(int)count(ALL(PP[0]),0)+(int)count(ALL(PP[1]),0)});
 	while(PP[0].size()<ma) PP[0].push_back(1010);
 	while(PP[1].size()<ma) PP[1].push_back(1011);
 	sort(ALL(PP[0]));
 	sort(ALL(PP[1]));
 	
 	int hoge=0;
 	FOR(i,N) {
 		x = count(ALL(PP[0]),i)+count(ALL(PP[1]),i);
 		if(x>ma) hoge=max(hoge,x-ma);
 	}
 	
 	
 	_P("Case #%d: %d %d\n",_loop,ma,hoge);
 	
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
 
 
