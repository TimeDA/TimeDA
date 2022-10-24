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
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int tests;
 int n;
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (t,1,tests) {
 		cin >> n;
 		printf("Case #%d: ",t);
 		if (n==0) {
 			cout << "INSOMNIA" << endl;
 			continue;
 		}
 		int done=0;
 		set<char> seen;
 		for (int k=1;k<1000;k++) {
 			int m=k*n;
 			string s=cvt<string>(m);
 			set<char> c(ALL(s));
 			seen.insert(ALL(c));
 			if (seen.size()==10) {
 				cout << m << endl;
 				done=1;
 				break;
 			}
 		}
 		assert(done);
 	}
 	return 0;
 }
