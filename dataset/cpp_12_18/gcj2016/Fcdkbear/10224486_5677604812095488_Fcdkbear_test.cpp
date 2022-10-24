#include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 #include <bitset>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define MEMS(a,b) memset((a),(b),sizeof(a))
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define LL long long
 #define U unsigned
 
 double prob[210];
 vector<double> pr;
 int n,k;
 double res;
 
 void r(int p) {
 	if (p == n) {
 		if (pr.size() == k) {
 			double nres = 0;
 			FOR(mask,0,(1<<k)) {
 				int cnt0 = 0;
 				int cnt1 = 0;
 				FOR(i,0,k)
 					if ((mask >> i)&1)
 						cnt0++;
 					else
 						cnt1++;
 				if (cnt0 == cnt1) {
 					double pro = 1;
 					FOR(i,0,k)
 						if ((mask >> i)&1)
 							pro*=pr[i];
 						else
 							pro*=(1-pr[i]);
 					nres += pro;
 				}
 			}
 			res = max(res,nres);
 		}
 		return;
 	}
 	r(p+1);
 	pr.push_back(prob[p]);
 	r(p+1);
 	pr.pop_back();
 }
 
 int main()
 {
 #ifdef Fcdkbear
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
         double beg = clock();
 #else
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
 #endif
 
         int tests;
         scanf("%d",&tests);
         FOR(testNumber, 1, tests+1) {
         	cin>>n>>k;
         	FOR(i,0,n)
         		cin>>prob[i];
         	res = 0;
         	r(0);
         	printf("Case #%d: %.15lf\n",testNumber,res);
         }
 
 #ifdef Fcdkbear
         double end = clock();
         fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
         return 0;
 }
