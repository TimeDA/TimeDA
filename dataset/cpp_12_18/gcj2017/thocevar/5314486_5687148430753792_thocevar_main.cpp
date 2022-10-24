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
 int n,c,m;
 vector<int> l[1001];
 
 int check(int r) {
 	vector<set<int> > f(r);
 	vector<set<int> > u(r);
 	int p=0;
 	REP (i,n) {
 		REP (j,r) {
 			f[j].insert(i);
 		}
 		//printf("i=%d\n",i);
 		for (int x : l[i]) {
 			//printf("place %d\n",x);
 			int done=0;
 			// assigned seat
 			REP (j,r) if (u[j].count(x)==0) {
 				if (f[j].count(i)) {
 					//printf("assigned %d\n",j);
 					f[j].erase(i);
 					u[j].insert(x);
 					done=1;
 					break;
 				}
 			}
 			if (done) continue;
 			// promoted seat
 			REP (j,r) if (u[j].count(x)==0) {
 				if (!f[j].empty()) {
 					//printf("promoted %d\n",j);
 					f[j].erase(f[j].begin());
 					u[j].insert(x);
 					p++;
 					done=1;
 					break;
 				}
 			}
 			if (!done) return -1;
 		}
 	}
 	return p;
 }
 
 int main() {
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		cerr << test << endl;
 		printf("Case #%d: ",test);
 		cin >> n >> c >> m;
 		REP (i,n) l[i].clear();
 		REP (i,m) {
 			int pos, cust;
 			cin >> pos >> cust;
 			pos--; cust--;
 			l[pos].push_back(cust);
 		}
 		//check(2); return 0;
 		int lo=0,hi=m,P=-1;
 		while (hi-lo>1) {
 			int r=(lo+hi)/2;
 			int p=check(r);
 			if (p==-1) lo=r; else hi=r;
 		}
 		printf("%d %d\n",hi,check(hi));
 	}
 	return 0;
 }
