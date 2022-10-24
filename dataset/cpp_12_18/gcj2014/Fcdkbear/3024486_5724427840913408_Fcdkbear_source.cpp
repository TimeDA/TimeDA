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
 #include <unordered_map>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 const int MAX_LEFT = 1005;
 int dp[110][210][1010][2];
 int was[110][210][1010][2];
 int test;
 
 int g[110];
 int h[110];
 int n, p, q;
 
 int r(int pos, int left, int moves, int who)
 {
 	if (pos == n)
 		return 0;
 	if (was[pos][left][moves][who] == test)
 		return dp[pos][left][moves][who];
 	was[pos][left][moves][who] = test;
 	int res = 0;
 	if (moves > 0)
 	{
 		if (left > p)
 			res = max(res, r(pos, left - p, moves - 1, who));
 		else
 			res = max(res, g[pos] + r(pos + 1, h[pos + 1], moves - 1, who));
 	}
 	if (who == 0)
 	{
 		//don't hit
 		if (moves < MAX_LEFT)
 			res = max(res, r(pos, left, moves + 1, who ^ 1));
 		//hit
 		if (left > p)
 			res = max(res, r(pos, left - p, moves, who ^ 1));
 		else
 			res = max(res, g[pos] + r(pos + 1, h[pos + 1], moves, who ^ 1));
 	}
 	else
 	{
 		if (left > q)
 			res = max(res, r(pos, left - q, moves, who ^ 1));
 		else
 			res = max(res, r(pos + 1, h[pos + 1], moves, who ^ 1));
 	}
 	return dp[pos][left][moves][who] = res;
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
 
 	int t;
 	scanf("%d", &t);
 	for (test = 1; test <= t; ++test)
 	{
 		scanf("%d%d%d", &p, &q, &n);
 		FOR(i, 0, n)
 			scanf("%d%d", &h[i], &g[i]);
 		int res = r(0, h[0], 0, 0);
 		printf("Case #%d: %d\n", test, res);
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }