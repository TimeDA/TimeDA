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
 
 int s[10005];
 int used[10005];
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","w",stdout);
 	int tests;
 	cin >> tests;
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		int n,x;
 		cin >> n >> x;
 		REP (i,n) {
 			cin >> s[i];
 		}
 		sort(s,s+n);
 		INIT(used,0);
 		int j=n-1, st=0;
 		REP (i,n) if (!used[i]) {
 			while (i<j && (used[j] || s[i]+s[j]>x)) {
 				j--;
 			}
 			st++;
 			used[i]=1;
 			if (i<j) used[j]=1;
 		}
 		printf("Case #%d: %d\n",test,st);
 	}
 	return 0;
 }
