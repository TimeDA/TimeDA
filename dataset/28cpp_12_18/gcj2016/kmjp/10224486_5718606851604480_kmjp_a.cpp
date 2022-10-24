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
 
 int N,R,P,S;
 
 vector<int> ok(vector<int> V) {
 	vector<int> O=V;
 	while(V.size()>1) {
 		vector<int> VV;
 		for(int i=0;i<V.size();i+=2) {
 			if(V[i]==V[i+1]) return {};
 			if(V[i]+V[i+1]==1) VV.push_back(0);
 			if(V[i]+V[i+1]==3) VV.push_back(1);
 			if(V[i]+V[i+1]==2) VV.push_back(2);
 		}
 		V=VV;
 	}
 	return O;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	char SS[4]="PRS";
 	cin>>N>>R>>P>>S;
 	vector<int> V;
 	FOR(i,R) V.push_back(1);
 	FOR(i,P) V.push_back(0);
 	FOR(i,S) V.push_back(2);
 	sort(ALL(V));
 	vector<int> R;
 	do {
 		vector<int> R2=ok(V);
 		if(R2.size()) {
 			if(R.empty()) R=R2;
 			else R=min(R,R2);
 		}
 	} while(next_permutation(ALL(V)));
 	
 	if(R.empty()) {
 		_P("Case #%d: IMPOSSIBLE\n",_loop);
 	}
 	else {
 		_P("Case #%d: ",_loop);
 		FORR(r,R) _P("%c",SS[r]);
 		_P("\n");
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
 
 
