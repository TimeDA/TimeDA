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
 
 int N,S;
 int X[1010],Y[1010],Z[1010];
 int VX[1010],VY[1010],VZ[1010];
 int vis[1010];
 double dist[1010][1010];
 
 void dfs(int cur,double v) {
 	int i;
 	vis[cur]=1;
 	FOR(i,N) if(vis[i]==0 && dist[cur][i]<=v) dfs(i,v);
 }
 
 int cango(double v) {
 	ZERO(vis);
 	dfs(0,v);
 	return vis[1];
 	
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N>>S;
 	FOR(i,N) cin>>X[i]>>Y[i]>>Z[i]>>VX[i]>>VY[i]>>VZ[i];
 	FOR(x,N) FOR(y,N) dist[x][y]=sqrt((X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y])+(Z[x]-Z[y])*(Z[x]-Z[y]));
 	
 	
 	double L=0,R=1e9;
 	FOR(i,100) {
 		double M=(L+R)/2;
 		if(cango(M)) R=M;
 		else L=M;
 	}
 	
 	_P("Case #%d: %.12lf\n",_loop,L);
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
 
 
