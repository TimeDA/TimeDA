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
 
 const int MAXN=1000;
 const int MAXK=100;
 
 int n,k;
 int sum[MAXN];
 
 int off[MAXN];
 
 int lval[MAXK],hval[MAXK];
 
 int dp[MAXK+1][MAXK];
 void sol(int i,int j,int val) { if(val<dp[i][j]) dp[i][j]=val; }
 int divup(int a,int b) { return a>=0?(a+b-1)/b:a/b; }
 
 int calc() {
 	REP(i,k) lval[i]=hval[i]=off[i];
 	FOR(i,k,n) { int at=i%k; if(off[i]<lval[at]) lval[at]=off[i]; if(off[i]>hval[at]) hval[at]=off[i]; }
 	//REP(i,k) printf("%d: %d..%d\n",i,lval[i],hval[i]);
 	int want=sum[0]%k; if(want<0) want+=k;
 	int ret=INT_MAX;
 	REP(fix,k) {
 		REPE(i,k) REP(j,k) dp[i][j]=INT_MAX;
 		//printf("fix=%d\n",fix);
 		sol(0,0,0);
 		REP(i,k) REP(j,k) if(dp[i][j]!=INT_MAX) {
 			//printf("%d,%d = %d\n",i,j,dp[i][j]);
 			if(i==fix) {
 				int nj=j;
 				int nval=max(dp[i][j],hval[i]-lval[fix]);
 				sol(i+1,nj,nval);
 				continue;
 			}
 			REP(dx,k) {
 				// x>=lval[fix]-lval[i], x=y*k+dx, 
 				int y=divup(lval[fix]-lval[i]-dx,k),x=y*k+dx;
 				int nj=j+dx; if(nj>=k) nj-=k;
 				int nval=max(dp[i][j],x+hval[i]-lval[fix]);
 				//printf("\t-> %d,%d = %d (y=%d,x=%d) [%d,%d]\n",i+1,nj,y,x,lval[i],hval[i]);
 				sol(i+1,nj,nval);
 			}
 		}
 		int cur=dp[k][want];
 		if(cur<ret) ret=cur;
 	}
 	return ret;
 }
 
 void run(int casenr) {
 	scanf("%d%d",&n,&k);
 	REP(i,n-k+1) scanf("%d",&sum[i]);
 
 	REP(i,k) off[i]=0;
 	FOR(i,k,n) {
 		off[i]=sum[i-k+1]-sum[i-k];
 		if(i-k>=k) off[i]+=off[i-k];
 	}
 	//FOR(i,k,n) printf("%d: %d\n",i,off[i]);
 	printf("Case #%d: %d\n",casenr,calc());
 	fprintf(stderr,"Case #%d: %d\n",casenr,calc());
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
