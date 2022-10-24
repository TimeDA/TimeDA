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
 
 int N;
 int mask[30];
 int mask2[30];
 
 int dfs(int hu,int work) {
 	int i,j;
 	if(hu==0) return 1;
 	FOR(i,N) if(hu&(1<<i)) {
 		int cand=mask2[i]&work;
 		if(cand==0) return 0;
 		FOR(j,N) if(cand&(1<<j)) {
 			if(dfs(hu^(1<<i),work^(1<<j))==0) return 0;
 		}
 	}
 	return 1;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N;
 	FOR(i,N) {
 		string s;
 		cin>>s;
 		mask[i]=0;
 		FOR(j,N) if(s[j]=='1') mask[i] |= 1<<j;
 	}
 	int mi=1010;
 	for(int m=0;m<1<<16;m++) if(__builtin_popcount(m)<mi) {
 		int ng=0;
 		FOR(i,4) if((m>>(i*4))&mask[i]) ng++;
 		if(ng) continue;
 		FOR(i,4) mask2[i]=mask[i] | (m>>(i*4));
 		if(dfs((1<<N)-1,(1<<N)-1)) mi=__builtin_popcount(m);
 	}
 	
 	
 	_P("Case #%d: %d\n",_loop,mi);
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
 
 
