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
 
 #define LIM 1000000000000000000LL
 
 int tests;
 vector<int64> tidy;
 
 void gen(int64 x) {
 	tidy.push_back(x);
 	FOR (d,x%10,9) {
 		if (x*10.0+d<=LIM) gen(x*10+d);
 	}
 }
 
 int main() {
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","wb",stdout);
 	FOR (x,1,9) gen(x);
 	sort(ALL(tidy));
 	cin >> tests;
 	FOR (test,1,tests) {
 		printf("Case #%d: ",test);
 		int64 x;
 		cin >> x;
 		auto it=upper_bound(ALL(tidy), x);
 		it--;
 		printf("%I64d\n",*it);
 	}
 	return 0;
 }
