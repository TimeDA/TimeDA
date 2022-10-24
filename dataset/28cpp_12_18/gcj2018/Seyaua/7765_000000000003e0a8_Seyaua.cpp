#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int maxN = 101000;

long long dp[2][maxN];
int n;
long long w[maxN];

void solve(int tcase) {
	printf("Case #%d: ", tcase);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		w[i] = v;
	}
	memset(dp, -1, sizeof(dp));

	int u = 0, v = 1;
	dp[u][0] = 0;

	for (int i = 0; i < n; ++i) {
		memset(dp[v], -1, sizeof(dp[v]));
		for (int j = 0; j <= i; ++j) {
			if (dp[u][j] == -1) {
				break;
			}
			if (dp[v][j] == -1) {
				dp[v][j] = dp[u][j];
			} else {
				dp[v][j] = min(dp[v][j], dp[u][j]);
			}
			if (dp[u][j] <= 6 * w[i]) {
				dp[v][j + 1] = dp[u][j] + w[i];
			}
		}
		swap(u, v);
	}

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		if (dp[u][i] != -1) {
			res = max(res, i);
		}
	}
	cout << res << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		solve(i + 1);
	}

	return 0;
}