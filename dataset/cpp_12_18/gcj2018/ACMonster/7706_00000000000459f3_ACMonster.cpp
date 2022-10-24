//Problem B

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

const int MAXM = 32;
const int MAXN = 500;

bool flag[MAXM][MAXN + 1][MAXN + 1];
int f[MAXM][MAXN + 1][MAXN + 1];

int dp(int r, int x, int y) {
	if (r >= MAXM)
		return 0;
	if (flag[r][x][y])
		return f[r][x][y];
	int tmp = 0, ans = 0;
	int remx = x, remy = y;
	while (true) {
		remx -= r;
		remy -= tmp;
		if (remx < 0 || remy < 0)
			break;
		ans = max(ans, dp(r + 1, remx, remy) + tmp + 1);
		tmp++;
	}
	flag[r][x][y] = true;
	return f[r][x][y] = ans;
}

int main() {
	int totalTest = get();
	memset(flag, 0, sizeof(flag));
	for (int test = 1; test <= totalTest; test++) {
		int m = get(), n = get();
		printf("Case #%d: %d\n", test, dp(0, m, n) - 1);
	}
	return 0;
}
