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
 int N,K;
 double p[205];
 double f[205][205];
 
 int main() {
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		//cerr << test << endl;
 		printf("Case #%d: ",test);
 		scanf("%d %d",&N,&K);
 		INIT(f,0);
 		FOR (n,1,N) scanf("%lf",&p[n]);
 		double best=0;
 		REP (m,1<<N) {
 			int st=0;
 			vector<int> ind;
 			REP (i,N) if (m&(1<<i)) {
 				ind.push_back(i+1);
 			}
 			if (ind.size()!=K) continue;
 			f[0][0]=1.0;
 			FOR (k,1,K) {
 				double prob = p[ind[k-1]];
 				FOR (r,0,k) {
 					f[k][r] = f[k-1][r]*(1-prob);
 					if (r>0) f[k][r] += f[k-1][r-1]*prob;
 				}
 			}
 			best=max(best,f[K][K/2]);
 		}
 		printf("%.9f\n",best);
 	}
 	return 0;
 }
