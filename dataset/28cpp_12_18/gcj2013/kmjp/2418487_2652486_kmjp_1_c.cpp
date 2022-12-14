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
 
 ll R,N,M,K;
 
 void solve2(vector<int>& V) {
 	int s1,s2,s3,i;
 	int cand[200];
 	
 	ZERO(cand);
 	vector<pair<int,int> > C;
 	
 	for(s1=2;s1<=M;s1++) {
 		for(s2=s1;s2<=M;s2++) {
 			for(s3=s2;s3<=M;s3++) {
 				cand[1]++;
 				cand[s1]++;
 				cand[s2]++;
 				cand[s3]++;
 				cand[s1*s2]++;
 				cand[s2*s3]++;
 				cand[s3*s1]++;
 				cand[s1*s2*s3]++;
 				
 				int prop=1;
 				FOR(i,V.size()) prop *= cand[V[i]];
 				if(prop) C.push_back(make_pair(prop,s1*100+s2*10+s3));
 			}
 		}
 	}
 	
 	sort(C.begin(),C.end());
 	_P("%d\n",C[0].second);
 }
 
 
 
 void solve(int _loop) {
 	int i,j,x,y,ne=0;
 	
 	_PE("Case #%d:\n",_loop);
 	
 	cin >> R >> N >> M >> K;
 	FOR(y,R) {
 		vector<int> V;
 		FOR(x,K) V.push_back(GETi());
 		solve2(V);
 	}
 	
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
 
 
 
