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
 
 int N;
 int A[1001];
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N;
 	FOR(i,N) cin>>A[i];
 	map<int,int> M;
 	FOR(i,N) M[A[i]]=0;
 	i=0;
 	ITR(it,M) it->second=i++;
 	vector<int> V;
 	FOR(i,N) V.push_back(M[A[i]]);
 	int ret=0;
 	FOR(i,N) {
 		FOR(j,V.size()) if(V[j]==i) break;
 		ret+=min(j,(int)V.size()-1-j);
 		V.erase(V.begin()+j);
 	}
 	
 	
 	
 	
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
 
 
