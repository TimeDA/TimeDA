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
 
 const string PROBLEM = "C-small-attempt0";
 
 int N, Q;
 int E[100], S[100];
 int G[100][100];
 int U[100], V[100];
 
 
 void read()
 {
 	scanf("%d%d", &N, &Q);
 	for (int i = 0; i < N; ++i)
 		scanf("%d%d", &E[i], &S[i]);
 	for (int i = 0; i < N; ++i)
 		for (int j = 0; j < N; ++j)
 			scanf("%d", &G[i][j]);
 	for (int i = 0; i < Q; ++i)
 	{
 		scanf("%d%d", &U[i], &V[i]);
 		U[i]--;
 		V[i]--;
 	}
 }
 
 int D[100][100];
 int used[100];
 
 double T[100];
 
 double go(int s, int e)
 {
 	for (int i = 0; i < N; ++i)
 		T[i] = 1e18;
 	T[s] = 0;
 	memset(used, 0, sizeof(used));
 	for (int i = 0; i < N; ++i)
 	{
 		int v = -1;
 		for (int j = 0; j < N; ++j)
 			if (!used[j] && (v == -1 || T[j] < T[v]))
 				v = j;
 		used[v] = 1;
 		for (int to = 0; to < N; ++to)
 		{
 			if (D[v][to] > E[v])
 				continue;
 			T[to] = min(T[to], T[v] + (0.0 + D[v][to]) / S[v]);
 		}
 	}
 	return T[e];
 }
 
 vector<double> solve()
 {
 	for (int i = 0; i < N; ++i)
 		for (int j = 0; j < N; ++j)
 			D[i][j] = (int)2e9;
 	for (int i = 0; i < N; ++i)
 	{
 		D[i][i] = 0;
 		memset(used, 0, sizeof(used));
 		for (int j = 0; j < N; ++j)
 		{
 			int v = -1;
 			for (int k = 0; k < N; ++k)
 				if (!used[k] && (v == -1 || D[i][k] < D[i][v]))
 					v = k;
 			if (D[i][v] >= (int)2e9)
 				break;
 			used[v] = 1;
 			for (int to = 0; to < N; ++to)
 			{
 				if (G[v][to] == -1)
 					continue;
 				if (D[i][v] + G[v][to] > E[i])
 					continue;
 				D[i][to] = min(D[i][to], D[i][v] + G[v][to]);
 			}
 		}
 	}
 	vector<double> res;
 	for (int i = 0; i < Q; ++i)
 		res.push_back(go(U[i], V[i]));
 	return res;
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
 		auto res = solve();
 		for (double y : res)
 			printf("%.10lf ", y);
 		printf("\n");
 	}
 	return 0;
 }