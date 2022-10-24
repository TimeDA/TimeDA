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
 #include <unordered_map>
 using namespace std;
 
 #define ALL(c) (c).begin(),(c).end()
 #define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
 #define REP(i,n) for (int i=0;i<(int)(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int tests;
 string s;
 int k,n;
 int f[1000];
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		printf("Case #%d: ",test);
 		cin >> s >> k;
 		n=s.size();
 		REP (i,n) f[i]=(s[i]=='+');
 		int r=0;
 		REP (i,n-k+1) {
 			if (f[i]==0) {
 				r++;
 				REP (j,k) f[i+j]^=1;
 			}
 		}
 		REP (i,n) if (f[i]==0) r=-1;
 		if (r==-1) printf("IMPOSSIBLE\n");
 		else printf("%d\n",r);
 	}
 	return 0;
 }
