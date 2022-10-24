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
 
 int m,n;
 string s[10];
 
 int p[10];
 int worst,cnt;
 
 void solve(int i=0) {
 	if (i==m) {
 		set<string> t[n];
 		REP (j,m) {
 			FOR (k,0,(int)s[j].size()) {
 				t[p[j]].insert(s[j].substr(0,k));
 			}
 		}
 		int sz=0;
 		REP (j,n) sz+=t[j].size();
 		if (sz>worst) {
 			worst=sz;
 			cnt=1;
 		} else if (sz==worst) {
 			cnt++;
 		}
 	} else {
 		REP (j,n) {
 			p[i]=j;
 			solve(i+1);
 		}
 	}
 }
 
 int main() {
 	freopen("D-small-attempt0.in","r",stdin);
 	freopen("D-small-attempt0.out","w",stdout);
 	int tests;
 	scanf("%d",&tests);
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		scanf("%d %d",&m,&n);
 		REP (i,m) cin >> s[i];
 		worst=0; cnt=0;
 		solve();
 		printf("Case #%d: %d %d\n",test,worst,cnt);
 	}
 	return 0;
 }
