#include <algorithm>  
 #include <iostream>  
 #include <sstream>  
 #include <string>  
 #include <vector>  
 #include <queue>  
 #include <set>  
 #include <map>  
 #include <cstdio>  
 #include <cstdlib>  
 #include <cctype>  
 #include <cmath>  
 #include <list>  
 #include <climits>
 #include <cassert>
 using namespace std;  
 
 #define PB push_back  
 #define MP make_pair  
 #define SZ(v) ((int)(v).size())  
 #define FOR(i,a,b) for(int i=(a);i<(b);++i)  
 #define REP(i,n) FOR(i,0,n)  
 #define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
 #define REPE(i,n) FORE(i,0,n)  
 #define FORSZ(i,a,v) FOR(i,a,SZ(v))  
 #define REPSZ(i,v) REP(i,SZ(v))  
 typedef long long ll;  
 int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
 
 const int MOD=1000000007;
 const int MAXH=100;
 const int MAXPER=12;
 
 int h,w;
 int ways[MAXH+1][MAXPER+1][2];
 void inc(int &a,ll b) { a=(a+b)%MOD; }
 void add(int i,int j,int k,int dh,int dw) {
 	if(w%dw!=0) return;
 	if(i+dh>h) return;
 	int g=gcd(j,dw); int nj=j/g*dw;
 	//printf("\t\t(%d,%d,%d)+=%d*%d\n",i+dh,nj,1-k,g,ways[i][j][k]);
 	inc(ways[i+dh][nj][1-k],(ll)g*ways[i][j][k]);
 }
 
 int solve(int h,int w) {
 	::h=h,::w=w;
 	memset(ways,0,sizeof(ways)); ways[0][1][0]=ways[0][1][1]=1;
 	REPE(i,h) FORE(j,1,MAXPER) REP(k,2) if(ways[i][j][k]>0) {
 		//printf("\t%d %d %d = %d\n",i,j,k,ways[i][j][k]);
 		if(k==0) add(i,j,k,1,1);
 		if(k==0) add(i,j,k,2,3);
 		if(k==0) add(i,j,k,2,6);
 		if(k==0) add(i,j,k,3,4);
 		if(k==1) add(i,j,k,2,1);
 	}
 	int ret=0; FORE(j,1,MAXPER) REP(k,2) inc(ret,ways[h][j][k]); return ret;
 }
 
 void run(int casenr) {
 	scanf("%d%d",&h,&w);
 	printf("Case #%d: %d\n",casenr,solve(h,w));
 }
 
 void test() {
 	FORE(h,2,6) FORE(w,3,6) printf("%d %d = %d\n",h,w,solve(h,w));
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	//test();
 	return 0;
 }
