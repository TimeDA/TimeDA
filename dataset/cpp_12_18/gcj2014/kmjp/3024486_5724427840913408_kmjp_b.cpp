#include <cstdlib>
 #include <cstring>
 #include <memory>
 #include <cstdio>
 #include <fstream>
 #include <iostream>
 #include <cmath>
 #include <string>
 #include <sstream>
 #include <stack>
 #include <queue>
 #include <vector>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <sys/time.h>
 using namespace std;
 
 typedef signed long long ll;
 
 #undef _P
 #define _P(...) (void)printf(__VA_ARGS__)
 
 #define FOR(x,to) for(x=0;x<to;x++)
 #define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
 #define ZERO(a) memset(a,0,sizeof(a))
 void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
 #define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
 #define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
 ll GETi() { ll i;scanf("%lld",&i); return i;}
 //-------------------------------------------------------
 
 int P,Q,N;
 int H[105],G[101];
 int S1[105],S2[101];
 map<ll,int> M;
 
 int dodo(int a1,int a2,int a3,int a4) {
 	if(a1<=0 && a2<=0 && a3<=0 && a4<=0) return 0;
 	ll key=a1+a2*1000+a3*1000000LL+a4*1000000000LL;
 	if(M.find(key)!=M.end()) return M[key];
 	
 	int ret=0;
 	// none
 	int x[4],i,j;
 	FOR(i,5) {
 		x[0]=a1;
 		x[1]=a2;
 		x[2]=a3;
 		x[3]=a4;
 		j=0;
 		if(i<4) {
 			if(x[i]<=0) continue;
 			x[i]-=P;
 			if(x[i]<=0) x[i]=0,j+=G[i];
 		}
 		if(x[0]) x[0]=max(0,x[0]-Q);
 		else if(x[1]) x[1]=max(0,x[1]-Q);
 		else if(x[2]) x[2]=max(0,x[2]-Q);
 		else if(x[3]) x[3]=max(0,x[3]-Q);
 		else {
 			ret = max(ret,j);
 			continue;
 		}
 		ret = max(ret, j+dodo(x[0],x[1],x[2],x[3]));
 	}
 	return M[key]=ret;
 	
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>P>>Q>>N;
 	ZERO(H);
 	ZERO(G);
 	FOR(i,N) cin>>H[i]>>G[i];
 	M.clear();
 	
 	_P("Case #%d: %d\n",_loop,dodo(H[0],H[1],H[2],H[3]));
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
 
 
