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
 
 const string PROBLEM = "A-small-attempt1";
 
 int D, N;
 int K[1000], S[1000];
 
 void read()
 {
 	scanf("%d%d", &D, &N);
 	for (int i = 0; i < N; ++i)
 		scanf("%d%d", &K[i], &S[i]);
 }
 
 double T[1000];
 
 bool ok(double speed)
 {
 	for (int i = 0; i < N; ++i)
 	{
 		double x = speed * T[i];
 		if (x > K[i] + S[i] * T[i])
 			return 0;
 	}
 	return 1;
 }
 
 double solve()
 {
 	for (int i = 0; i < N; ++i)
 	{
 		T[i] = (0.0 + D - K[i]) / S[i];
 		for (int j = 0; j < N; ++j)
 		{
 			if (K[j] > K[i] && S[j] < S[i])
 			{
 				double t = (0.0 + K[i] - K[j]) / (S[j] - S[i]);
 				if (K[i] + S[i] * t > D)
 					continue;
 				T[i] = min(T[i], t);
 			}
 		}
 	}
 
 	double L = 0, R = 1e20;
 	for (int it = 0; it < 100; ++it)
 	{
 		double M = (L + R) / 2;
 		if (ok(M))
 			L = M;
 		else
 			R = M;
 	}
 	return (L + R) / 2;
 }
 
 int main()
 {
 #ifndef _DEBUG
 	freopen((PROBLEM + ".in").c_str(), "r", stdin);
 	freopen((PROBLEM + ".out").c_str(), "w", stdout);
 #endif
 
 	int tests;
 	scanf("%d", &tests);
 	for (int test_case = 1; test_case <= tests; test_case++)
 	{
 		printf("Case #%d: ", test_case);
 		read();
 		printf("%.10lf\n", solve());
 	}
 	return 0;
 }