#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <math.h>
 #include <queue>
 #include <list>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stack>
 #include <ctime>
 using namespace std;
 
 #define ALL(c) (c).begin(),(c).end()
 #define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
 #define REP(i,n) for (int i=0;i<(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define FORD(i,a,b) for (int i=(a);i>=(b);i--)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int p,q,n;
 int h[100],g[100];
 
 int fin[201];
 
 int dp[100][20001][2];
 
 int solve(int i, int s, int tower) {
 	if (i==n) return 0;
 	int &f = dp[i][s][tower];
 	if (f!=-1) return f;
 	// bonus
 	FOR (k,0,s) {
 		int hi=h[i]-k*p;
 		int ff;
 		if (hi<=0) {
 			ff=solve(i+1,s-k,tower);
 			f=max(f,ff+g[i]);
 			break;
 		} else {
 			hi-=tower*q;
 			if (hi<=0) {
 				ff=solve(i+1,s-k,0);
 				f=max(f,ff);
 			} else {
 				// leave
 				ff=solve(i+1,s-k+(hi+q-1)/q,0);
 				f=max(f,ff);
 				// finish
 				/*if (i==2 && s==3 && tower==0 && k==2) {
 					printf("!%d\n",hi);
 				}*/
 				if (fin[hi]!=-1) {
 					ff=solve(i+1,s-k+fin[hi],1);
 					f=max(f,ff+g[i]);
 				}
 			}
 		}
 	}
 	//printf("%d %d %d: %d\n",i,s,tower,f);
 	return f;
 }
 
 int main() {
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","w",stdout);
 	int tests;
 	scanf("%d",&tests);
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		scanf("%d %d %d",&p,&q,&n);
 		REP (i,n) scanf("%d %d",&h[i],&g[i]);
 		FOR (h,1,200) {
 			fin[h]=-1;
 			FOR (t,0,200) {
 				int hd = h-t*q;
 				if (hd<=0) break;
 				int d = (hd+p-1)/p;
 				if (t>=d-1) {
 					fin[h]=t+1-d;
 				}
 			}
 			//printf("%d: %d\n",h,fin[h]);
 		}
 		INIT(dp,-1);
 		int r = solve(0,0,0);
 		printf("Case #%d: %d\n",test,r);
 	}
 	return 0;
 }
