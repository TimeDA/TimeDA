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
 #include <unordered_set>
 
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
 
 double eps = 1e-4;
 
 
 struct num
 {
 	int v1, v2;
 	int intValue;
 	double value;
 };
 
 void solveForOne(num r, num x, num needV, num needX) {
 	if (needX.intValue != x.intValue)
 	{
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	printf("%.15lf\n", needV.value / r.value);
 }
 
 void solveForTwo(num r1, num x1, num r2, num x2, num needV, num needX)
 {
 	LL val1 = needV.intValue * 1ll * needX.intValue;
 	LL val2 = needV.intValue * 1ll * x2.intValue;
 	LL val4 = val1 - val2;
 	LL val3 = x1.intValue - x2.intValue;
 	if ((val4 > 0) && (val3<0))
 	{
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	if ((val4 < 0) && (val3 > 0))
 	{
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	if (val3 < 0)
 	{
 		val4 = -val4;
 		val3 = -val3;
 	}
 	LL val5 = val3*needV.intValue;
 	if (val4 > val5)
 	{
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	double v0 = needV.value*needX.value - needV.value*x2.value;
 	v0 /= (x1.value - x2.value);
 	double v1 = needV.value - v0;
 	double res = max(v0 / r1.value, v1 / r2.value);
 	res = MAX(res, 0);
 	printf("%.15lf\n", res);
 }
 
 
 num readNum()
 {
 	num res;
 	scanf("%d.%d", &res.v1, &res.v2);
 	res.value = res.v1 + res.v2 / 10000.0;
 	res.intValue = res.v1 * 10000 + res.v2;
 	return res;
 }
 
 pair<num, num> c[3];
 
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
 	scanf("%d", &tests);
 	FOR(testNumber, 1, tests + 1)
 	{
 		int n;
 		scanf("%d", &n);
 		
 		num needV, needX;
 		needV = readNum();
 		needX = readNum();
 		FOR(i, 0, n)
 		{
 			c[i].first = readNum();
 			c[i].second = readNum();
 		}
 		printf("Case #%d: ", testNumber);
 		if (n == 1)
 		{
 			solveForOne(c[0].first, c[0].second, needV, needX);
 			continue;
 		}
 		if (c[0].second.intValue==c[1].second.intValue)
 		{
 			num sum;
 			sum.intValue = c[0].first.intValue + c[1].first.intValue;
 			sum.value = c[0].first.value + c[1].first.value;
 			solveForOne(sum, c[0].second, needV, needX);
 			continue;
 		}
 		solveForTwo(c[0].first, c[0].second, c[1].first, c[1].second, needV, needX);
 	}
 	return 0;
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }