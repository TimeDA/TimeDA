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
 int n,p;
 
 map<vector<int>, int> mem;
 
 int solve(int i, vector<int> f, int m) {
 	if (i==n-1) return 0;
 	if (mem.count(f)) return mem[f];
 	int r=0;
 	REP (j,p) if (f[j]>0) {
 		f[j]--;
 		int mj=(m+j)%f.size();
 		r=max(r, solve(i+1,f,mj)+(mj==0));
 		f[j]++;
 	}
 	return mem[f]=r;
 }
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		cerr << test << endl;
 		printf("Case #%d: ",test);
 		cin >> n >> p;
 		vector<int> f(p);
 		REP (i,n) {
 			int g;
 			cin >> g;
 			f[g%p]++;
 		}
 		mem.clear();
 		printf("%d\n",1+solve(0,f,0));
 	}
 	return 0;
 }
