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
 int A[101];
 string E;
 int M;
 string C[5];
 vector<int> R[101],ST;
 
 string S;
 
 unordered_set<string> U;
 int sub[101];
 double pat[101];
 
 mt19937 mt;
 
 double comb(int P_,int Q_) {
 	static const int N_=102;
 	static double C_[N_][N_];
 	
 	if(C_[0][0]==0) {
 		int i,j;
 		FOR(i,N_) C_[i][0]=C_[i][i]=1;
 		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
 	}
 	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
 	return C_[P_][Q_];
 }
 
 string hoge() {
 	string ret="";
 	uniform_real_distribution<double> hogege(0,1);
 	
 	vector<int> C=R[0];
 	while(C.size()) {
 		
 		int pos = mt()%C.size();
 		int cur=C[pos];
 		ret+=cur;
 		swap(C[pos],C[C.size()-1]);
 		C.pop_back();
 		FORR(r,R[cur]) C.push_back(r);
 	}
 	return ret;
 	
 }
 
 void dfs(int cur) {
 	sub[cur]=1;
 	pat[cur]=1;
 	FORR(r,R[cur]) {
 		dfs(r);
 		sub[cur]+=sub[r];
 		pat[cur]*=pat[r];
 		pat[cur]*=comb(sub[cur],sub[r]);
 	}
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>N;
 	FOR(i,N+1) R[i].clear(), pat[i]=-1, sub[i]=-1;
 	FOR(i,N) {
 		cin>>A[i+1];
 		R[A[i+1]].push_back(i+1);
 	}
 	cin>>E;
 	cin>>M;
 	FOR(i,M) cin>>C[i];
 	dfs(0);
 	
 	U.clear();
 	struct timeval start,end,ts;
 	int hit[6]={};
 	int tot=0,nl=0;
 	gettimeofday(&start,NULL);
 	srand(start.tv_usec);
 	while(1) {
 		FOR(i,100) {
 			string ret=hoge();
 			nl++;
 			if(U.count(ret)) continue;
 			U.insert(ret);
 			string RC="";
 			FORR(r,ret) if(r) RC+=E[r-1];
 			
 			FOR(j,M) if(RC.find(C[j])!=string::npos) hit[j]++;
 			tot++;
 		}
 		gettimeofday(&end,NULL);
 		long long span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
 		if(span>400000) break;
 	}
 	
 	
 	_P("Case #%d:",_loop);
 	FOR(i,M) _P(" %.3lf",hit[i]*1.0/tot);
 	//_P("  :%d/%d",tot,nl);
 	_P("\n");
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
 
 
