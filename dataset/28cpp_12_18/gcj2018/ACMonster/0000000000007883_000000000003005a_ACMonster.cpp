//Problem A

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

int x[100], y[100];
int f[101], g[101];
int board[100][100];

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int n = get(), m = get(), a = get() + 1, b = get() + 1;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		int total = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c;
				while (c = getchar(), c != '@' && c != '.');
				board[i][j] = (c == '@');
				x[i] += board[i][j];
				y[j] += board[i][j];
				total += board[i][j];
			}
		bool ans = true;
		if (total % (a * b))
			ans = false;
		if (total) {
			int tmp = total / a;
			memset(f, -1, sizeof(f));
			f[0] = 0;
			for (int i = 0, sum = 0; i < n; i++) {
				sum += x[i];
				if (!(sum % tmp))
					f[sum / tmp] = i + 1;
			}
			tmp = total / b;
			memset(g, -1, sizeof(g));
			g[0] = 0;
			for (int i = 0, sum = 0; i < m; i++) {
				sum += y[i];
				if (!(sum % tmp))
					g[sum / tmp] = i + 1;
			}
			for (int i = 1; ans && i <= a; i++)
				ans = (f[i] != -1);
			for (int i = 1; ans && i <= b; i++)
				ans = (g[i] != -1);
			if (ans) {
				tmp = total / (a * b);
				for (int i = 0; i < a; i++)
					for (int j = 0; j < b; j++) {
						int sum = 0;
						for (int x = f[i]; x < f[i + 1]; x++)
							for (int y = g[i]; y < g[i + 1]; y++)
								sum += board[x][y];
						if (sum != tmp)
							ans = false;
					}
			}
		}
		printf("Case #%d: ", test);
		printf(ans ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
	return 0;
}
