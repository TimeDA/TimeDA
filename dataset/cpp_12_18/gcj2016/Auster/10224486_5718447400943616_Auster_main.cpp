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
 
 int T, n;
 
 int G;
 char buf[5];
 
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
 
 int a[4][4];
 
 int ok(int G)
 {
 	for (int i = 0; i < n * n; ++i)
 		a[i / n][i % n] = (G & (1 << i)) > 0;
 
 	vector<int> p1(n);
 	for (int i = 0; i < n; ++i)
 		p1[i] = i;
 
 	do
 	{
 		vector<int> p2(n);
 		for (int i = 0; i < n; ++i)
 			p2[i] = i;
 
 		do
 		{
 			int used = 0;
 			for (int i = 0; i < n; ++i)
 			{
 				if (a[p1[i]][p2[p1[i]]])
 					used |= 1 << p2[p1[i]];
 			}
 			for (int i = 0; i < n; ++i)
 			{
 				if (!a[p1[i]][p2[p1[i]]])
 				{
 					int bad = 0;
 					for (int j = 0; j < n; ++j)
 					{
 						if (!(used & (1 << j)) && a[p1[i]][j])
 							bad = 1;
 					}
 					if (!bad)
 						return 0;
 				}
 			}
 
 
 		} while (next_permutation(p2.begin(), p2.end()));
 
 	} while (next_permutation(p1.begin(), p1.end()));
 
 	return 1;
 }
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("D-small-attempt0.in", "r", stdin);
 	freopen("D-small-attempt0.out", "w", stdout);
 #endif
 	scanf("%d", &T);
 	for (int test = 1; test <= T; ++test)
 	{
 		scanf("%d", &n);
 
 		G = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			scanf("%s", buf);
 			for (int j = 0; j < n; ++j)
 				G |= (buf[j] - '0') << (i * n + j);
 		}
 
 		int res = (int)1e9;
 		for (int i = 0; i < 1 << (n * n); ++i)
 		{
 			if (ok(G | i))
 				res = min(res, cnt(i ^ (G & i)));
 		}
 
 		printf("Case #%d: %d\n", test, res);
 
 
 	}
 	return 0;
 }