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
 
 int H,W;
 string S[51];
 int mask[51][51];
 
 int LR[51][51];
 int UD[51][51];
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	MINUS(LR);
 	MINUS(UD);
 	
 	cin>>H>>W;
 	FOR(y,H) cin>>S[y];
 	ZERO(mask);
 	FOR(y,H) FOR(x,W) if(S[y][x]=='-' || S[y][x]=='|') S[y][x]='+';
 	FOR(y,H) FOR(x,W) if(S[y][x]=='+') {
 		mask[y][x]=3;
 		// left
 		for(int x2=x-1;x2>=0;x2--) {
 			if(S[y][x2]=='#') break;
 			if(S[y][x2]=='+') mask[y][x]&=2;
 		}
 		for(int x2=x+1;x2<W;x2++) {
 			if(S[y][x2]=='#') break;
 			if(S[y][x2]=='+') mask[y][x]&=2;
 		}
 		for(int y2=y-1;y2>=0;y2--) {
 			if(S[y2][x]=='#') break;
 			if(S[y2][x]=='+') mask[y][x]&=1;
 		}
 		for(int y2=y+1;y2<H;y2++) {
 			if(S[y2][x]=='#') break;
 			if(S[y2][x]=='+') mask[y][x]&=1;
 		}
 		
 		if(mask[y][x]==0) {
 			_P("Case #%d: IMPOSSIBLE\n",_loop);
 			return;
 		}
 		
 		if(mask[y][x]&1) {
 			for(int x2=x-1;x2>=0;x2--) {
 				if(S[y][x2]!='.') break;
 				LR[y][x2]=x;
 			}
 			for(int x2=x+1;x2<W;x2++) {
 				if(S[y][x2]!='.') break;
 				LR[y][x2]=x;
 			}
 		}
 		if(mask[y][x]&2) {
 			for(int y2=y-1;y2>=0;y2--) {
 				if(S[y2][x]!='.') break;
 				UD[y2][x]=y;
 			}
 			for(int y2=y+1;y2<H;y2++) {
 				if(S[y2][x]!='.') break;
 				UD[y2][x]=y;
 			}
 		}
 	}
 	
 	
 	FOR(j,250) {
 		FOR(i,250) {
 			FOR(y,H) FOR(x,W) {
 				if(S[y][x]=='.') {
 					if(LR[y][x]>=0 && mask[y][LR[y][x]]==1) S[y][x]='o';
 					if(UD[y][x]>=0 && mask[UD[y][x]][x]==2) S[y][x]='o';
 				}
 				if(S[y][x]=='.') {
 					int cand=0;
 					if(LR[y][x]>=0 && (mask[y][LR[y][x]]&1)) cand++;
 					if(UD[y][x]>=0 && (mask[UD[y][x]][x]&2)) cand++;
 					if(cand==1) {
 						if(LR[y][x]>=0 && (mask[y][LR[y][x]]&1)) mask[y][LR[y][x]]=1;
 						if(UD[y][x]>=0 && (mask[UD[y][x]][x]&2)) mask[UD[y][x]][x]=2;
 						S[y][x]='o';
 					}
 				}
 			}
 		}
 		
 		FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
 			if(LR[y][x]>=0 && (mask[y][LR[y][x]]&1)) {
 				S[y][x]='o';
 				mask[y][LR[y][x]]=1;
 				break;
 			}
 			if(UD[y][x]>=0 && (mask[UD[y][x]][x]&2)) {
 				S[y][x]='o';
 				mask[UD[y][x]][x]=2;
 				break;
 			}
 		}
 	}
 	FOR(y,H) FOR(x,W) {
 		if(S[y][x]=='.') {
 			_P("Case #%d: IMPOSSIBLE\n",_loop);
 			return;
 		}
 	}
 	
 	_P("Case #%d: POSSIBLE\n",_loop);
 	FOR(y,H) {
 		FOR(x,W) {
 			if(S[y][x]=='o') S[y][x]='.';
 			if(mask[y][x]&1) S[y][x]='-';
 			if(S[y][x]=='+' && (mask[y][x]&2)) S[y][x]='|';
 		}
 		_P("%s\n",S[y].c_str());
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
 
 
