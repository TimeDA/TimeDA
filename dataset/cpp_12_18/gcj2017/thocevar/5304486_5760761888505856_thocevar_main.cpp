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
 int r,c;
 string s[30];
 int e[30];
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		//cerr << test << endl;
 		printf("Case #%d:\n",test);
 		cin >> r >> c;
 		REP (i,r) cin >> s[i];
 		REP (i,r) {
 			char p='?';
 			REP (j,c) {
 				if (s[i][j]!='?') { p=s[i][j]; break; }
 			}
 			if (p!='?') {
 				REP (j,c) {
 					if (s[i][j]!='?') {
 						p=s[i][j];
 					} else {
 						s[i][j]=p;
 					}
 				}
 			}
 		}
 		REP (i,r) {
 			if (s[i][0]=='?') {
 				for (int ii=i+1;ii<r;ii++) {
 					if (s[ii][0]!='?') { s[i]=s[ii]; break; }
 				}
 			}
 		}
 		REP (i,r) {
 			if (s[i][0]=='?') {
 				for (int ii=i-1;ii>=0;ii--) {
 					if (s[ii][0]!='?') { s[i]=s[ii]; break; }
 				}
 			}
 		}
 		REP (i,r) {
 			cout << s[i] << endl;
 		}
 	}
 	return 0;
 }
