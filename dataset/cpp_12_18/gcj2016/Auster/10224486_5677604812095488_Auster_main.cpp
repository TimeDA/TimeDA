#pragma comment(linker, "/STACK:134217728")
 #define _CRT_SECURE_NO_WARNINGS
 
 #include <cstdio>
 #include <algorithm>
 #include <iostream>
 #include <vector>
 #include <queue>
 #include <map>
 #include <set>
 #include <string>
 #include <numeric>
 #include <complex>
 #include <functional>
 #include <cmath>
 #include <time.h>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int T, n, k;
 
 double p[200];
 
 int cnt(int x)
 {
 	int res = 0;
 	while (x)
 	{
 		x &= x - 1;
 		res++;
 	}
 	return res;
 }
 
 double dp[20][20];
 
 double go(int pos, int mask, int yes)
 {
 	if (pos == n)
 		return yes == k / 2;
 	double & res = dp[pos][yes];
 	if (res != -1.0)
 		return res;
 	res = 0;
 	if (mask & (1 << pos))
 		res = p[pos] * go(pos + 1, mask, yes + 1) + (1.0 - p[pos]) * go(pos + 1, mask, yes);
 	else
 		res = go(pos + 1, mask, yes);
 	return res;
 }
 
 void clear()
 {
 	for (int i = 0; i < 20; ++i)
 		for (int j = 0; j < 20; ++j)
 			dp[i][j] = -1.0;
 }
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 #endif
 	scanf("%d", &T);
 	for (int test = 1; test <= T; ++test)
 	{
 		scanf("%d%d", &n, &k);
 		
 		for (int i = 0; i < n; ++i)
 			scanf("%lf", &p[i]);
 
 		double res = 0.0;
 
 		for (int i = 0; i < 1 << n; ++i)
 		{
 			if (cnt(i) != k)
 				continue;
 			clear();
 			res = max(res, go(0, i, 0));
 		}
 
 		printf("Case #%d: %.10lf\n", test, res);
 
 	}
 	return 0;
 }