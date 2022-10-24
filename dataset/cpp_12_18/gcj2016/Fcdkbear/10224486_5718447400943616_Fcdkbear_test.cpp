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
 
 char s[10][10];
 int n;
 int dp[20][20];
 int mask;
 
 int r(int mask1, int mask2) {
 	if (mask1 +1 == (1<<n)) {
 		if (mask2+1 == (1<<n))
 			return 0;
 		return 1;
 	}
 	if (dp[mask1][mask2] != -1)
 		return dp[mask1][mask2];
 	FOR(i,0,n) {
 		if ((mask1>>i)&1)
 			continue;
 		bool found = false;
 		FOR(j,0,n) {
 			if ((mask2>>j)&1)
 				continue;
 			int idx = i*n+j;
 			if (((mask>>idx)&1) == 0)
 				continue;
 			found = true;
 			if (r(mask1|(1<<i),mask2|(1<<j)) == 1)
 				return dp[mask1][mask2] = 1;
 		}
 		if (!found)
 			return dp[mask1][mask2] = 1;
 	}
 	return dp[mask1][mask2] = 0;
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
         	cin>>n;
         	FOR(i,0,n)
         		scanf("%s",s[i]);
         	int res = 1000000000;
         	for (mask = 0; mask<(1<<(n*n)); ++mask) {
         		bool ok = true;
         		FOR(i,0,n*n) {
         			int c = ((mask>>i)&1);
         			if ((c == 0) && (s[i/n][i%n] == '1'))
         				ok = false;
         		}
         		if (!ok)
         			continue;
         		//cout<<mask<<endl;
         		MEMS(dp,-1);
         		int k = r(0,0);
         		int nres = 0;
         		if (k == 0) {
         			FOR(i,0,n*n) {
 						int c = ((mask>>i)&1);
 						if ((c == 1) && (s[i/n][i%n] == '0'))
 							nres++;
 					}
             		res = min(res,nres);
         		}
         	}
         	printf("Case #%d: %d\n",testNumber,res);
         }
 
 #ifdef Fcdkbear
         double end = clock();
         fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
         return 0;
 }
