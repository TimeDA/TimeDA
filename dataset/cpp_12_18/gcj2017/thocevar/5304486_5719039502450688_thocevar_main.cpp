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
 int hd, ad, hk, ak, b, d;
 
 int main() {
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		cerr << test << endl;
 		printf("Case #%d: ",test);
 		cin >> hd >> ad >> hk >> ak >> b >> d;
 		int hd0=hd, ad0=ad, hk0=hk, ak0=ak;
 		int sol=1000;
 		int debug=0;
 		FOR (nd0,0,105) FOR (nb0,0,105) {
 			hd=hd0; ad=ad0; hk=hk0; ak=ak0;
 			int nd=nd0, nb=nb0;
 			int m=0;
 			while (m<1000) {
 				m++;
 				//printf("m=%d\n",m);
 				if (nd>0) {
 					if (hd-max(ak-d,0)<=0) {
 						if (debug) printf("cure d\n");
 						hd=hd0;
 					} else {
 						if (debug) printf("debuf\n");
 						ak=max(ak-d,0);
 						nd--;
 					}
 				} else if (nb>0) {
 					if (hd-ak<=0) {
 						if (debug) printf("cure b\n");
 						hd=hd0;
 					} else {
 						if (debug) printf("buf\n");
 						ad+=b;
 						nb--;
 					}
 				} else {
 					if (hk-ad>0 && hd-ak<=0) {
 						if (debug) printf("cure a\n");
 						hd=hd0;
 					} else {
 						if (debug) printf("attack\n");
 						hk-=ad;
 						if (hk<=0) break;
 					}
 				}
 				hd-=ak;
 				if (hd<=0) { m=1000; break; }
 			}
 			sol=min(sol,m);
 		}
 		if (sol==1000) {
 			printf("IMPOSSIBLE\n");
 		} else {
 			printf("%d\n",sol);
 		}
 	}
 	return 0;
 }
