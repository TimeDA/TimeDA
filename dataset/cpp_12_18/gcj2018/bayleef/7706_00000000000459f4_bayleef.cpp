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

char a[4][5], b[8][10], c[16][20];

int u[4][5], v[4][5];

void dfs(int i, int j)
{
	v[i][j] = 1;
	if (i && u[i - 1][j] && !v[i - 1][j])
		dfs(i - 1, j);
	if (j && u[i][j - 1] && !v[i][j - 1])
		dfs(i, j - 1);
	if (i < 3 && u[i + 1][j] && !v[i + 1][j])
		dfs(i + 1, j);
	if (j < 4 && u[i][j + 1] && !v[i][j + 1])
		dfs(i, j + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		int n, m, i, j;
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", &a[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				b[2 * i][2 * j] = b[2 * i][2 * j + 1] = b[2 * i + 1][2 * j] = b[2 * i + 1][2 * j + 1] = a[i][j];
		for (i = 0; i < 2 * n; i++)
			for (j = 0; j < 2 * m; j++)
				c[2 * i][2 * j] = c[2 * i][2 * j + 1] = c[2 * i + 1][2 * j] = c[2 * i + 1][2 * j + 1] = b[i][j];
		int ans = 0;
		for (int msk = 1; msk < 1 << n * m; msk++)
		{
			int cur = 0;
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					u[i][j] = msk >> i * m + j & 1;
					v[i][j] = 0;
					cur += u[i][j];
				}
			bool good = true;
			for (i = 0; i < n && good; i++)
				for (j = 0; j < m && good; j++)
					if (u[i][j] == 1)
					{
						dfs(i, j);
						for (i = 0; i < n; i++)
							for (j = 0; j < m; j++)
								if (u[i][j] != v[i][j])
								{
									good = false;
									break;
								}
					}
			if (!good)continue;
			for (i = 0; i <= 3 * n; i++)
				for (j = 0; j <= 3 * m; j++)
				{
					bool ok = true;
					for (int k = 0; k < n; k++)
						for (int l = 0; l < m; l++)
							if (u[k][l] && a[k][l] != c[i + k][j + l])
							{
								ok = false;
								break;
							}
					if (ok)
					{
						i = 3 * n + 1;
						ans = max(ans, cur);
						break;
					}
				}
		}
		printf("Case #%d: %d\n", ts, ans);
	}
	return 0;
}