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
 vector<int> P[1010];
 map<string,int> M;
 int type[4040];
 
 vector<string> split(const string str, char delim){
 	vector<string> res;
 	size_t current = 0, found;
 	while((found = str.find_first_of(delim, current)) != string::npos){
 		res.push_back(string(str, current, found - current));
 		current = found + 1;
 	}
 	res.push_back(string(str, current, str.size() - current));
 	return res;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	string s;
 	
 	cin>>N;
 	getline(cin,s);
 	M.clear();
 	
 	FOR(i,N) {
 		getline(cin,s);
 		vector<string> VS=split(s,' ');
 		
 		P[i].clear();
 		FORR(r,VS) {
 			if(M.count(r)==0) M[r]=M.size()-1;
 			P[i].push_back(M[r]);
 		}
 		sort(ALL(P[i]));
 		P[i].erase(unique(ALL(P[i])), P[i].end());
 	}
 	
 	int W=M.size();
 	int mi=101010;
 	for(int mask=2;mask<1<<N;mask+=4) {
 		ZERO(type);
 		FOR(i,N) {
 			FORR(r,P[i]) type[r] |= 1<<((mask&(1<<i))>0);
 		}
 		x=0;
 		FOR(i,W) if(type[i]==3) x++;
 		mi=min(mi,x);
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
 
 
