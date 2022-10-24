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
 
 int F,P;
 int A[2020],B[2020];
 int mat[1010][1010];
 vector<int> out[2020];
 vector<int> in[2020];
 int val[2020];
 
 int dfs(int cur,int T) {
 	int i;
 	if(cur==P) {
 		int num[12]={};
 		FOR(i,P) {
 			num[A[i]]+=val[i];
 			num[B[i]]-=val[i];
 		}
 		FOR(i,F) if(num[i]) return 0;
 		_P("Case #%d:",T);
 		FOR(i,P) _P(" %d",val[i]);
 		_P("\n");
 		return 1;
 	}
 	int ret=0;
 	for(int i=-3;i<=3;i++) if(i) {
 		val[cur]=i;
 		if(dfs(cur+1,T)) return 1;
 	}
 	return 0;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>F>>P;
 	MINUS(mat);
 	FOR(i,F) {
 		out[i].clear();
 		in[i].clear();
 	}
 	FOR(i,P) {
 		cin>>A[i]>>B[i];
 		A[i]--,B[i]--;
 		mat[A[i]][B[i]]=i;
 		out[A[i]].push_back(B[i]);
 		in[B[i]].push_back(A[i]);
 	}
 	
 	if(dfs(0,_loop)==0) {
 		_P("Case #%d: IMPOSSIBLE\n",_loop);
 	}
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
 
 
