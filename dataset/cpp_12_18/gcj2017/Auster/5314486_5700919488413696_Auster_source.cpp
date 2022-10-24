#define _CRT_SECURE_NO_WARNINGS
 
 #pragma comment(linker, "/STACK:250000000")
 
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
 #include <cstring>
 #include <ctime>
 #include <cassert>
 
 #define y1 klfjvkldfngldf
 
 using namespace std;
 
 typedef long long LL;
 
 int n, p;
 int g[4];
 
 
 void read()
 {
 	memset(g, 0, sizeof(g));
 	scanf("%d%d", &n, &p);
 	for (int i = 0; i < n; ++i)
 	{
 		int x;
 		scanf("%d", &x);
 		g[x % p]++;
 	}
 }
 
 struct node
 {
 	LL hash;
 	int next;
 	int id;
 };
 
 const int M = 1 << 21;
 int First[M];
 node HT[M];
 int N;
 
 int dp[M];
 
 void init()
 {
 	memset(First, -1, sizeof(First));
 	memset(dp, -1, sizeof(dp));
 	N = 0;
 }
 
 int add(LL hash)
 {
 	int h = hash & (M - 1);
 	HT[N].hash = hash;
 	HT[N].id = N;
 	HT[N].next = First[h];
 	First[h] = N;
 	return N++;
 }
 
 int get(LL hash)
 {
 	int h = hash & (M - 1);
 	for (int i = First[h]; i != -1; i = HT[i].next)
 		if (HT[i].hash == hash)
 			return i;
 	return -1;
 }
 
 LL Hash(int * a)
 {
 	LL h = 0;
 	for (int i = 0; i < p; ++i)
 		h = h * 2999 + a[i];
 	return h;
 }
 
 int go(int * a, int old)
 {
 	int total = accumulate(a, a + p, 0);
 	if (total == 0)
 		return 0;
 	LL h = Hash(a);
 	int id = get(h);
 	if (id != -1)
 		return dp[id];
 	id = add(h);
 	dp[id] = 0;
 	for (int i = 0; i < p; ++i)
 	{
 		if (a[i] > 0)
 		{
 			a[i]--;
 			dp[id] = max(dp[id], go(a, (old + i) % p));
 			a[i]++;
 		}
 	}
 	dp[id] += old == 0;
 	return dp[id];
 }
 
 int solve()
 {
 	init();
 	return go(g, 0);
 }
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 	int t;
 	scanf("%d", &t);
 
 	for (int i = 1; i <= t; ++i)
 	{
 		read();
 		printf("Case #%d: %d\n", i, solve());
 	}
 	return 0;
 }