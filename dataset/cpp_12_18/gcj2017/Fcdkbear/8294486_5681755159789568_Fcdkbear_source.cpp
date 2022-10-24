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
 
 int e[110];
 int s[110];
 int d[110][110];
 int u[110];
 int v[110];
 LL sum[110];
 int was[110][110];
 double dp[110][110];
 int n, q;
 double INF = 1e40;
 
 double r(int v, int h) {
 	if (v == n - 1) {
 		return 0;
 	}
 	if (was[v][h]) {
 		return dp[v][h];
 	}
 	was[v][h] = 1;
 	double res = INF;
 	if (e[v] >= d[v][v + 1]) {
 		res = min(res, d[v][v + 1] / (double)s[v] + r(v + 1, v));
 	}
 	if (sum[v + 1] - sum[h] <= e[h]) {
 		res = min(res, d[v][v + 1] / (double)s[h] + r(v + 1, h));
 	}
 	return dp[v][h] = res;
 }
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	double beg = clock();
 	freopen("out.txt", "w", stdout);
 #endif
 	
 	int tests;
 	scanf("%d", &tests);
 	FOR(testNumber, 1, tests + 1) {
 		cin >> n >> q;
 		FOR(i, 0, n) {
 			cin >> e[i] >> s[i];
 		}
 		FOR(i, 0, n) {
 			FOR(j, 0, n) {
 				cin >> d[i][j];
 			}
 		}
 		FOR(i, 0, q) {
 			cin >> u[i] >> v[i];
 			u[i]--;
 			v[i]--;
 		}
 		FOR(i, 1, n) {
 			sum[i] = sum[i - 1] + d[i - 1][i];
 		}
 		MEMS(was, 0);
 		double res = r(0, 0);
 		printf("Case #%d: %.15lf\n", testNumber, res);
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }