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
 	LL n, k;
 
 	solver()
 	{
 		scanf("%lld%lld", &n, &k);
 	}
 
 	void solve(LL & rmin, LL & rmax)
 	{
 		map<LL, LL> have;
 		have[n] = 1;
 		while (k)
 		{
 			LL len = have.rbegin()->first;
 			LL cnt = have.rbegin()->second;
 			LL L = (len - 1) / 2;
 			LL R = (len - 1) - L;
 			if (cnt < k)
 			{
 				have.erase(len);
 				have[L] += cnt;
 				have[R] += cnt;
 				k -= cnt;
 			}
 			else
 			{
 				rmin = L;
 				rmax = R;
 				return;
 			}
 		}
 	}
 };
 
 int main()
 {
 	freopen("C-small-1-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	
 	int t;
 	scanf("%d", &t);
 
 	for (int test_case = 1; test_case <= t; ++test_case)
 	{
 		solver s;
 		LL rmin, rmax;
 		s.solve(rmin, rmax);
 		printf("Case #%d: %lld %lld\n", test_case, rmax, rmin);
 	}
 	return 0;
 }