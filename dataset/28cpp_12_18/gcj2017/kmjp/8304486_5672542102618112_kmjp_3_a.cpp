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
 
 int nex[6][100000];
 ll p10[11];
 vector<int> pre[6][100000];
 int D;
 string S;
 int T;
 int did[101010];
 
 int getdecay(int num,int d) {
 	int i;
 	int cnt[10]={};
 	
 	FOR(i,d) {
 		if(num%10>d) return 0;
 		if(num%10) cnt[num%10]++;
 		num/=10;
 	}
 	int v=0;
 	for(i=1;i<=d;i++) v=v*10+cnt[i];
 	return v;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>S;
 	D=S.size();
 	T=0;
 	FORR(c,S) T=T*10+c-'0';
 	ZERO(did);
 	
 	int num=0;
 	queue<int> Q;
 	
 	did[T]=1;
 	Q.push(T);
 	while(Q.size()) {
 		x = Q.front();
 		Q.pop();
 		num++;
 		FORR(e,pre[D][x]) if(did[e]==0) Q.push(e),did[e]=1;
 	}
 	
 	
 	_P("Case #%d: %d\n",_loop,num);
 }
 
 void init() {
 	int f,i,j,k,l,x,y;
 	p10[0]=1;
 	FOR(i,9) p10[i+1]=p10[i]*10;
 	
 	for(i=1;i<=5;i++) {
 		for(j=1;j<p10[i];j++) {
 			nex[i][j]=getdecay(j,i);
 			if(nex[i][j]==0) continue;
 			pre[i][nex[i][j]].push_back(j);
 		}
 	}
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
 
 
