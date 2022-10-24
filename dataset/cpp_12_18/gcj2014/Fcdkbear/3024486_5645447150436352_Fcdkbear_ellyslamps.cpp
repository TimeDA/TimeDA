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
 
 int a[1000010];
 LL sum[1000010];
 int n, p, q, r, s;
 
 inline double get(int le, int ri)
 {
 	if (ri < 0)
 		return 0;
 	if (ri >= n)
 		return 0;
 	LL now = 0;
 	if (le)
 		now = MAX(now, sum[le - 1]);
 	LL now1 = sum[ri];
 	if (le)
 		now1 -= sum[le - 1];
 	now = MAX(now, now1);
 	if (ri != n - 1)
 		now = MAX(now, sum[n - 1] - sum[ri]);
 	return 1 - now / (double)sum[n - 1];
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
 	FOR(it, 0, t)
 	{
 		scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
 		FOR(i, 0, n)
 		{
 			LL v = i * 1ll * p;
 			v += q;
 			v %= r;
 			v += s;
 			a[i] = v;
 			sum[i] = v;
 			if (i)
 				sum[i] += sum[i - 1];
 		}
 		double res = 0;
 		FOR(i, 0, n)
 		{
 			int le = i;
 			int ri = n - 1;
 			int best = n - 1;
 			while (le <= ri)
 			{
 				int m = (le + ri) / 2;
 				LL val1 = sum[m];
 				if (i)
 					val1 -= sum[i - 1];
 				LL val2 = 0;
 				val2 = sum[n - 1] - sum[m];
 				if (val1 >= val2)
 				{
 					best = m;
 					ri = m - 1;
 				}
 				else
 					le = m + 1;
 			}
 			res = max(res, get(i, best - 1));
 			res = max(res, get(i, best));
 			res = max(res, get(i, best + 1));
 		}
 		printf("Case #%d: %.15lf\n", it+1, res);
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }