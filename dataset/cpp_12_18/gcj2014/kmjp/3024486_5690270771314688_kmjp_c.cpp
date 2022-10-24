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
 int UE,UL;
 string Q[1001];
 int ID[1001];
 int S[2005]; // 0-out 1-in 2-unstable
 
 
 int dfs(int cur,int pa) {
 	int i,ma=5000;
 	if(cur==N) {
 		int c=0;
 		FOR(i,N+2) c+=S[i]==0;
 		return c;
 	}
 	if(ID[cur]>0) {
 		int pre=S[ID[cur]];
 		if(Q[cur][0]=='E') {
 			if(S[ID[cur]]==0) return 5000;
 			S[ID[cur]]=0;
 		}
 		else {
 			if(S[ID[cur]]==1) return 5000;
 			S[ID[cur]]=1;
 		}
 		ma=dfs(cur+1,pa);
 		S[ID[cur]]=pre;
 	}
 	else {
 		for(i=1;i<=pa+1;i++) {
 			ID[cur] = i;
 			int pre=S[ID[cur]];
 			if(Q[cur][0]=='E') {
 				if(S[ID[cur]]==0) continue;
 				S[ID[cur]]=0;
 			}
 			else {
 				if(S[ID[cur]]==1) continue;
 				S[ID[cur]]=1;
 			}
 			ma=min(ma,dfs(cur+1,pa+(i==pa+1)));
 			S[ID[cur]]=pre;
 		}
 		ID[cur] = 0;
 	}
 	return ma;
 }
 
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	_P("Case #%d: ",_loop);
 	cin>>N;
 	FOR(i,N) cin>>Q[i]>>ID[i];
 	map<int,int> M;
 	FOR(i,N) if(ID[i]>0) {
 		if(M.find(ID[i])==M.end()) M[ID[i]]=M.size();
 	}
 	FOR(i,N) if(ID[i]>0) ID[i]=M[ID[i]];
 	
 	FOR(i,2000+5) S[i]=2;
 	int ret=dfs(0,M.size());
 	if(ret>=5000) _P("CRIME TIME\n");
 	else _P("%d\n",ret);
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
 
 
