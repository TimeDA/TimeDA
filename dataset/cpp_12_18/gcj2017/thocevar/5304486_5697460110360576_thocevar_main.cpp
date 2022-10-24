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
 int r[55];
 
 int main() {
 	freopen("B-small-attempt1.in","r",stdin);
 	freopen("B-small-attempt1.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		cerr << test << endl;
 		cin >> n >> p;
 		REP (i,n) cin >> r[i];
 		vector<vector<int> > events;
 		int id=0;
 		vector<vector<PII> > v(n);
 		REP (i,n) {
 			REP (j,p) {
 				int q;
 				cin >> q;
 				int l=ceil(q*10.0/(r[i]*11));
 				int h=floor(q*10.0/(r[i]*9));
 				v[i].push_back({l,h});
 			}
 		}
 		int sol=0;
 		if (n==1) {
 			REP (j,p) {
 				if (v[0][j].first<=v[0][j].second) sol++;
 			}
 		} else {
 			sort(ALL(v[1]));
 			do {
 				int st=0;
 				REP (j,p) {
 					if (max(v[0][j].first,v[1][j].first)<=min(v[0][j].second,v[1][j].second)) st++;
 				}
 				sol=max(sol,st);
 			} while (next_permutation(ALL(v[1])));
 		}
 		printf("Case #%d: %d\n",test,sol);
 	}
 	return 0;
 }
