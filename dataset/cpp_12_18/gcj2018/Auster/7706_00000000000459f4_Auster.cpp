#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <memory.h>

using namespace std;

typedef long long LL;

int n, m;
int a[21][21];

void read()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			a[i][j] = s[j] == 'B';
	}
}

int cnt(int x1, int x2, int y1, int y2, int val)
{
	int res = 0;
	for (int i = x1; i < x2; ++i)
		for (int j = y1; j < y2; ++j)
			res += a[i][j] == val;
	return res;
}

int used[21][21];

bool bound(int x, int y, int x1, int y1, int x2, int y2)
{
	return x >= x1 && x < x2 && y >= y1 && y < y2;
}

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y, int x1, int y1, int x2, int y2, int val)
{
	if (!bound(x, y, x1, y1, x2, y2))
		return 0;
	if (used[x][y] || a[x][y] != val)
		return 0;
	used[x][y] = 1;
	int res = 1;
	for (int d = 0; d < 4; ++d)
	{
		int tox = x + dx[d];
		int toy = y + dy[d];
		res += dfs(tox, toy, x1, y1, x2, y2, val);
	}
	return res;
}

void solve()
{
	int best = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int t1 = 0; t1 <= 2; ++t1)
			{
				for (int t2 = 0; t2 <= 2; ++t2)
				{
					for (int t3 = 0; t3 <= 2; ++t3)
					{
						for (int t4 = 0; t4 <= 2; ++t4)
						{
							memset(used, 0, sizeof(used));
							int now = 0;
							now += dfs(i - 1, j - 1, 
								0, 0, i, j, t1);
							now += dfs(i, j - 1, 
								i, 0, n, j, t2);
							now += dfs(i - 1, j, 
								0, j, i, m, t3);
							now += dfs(i, j, 
								i, j, n, m, t4);
							best = max(best, now);
						}
					}
				}
			}
		}
	}
	cout << best << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		read();
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}