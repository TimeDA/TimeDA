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
 int64 v,x;
 int64 r[2],c[2];
 
 int main() {
 	freopen("B-small-attempt2.in","r",stdin);
 	freopen("B-small-attempt2.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		double vf,xf;
 		cin >> n >> vf >> xf;
 		v=round(vf*10000); x=round(xf*10000);
 		REP (i,n) {
 			double rf,cf;
 			cin >> rf >> cf;
 			r[i]=round(rf*10000); c[i]=round(cf*10000);
 		}
 		printf("Case #%d: ",test);
 		double t;
 		if (n==1) {
 			if (c[0]==x) {
 				t = 1.0*v/r[0];
 				printf("%.12f\n",t);
 			} else {
 				printf("IMPOSSIBLE\n");
 			}
 		} else if (n==2) {
 			if (c[0]==c[1]) {
 				if (c[0]==x) {
 					t = 1.0*v/(r[0]+r[1]);
 					printf("%.12f\n",t);
 				} else {
 					printf("IMPOSSIBLE\n");
 				}
 			} else {
 				if (max(c[0],c[1])<x || x<min(c[0],c[1])) {
 					printf("IMPOSSIBLE\n");
 				} else {
 					double t1 = 1.0*(x*v-c[0]*v)/(r[1]*c[1]-r[1]*c[0]);
 					double t0 = (v-t1*r[1])/r[0];
 					printf("%.12f\n",max(t0,t1));
 				}
 			}
 		}
 	}
 	return 0;
 }
