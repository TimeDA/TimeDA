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
 	static const int N = 100;
 
 	int n;
 	char buf[2];
 
 	bool a[N][N];
 	bool b[N][N];
 
 	bool used[N][N];
 
 	vector<int> G[2 * N - 1];
 	int visited[2 * N - 1];
 	int mate[2 * N - 1];
 
 	solver()
 	{
 		memset(a, 0, sizeof(a));
 		memset(b, 0, sizeof(b));
 		int m;
 		scanf("%d%d", &n, &m);
 		for (int i = 0; i < m; ++i)
 		{
 			int x, y;
 			scanf("%s%d%d", buf, &x, &y);
 			x--, y--;
 			switch (buf[0])
 			{
 			case '+':
 				a[x][y] = 1;
 				break;
 			case 'x':
 				b[x][y] = 1;
 				break;
 			case 'o':
 				a[x][y] = 1;
 				b[x][y] = 1;
 				break;
 			}
 		}
 	}
 
 	struct P
 	{
 		char c;
 		int x, y;
 	};
 
 	pair<int, int> diag(int x, int y)
 	{
 		return {x + y, n - 1 + x - y};
 	}
 
 	bool go(int v)
 	{
 		if (v == -1)
 			return 1;
 		if (visited[v])
 			return 0;
 		visited[v] = 1;
 		for (int i = 0; i < G[v].size(); ++i)
 		{
 			int to = G[v][i];
 			if (go(mate[to]))
 			{
 				mate[to] = v;
 				return 1;
 			}
 		}
 		return 0;
 	}
 
 	int solve(vector<P> & res)
 	{
 		vector<bool> used_row(n, 0);
 		vector<bool> used_col(n, 0);
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if (b[i][j])
 				{
 					used_row[i] = 1;
 					used_col[j] = 1;
 				}
 			}
 		}
 		memset(used, 0, sizeof(used));
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if (!used_row[i] && !used_col[j])
 				{
 					used_row[i] = used_col[j] = 1;
 					b[i][j] = 1;
 					used[i][j] = 1;
 				}
 			}
 		}
 		vector<bool> used_diag1(2 * n - 1, 0);
 		vector<bool> used_diag2(2 * n - 1, 0);
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if (a[i][j])
 				{
 					auto p = diag(i, j);
 					used_diag1[p.first] = 1;
 					used_diag2[p.second] = 1;
 				}
 			}
 		}
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				auto p = diag(i, j);
 				if (!used_diag1[p.first] && !used_diag2[p.second])
 					G[p.first].push_back(p.second);
 			}
 		}
 
 		memset(mate, -1, sizeof(mate));
 		for (int i = 0; i < 2 * n - 1; ++i)
 		{
 			memset(visited, 0, sizeof(visited));
 			go(i);
 		}
 
 		for (int i = 0; i < 2 * n - 1; ++i)
 		{
 			if (mate[i] == -1)
 				continue;
 			int x = (i + mate[i] - n + 1) / 2;
 			int y = mate[i] - x;
 			a[x][y] = 1;
 			used[x][y] = 1;
 		}
 		
 		int points = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				points += a[i][j] + b[i][j];
 				if (!used[i][j])
 					continue;
 				if (a[i][j] && b[i][j])
 					res.push_back({'o', i + 1, j + 1});
 				else if (a[i][j])
 					res.push_back({ '+', i + 1, j + 1 });
 				else if (b[i][j])
 					res.push_back({ 'x', i + 1, j + 1 });
 			}
 		}
 
 		vector<pair<int, int> > A, B;
 
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if (a[i][j])
 					A.push_back({i, j});
 				if (b[i][j])
 					B.push_back({i, j});
 			}
 		}
 		for (int i = 0; i < A.size(); ++i)
 		{
 			for (int j = i + 1; j < A.size(); ++j)
 			{
 				if (A[i].first - A[i].second == A[j].first - A[j].second)
 					++*(char*)0;
 				if (A[i].first + A[i].second == A[j].first + A[j].second)
 					++*(char*)0;
 			}
 		}
 		for (int i = 0; i < B.size(); ++i)
 		{
 			for (int j = i + 1; j < B.size(); ++j)
 			{
 				if (B[i].first == B[j].first)
 					++*(char*)0;
 				if (B[i].second == B[j].second)
 					++*(char*)0;
 			}
 		}
 		
 		return points;
 	}
 };
 
 int main()
 {
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	
 	int t;
 	scanf("%d", &t);
 
 	for (int test_case = 1; test_case <= t; ++test_case)
 	{
 		solver s;
 		vector<solver::P> res;
 		printf("Case #%d: %d", test_case, s.solve(res));
 		printf(" %d\n", res.size());
 		for (auto r : res)
 			printf("%c %d %d\n", r.c, r.x, r.y);		
 	}
 	return 0;
 }