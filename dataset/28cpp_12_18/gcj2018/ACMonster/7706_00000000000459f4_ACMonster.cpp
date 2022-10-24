//Problem D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int get() {
	char c;
	while (c = getchar(), c != '-' && (c < '0' || c > '9'));
	bool flag = (c == '-');
	if (flag)
		c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return flag ? -x : x;
}

const int MAXN = 20;
const int v[4][2] = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0}
};

int n, m, counter;
bool a[MAXN][MAXN], b[MAXN][MAXN];
bool c1[2], c2[4], c3[4], c4[16];
bool flag[MAXN][MAXN];

void dfs(int x, int y) {
	flag[x][y] = true;
	counter++;
	for (int i = 0; i < 4; i++) {
		int x0 = x + v[i][0];
		int y0 = y + v[i][1];
		if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < m && a[x0][y0] == b[x0][y0] && !flag[x0][y0])
			dfs(x0, y0);
	}
}

int solve() {
	memset(flag, 0, sizeof(flag));
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == b[i][j] && !flag[i][j]) {
				counter = 0;
				dfs(i, j);
				ans = max(ans, counter);
			}
	return ans;
}

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		n = get(); m = get();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c;
				while (c = getchar(), c != 'B' && c != 'W');
				a[i][j] = (c == 'B');
			}
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));
		memset(c4, 0, sizeof(c4));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				c1[a[i][j]] = true;
				if (j)
					c2[a[i][j - 1] * 2 + a[i][j]] = true;
				if (i)
					c3[a[i - 1][j] * 2 + a[i][j]] = true;
				if (i && j) {
					int mask = a[i - 1][j - 1] * 8 + a[i - 1][j] * 4 + a[i][j - 1] * 2 + a[i][j];
					c4[mask] = true;
				}
			}
		int ans = 0;
		for (int d1 = 0; d1 < 2; d1++)
			if (c1[d1]) {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						b[i][j] = d1;
				ans = max(ans, solve());
			}
		for (int d1 = 0; d1 < 2; d1++)
			for (int d2 = 0; d2 < 2; d2++)
				if (c2[d1 * 2 + d2])
					for (int c = 1; c < m; c++) {
						for (int i = 0; i < n; i++)
							for (int j = 0; j < m; j++)
								b[i][j] = (j < c) ? d1 : d2;
						ans = max(ans, solve());
					}
		for (int d1 = 0; d1 < 2; d1++)
			for (int d2 = 0; d2 < 2; d2++)
				if (c3[d1 * 2 + d2])
					for (int r = 1; r < n; r++) {
						for (int i = 0; i < n; i++)
							for (int j = 0; j < m; j++)
								b[i][j] = (i < r) ? d1 : d2;
						ans = max(ans, solve());
					}
		for (int d1 = 0; d1 < 2; d1++)
			for (int d2 = 0; d2 < 2; d2++)
				for (int d3 = 0; d3 < 2; d3++)
					for (int d4 = 0; d4 < 2; d4++)
						if (c4[d1 * 8 + d2 * 4 + d3 * 2 + d4])
							for (int r = 1; r < n; r++)
								for (int c = 1; c < m; c++) {
									for (int i = 0; i < n; i++)
										for (int j = 0; j < m; j++)
											if (i < r && j < c)
												b[i][j] = d1;
											else if (i < r && j >= c)
												b[i][j] = d2;
											else if (i >= r && j < c)
												b[i][j] = d3;
											else
												b[i][j] = d4;
									ans = max(ans, solve());
								}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
