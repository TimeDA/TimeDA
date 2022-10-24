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
 #define REP(i,n) for (int i=0;i<(int)(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef long long int64;
 typedef pair<int64,int64> PII;
 
 int tests;
 int n;
 char w[9][9];
 
 int work[9], mach[9];
 
 int sim(int d) {
 	if (d==n) return 1;
 	REP (i,n) if (!work[i]) {
 		work[i]=1;
 		int can=0,cant=0;
 		REP (j,n) if (!mach[j] && w[i][j]=='1') {
 			mach[j]=1;
 			if (sim(d+1)) can++;
 			else cant++;
 			mach[j]=0;
 			if (cant>0) break;
 		}
 		work[i]=0;
 		if (cant>0 || can==0) return 0;
 	}
 	return 1;
 }
 
 int best;
 
 void solve(int i, int j, int c) {
 	if (j==n) {
 		solve(i+1,0,c);
 		return;
 	}
 	if (i==n) {
 		if (sim(0)) best=min(best,c);
 		return;
 	}
 	if (w[i][j]=='1') solve(i,j+1,c);
 	else {
 		w[i][j]='1';
 		solve(i,j+1,c+1);
 		w[i][j]='0';
 		solve(i,j+1,c);
 	}
 }
 
 int main() {
 	freopen("D-small-attempt0.in","r",stdin);
 	freopen("D-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		//cerr << test << endl;
 		printf("Case #%d: ",test);
 		scanf("%d",&n);
 		REP (i,n) scanf("%s",w[i]);
 		best=n*n;
 		solve(0,0,0);
 		cout << best << endl;
 	}
 	return 0;
 }
