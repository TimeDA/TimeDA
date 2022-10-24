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
 	char s[1 << 10];
 	int k;
 
 	solver()
 	{
 		scanf("%s", s);
 		scanf("%d", &k);
 	}
 
 	int solve()
 	{
 		int res = 0;
 		int i = 0;
 		for ( ; s[i + k - 1]; ++i)
 		{
 			if (s[i] == '+')
 				continue;
 			res++;
 			for (int j = 0; j < k; ++j)
 				s[i + j] = s[i + j] == '-' ? '+' : '-';
 		}
 		for (; s[i]; ++i)
 			if (s[i] == '-')
 				return -1;
 		return res;
 	}
 };
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	
 	int t;
 	scanf("%d", &t);
 
 	for (int test_case = 1; test_case <= t; ++test_case)
 	{
 		solver s;
 		printf("Case #%d: ", test_case);
 		int res = s.solve();
 		if (res == -1)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%d\n", res);
 	}
 	return 0;
 }