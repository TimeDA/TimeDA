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
 
 int N,D;
 ll S[1010101],M[1010101];
 int P[1010101];
 int num[1010101];
 
 ll A,C,R;
 
 int dodo(int lo,int hi) {
 	int i;
 	ZERO(num);
 	for(i=N-1;i>=0;i--) {
 		num[i]++;
 		if(S[i]<lo || hi<S[i]) num[i]=0;
 		if(i) num[P[i]] += num[i];
 	}
 	return num[0];
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N>>D;
 	cin>>S[0]>>A>>C>>R;
 	for(i=0;i<N;i++) S[i+1]=(S[i]*A+C)%R;
 	cin>>M[0]>>A>>C>>R;
 	for(i=0;i<N;i++) M[i+1]=(M[i]*A+C)%R;
 	for(i=1;i<N;i++) P[i]=M[i]%i;
 	
 	int ret=0;
 	FOR(i,N) ret=max(ret,dodo(S[i],S[i]+D));
 	
 	_P("Case #%d: %d\n",_loop,ret);
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
 
 
