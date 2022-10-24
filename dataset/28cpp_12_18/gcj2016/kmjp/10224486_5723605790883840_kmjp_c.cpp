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
 int A[6060];
 int room[101][101];
 
 int id(int y,int x) {
 	if(y<0) return x;
 	if(y>=H) return H+2*W-1-x;
 	if(x>=W) return W+y;
 	if(x<0) return 2*(H+W)-y-1;
 }
 // dir:0-up 1:down 2:left 3:right
 
 int go(int y,int x,int dir) {
 	if(y<0 || y>=H || x<0 || x>=W) return id(y,x);
 	if(room[y][x]==0) {
 		// /
 		if(dir==0) return go(y,x+1,3);
 		if(dir==1) return go(y,x-1,2);
 		if(dir==2) return go(y+1,x,1);
 		if(dir==3) return go(y-1,x,0);
 	}
 	else {
 		// 
 		if(dir==0) return go(y,x-1,2);
 		if(dir==1) return go(y,x+1,3);
 		if(dir==2) return go(y-1,x,0);
 		if(dir==3) return go(y+1,x,1);
 	}
 	return -1;
 }
 
 void solve(int _loop) {
 	int f,i,j,k,l,x,y;
 	
 	cin>>H>>W;
 	FOR(i,(H+W)) {
 		cin>>x>>y;
 		x--,y--;
 		A[x]=y;
 		A[y]=x;
 	}
 	for(int mask=0;mask<1<<(H*W);mask++) {
 		FOR(i,H*W) room[i/W][i%W] = (mask>>i)&1;
 		int ng=0;
 		/*
 		FOR(i,W) _P("%d->%d\n",A[i]+1,go(0,i,1)+1), ng+=(A[i]!=go(0,i,1));
 		FOR(i,H) _P("%d->%d\n",A[W+i]+1,go(i,W-1,2)+1), ng+=(A[W+i]!=go(i,W-1,2));
 		FOR(i,W) _P("%d->%d\n",A[W+H+i]+1,go(H-1,W-1-i,0)+1), ng+=(A[W+H+i]!=go(H-1,W-1-i,0));
 		FOR(i,H) _P("%d->%d\n",A[W+H+W+i]+1,go(H-1-i,0,3)+1), ng+=(A[W+H+W+i]!=go(H-1-i,0,3));
 		*/
 		FOR(i,W) ng+=(A[i]!=go(0,i,1));
 		FOR(i,H) ng+=(A[W+i]!=go(i,W-1,2));
 		FOR(i,W) ng+=(A[W+H+i]!=go(H-1,W-1-i,0));
 		FOR(i,H) ng+=(A[W+H+W+i]!=go(H-1-i,0,3));
 		//_P("mask:%d %d\n",mask,ng);
 		
 		if(ng) continue;
 		_P("Case #%d:\n",_loop);
 		FOR(y,H) {
 			FOR(x,W) _P("%c","/\\"[room[y][x]]);
 			_P("\n");
 		}
 		return;
 	}
 	int ok=0;
 	
 	
 	_P("Case #%d:\nIMPOSSIBLE\n",_loop);
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
 
 
