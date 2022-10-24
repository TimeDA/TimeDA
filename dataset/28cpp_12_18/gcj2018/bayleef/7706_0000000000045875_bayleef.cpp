#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int a[200][200];

struct edge
{
	int i;
	int c;
	int f;
	int b;
}e;

vector<edge>v[202][200];

void add_edge(int i, int j, int x)
{
	e.i = j;
	e.c = 1;
	e.f = 0;
	e.b = v[j][x].size();
	v[i][x].push_back(e);
	e.i = i;
	e.c = 0;
	e.f = 0;
	e.b = v[i][x].size() - 1;
	v[j][x].push_back(e);
}

int u[202];

bool dfs(int cur, int fin, int x)
{
	if (cur == fin)return true;
	int i;
	u[cur] = true;
	for (i = 0; i < v[cur][x].size(); i++)
	{
		int j = v[cur][x][i].i;
		if (!u[j] && v[cur][x][i].c > v[cur][x][i].f && dfs(j, fin, x))
		{
			v[cur][x][i].f++;
			v[j][x][v[cur][x][i].b].f--;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		int n, i, j;
		scanf("%d", &n);
		for (i = 0; i < 2 * n + 2; i++)
			for (j = 0; j < 2 * n; j++)
				v[i][j].clear();
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				int x;
				scanf("%d", &x);
				if (x > 0)
					--x;
				else
					x += 2 * n;
				add_edge(i, j + n, x);
			}
		for (i = 0; i < n; i++)
			for (j = 0; j < 2 * n; j++)
			{
				add_edge(2 * n, i, j);
				add_edge(i + n, 2 * n + 1, j);
			}
		int ans = n * n;
		for (i = 0; i < 2 * n; i++)
		{
			for (j = 0; j < 2 * n + 2; j++)
				u[j] = 0;
			while (dfs(2 * n, 2 * n + 1, i))
			{
				--ans;
				for (j = 0; j < 2 * n + 2; j++)
					u[j] = 0;
			}
		}
		printf("Case #%d: %d\n", ts, ans);
	}
	return 0;
}