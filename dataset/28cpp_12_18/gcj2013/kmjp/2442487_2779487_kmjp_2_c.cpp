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
 using namespace std;
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <sys/time.h>
 
 typedef signed long long ll;
 typedef unsigned long long ull;
 
 #define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
 #define _E(...) fprintf(stderr, __VA_ARGS__)
 #define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
 #define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
 #undef _P
 #define _P(...) printf(__VA_ARGS__)
 
 #define FOR(x,to) for(x=0;x<to;x++)
 #define FOR2(x,from,to) for(x=from;x<to;x++)
 #define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
 #define ZERO(a) memset(a,0,sizeof(a))
 void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
 #define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
 #define ZERO2(a,b) memset(a,0,b)
 #define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
 #define GETs(x) scanf("%s",x);
 int GETi() { int i;scanf("%d",&i); return i;}
 #define GET1(x) scanf("%d",x);
 #define GET2(x,y) scanf("%d%d",x,y);
 #define GET3(x,y,z) scanf("%d%d%d",x,y,z);
 
 #define EPS (1e-11)
 template <class T> T sqr(T val){ return val*val;}
 
 //-------------------------------------------------------
 
 ll N;
 int A[3001],B[3001],X[3001];
 int cand[3001];
 void solve(int _loop) {
 	int i,j,x,y,z,ne=0;
 	
 	cin>>N;
 	
 	FOR(i,N) A[i]=GETi();
 	FOR(i,N) B[i]=GETi();
 	ZERO(X);
 	
 	FOR(i,N) {
 		//FOR(j,N) _P("(%d,%d,%d) ",A[j],B[j],X[j]);
 		
 		ZERO(cand);
 		
 		int ma=0;
 		FOR(j,N) {
 			if(X[j]==0 &&  A[j]<=ma+1) cand[j]|=1;
 			if(X[j]) ma=max(ma,A[j]);
 		}
 		
 		ma=0;
 		for(j=N-1;j>=0;j--) {
 			if(X[j]==0 && B[j]<=ma+1) cand[j]|=2;
 			if(X[j]) ma=max(ma,B[j]);
 		}
 		
 		FOR(j,N) {
 			if(cand[j]==3) break;
 		}
 		//_P("%d\n",j);
 		X[j]=i+1;
 		
 	}
 	
 	
 	_PE("Case #%d:",_loop);
 	FOR(i,N) _P(" %d",X[i]);
 	_P("\n");
 }
 
 void init() {
 }
 
 int main(int argc,char** argv){
 	int loop,loops;
 	long long span;
 	char tmpline[1000];
 	struct timeval start,end,ts;
 	
 	if(argc>1) {
 		freopen(argv[1], "r", stdin);
 	}
 	
 	gettimeofday(&ts,NULL);
 	
 	GET1(&loops);
 	gets(tmpline);
 	init();
 	
 	for(loop=1;loop<=loops;loop++) {
 		gettimeofday(&start,NULL);
 		solve(loop);
 		gettimeofday(&end,NULL);
 		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
 		_E("                                     time: %lld ms\n",span/1000);
 	}
 	
 	start = ts;
 	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
 	_E("**Total time: %lld ms\n",span/1000);
 	
 	return 0;
 	
 }
 
 
 
