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
 
 const string PROBLEM = "B-small-attempt0";
 
 int N;
 int R, O, Y, G, B, V;
 
 void read()
 {
 	scanf("%d", &N);
 	scanf("%d", &R);
 	scanf("%d", &O);
 	scanf("%d", &Y);
 	scanf("%d", &G);
 	scanf("%d", &B);
 	scanf("%d", &V);
 
 }
 
 int E[3][3];
 const char C[] = { 'R', 'Y', 'B' };
 
 void go(int v, string & s)
 {
 	for (int i = 0; i < 3; ++i)
 	{
 		if (E[v][i])
 		{
 			E[v][i]--;
 			go(i, s);
 		}
 	}
 	s += C[v];
 }
 
 string get(int k, char c1, char c2)
 {
 	string res = "";
 	for (int i = 0; i < k; ++i)
 	{
 		res += c1;
 		res += c2;
 	}
 	return res;
 }
 
 string solve()
 {
 	if (R == G && R + G == N)
 		return get(G, 'R', 'G');
 	if (Y == V && Y + V == N)
 		return get(V, 'Y', 'V');
 	if (B == O && B + O == N)
 		return get(O, 'B', 'O');
 
 	if (O > 0 && B < O + 1)
 		return "IMPOSSIBLE";
 	if (V > 0 && Y < V + 1)
 		return "IMPOSSIBLE";
 	if (G > 0 && R < G + 1)
 		return "IMPOSSIBLE";
 
 	R -= G;
 	Y -= V;
 	B -= O;
 
 	bool ok = 0;
 	for (int BR = 0; BR <= R; ++BR)
 	{
 		int YR = R - BR;
 		for (int RB = 0; RB <= R; ++RB)
 		{
 			int RY = R - RB;
 
 			int YB = B - RB;
 			int BY = Y - RY;
 
 			if (YB < 0 || BY < 0)
 				continue;
 			if (YR + YB != Y)
 				continue;
 			if (BR + BY != B)
 				continue;
 			
 			E[0][1] = RY;
 			E[0][2] = RB;
 			E[1][0] = YR;
 			E[1][2] = YB;
 			E[2][0] = BR;
 			E[2][1] = BY;
 			ok = 1;
 		}
 	}
 
 	if (!ok)
 		return "IMPOSSIBLE";
 
 	string res = "";
 	if (R)
 		go(0, res);
 	else if (Y)
 		go(1, res);
 	else
 		go(2, res);
 	res.pop_back();
 
 	string rg = get(G, 'R', 'G');
 	string bo = get(O, 'B', 'O');
 	string yv = get(V, 'Y', 'V');
 
 	if (G)
 	{
 		int pos = res.find('R');
 		res = res.substr(0, pos) + rg + res.substr(pos);
 	}
 	if (O)
 	{
 		int pos = res.find('B');
 		res = res.substr(0, pos) + bo + res.substr(pos);
 	}
 	if (V)
 	{
 		int pos = res.find('Y');
 		res = res.substr(0, pos) + yv + res.substr(pos);
 	}
 
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
 		printf("%s\n", solve().c_str());
 	}
 	return 0;
 }