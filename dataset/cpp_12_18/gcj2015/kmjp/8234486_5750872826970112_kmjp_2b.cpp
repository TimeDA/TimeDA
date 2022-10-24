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
 ll V,X;
 vector<pair<ll,ll>> P,P2;
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	double vv,xx;
 	cin>>N>>vv>>xx;
 	V = vv*10000+0.1;
 	X = xx*10000+0.1;
 	
 	P.clear();
 	P2.clear();
 	P2.resize(N);
 	FOR(i,N) {
 		cin>>vv>>xx;
 		P2[i].second=vv*10000+0.1;
 		P2[i].first=xx*10000+0.1;
 	}
 	sort(ALL(P2));
 	FOR(i,N) {
 		if(P.empty() || P.back().first!=P2[i].first) {
 			P.push_back(P2[i]);
 		}
 		else P.back().second += P2[i].second;
 	}
 	
 	N=P.size();
 	if(N==1) {
 		if(P[0].first==X) {
 			_P("Case #%d: %.12lf\n",_loop,1.0*V/P[0].second);
 		}
 		else {
 			_P("Case #%d: IMPOSSIBLE\n",_loop);
 		}
 	}
 	else if(N==2) {
 		if(P[0].first==X) {
 			_P("Case #%d: %.12lf\n",_loop,1.0*V/P[0].second);
 		}
 		else if(P[1].first==X) {
 			_P("Case #%d: %.12lf\n",_loop,1.0*V/P[1].second);
 		}
 		else if(P[0].first<X && X<P[1].first) {
 			double p0=(P[1].first-X)*1.0/(P[1].first-P[0].first);
 			double p1=1-p0;
 			
 			double a0=V*p0/P[0].second;
 			double a1=V*p1/P[1].second;
 			_P("Case #%d: %.12lf\n",_loop,max(a0,a1));
 			
 		}
 		else {
 			_P("Case #%d: IMPOSSIBLE\n",_loop);
 		}
 		
 	}
 	else {
 		_P("Case #%d: H\n",_loop);
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
 
 
