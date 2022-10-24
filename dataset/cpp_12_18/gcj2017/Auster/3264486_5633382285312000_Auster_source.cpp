#define _CRT_SECURE_NO_WARNINGS
 #define y1 klfjvkldfngldf
 
 #pragma comment(linker, "/STACK:400000000")
 
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <string>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <stack>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <complex>
 #include <functional>
 #include <numeric>
 #include <random>
 #include <memory.h>
 #include <time.h>
 
 using namespace std;
 
 typedef long long LL;
 
 
 struct solver
 {
 	LL n;
 
 	solver()
 	{
 		scanf("%lld", &n);
 	}
 
 	LL go(LL now, int p = 1)
 	{
 		if (now > n)
 			return -1;
 		LL res = now;
 		if (now * 10.0 < 1e18)
 			res = max(res, go(now * 10 + p, p));
 		if (p < 9)
 			res = max(res, go(now, p + 1));
 		return res;
 	}
 
 	LL solve()
 	{
 		return go(0, 1);
 	}
 };
 
 int main()
 {
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	
 	int t;
 	scanf("%d", &t);
 
 	for (int test_case = 1; test_case <= t; ++test_case)
 	{
 		solver s;
 		printf("Case #%d: %lld\n", test_case, s.solve());
 	}
 	return 0;
 }