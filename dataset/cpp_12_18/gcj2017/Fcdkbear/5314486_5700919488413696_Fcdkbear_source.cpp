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
 #include <unordered_map>
 #include <unordered_set>
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
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.1415926535897
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 map<pair<int, vector<int>>, int> dp;
 int n, p;
 
 int r(int left, vector<int> a) {
 	if (dp.find(mp(left, a)) != dp.end()) {
 		return dp[mp(left, a)];
 	}
 	int sum = 0;
 	FOR(i, 0, a.size()) {
 		sum += a[i];
 	}
 	int res = 0;
 	FOR(i, 0, a.size()) {
 		if (a[i]) {
 			int nLeft = left + (i + 1);
 			if (nLeft >= p) {
 				nLeft -= p;
 			}
 			a[i]--;
 			int now = r(nLeft, a);
 			a[i]++;
 			if ((nLeft == 0) && (sum > 1)) {
 				now++;
 			}
 			res = max(res, now);
 		}
 	}
 	return dp[mp(left, a)] = res;
 }
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	double beg = clock();
 #endif
 
 	int tests;
 	cin >> tests;
 	FOR(testnumber, 1, tests + 1) {
 		scanf("%d%d", &n, &p);
 		vector<int> a(p - 1, 0);
 		int res = 1;
 		FOR(i, 0, n) {
 			int v;
 			scanf("%d", &v);
 			if (v%p) {
 				a[(v%p) - 1]++;
 			}
 			else {
 				res++;
 			}
 		}
 		res = min(res, n);
 		dp.clear();
 		res += r(0, a);
 		printf("Case #%d: %d\n", testnumber, res);
 	}
 
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }