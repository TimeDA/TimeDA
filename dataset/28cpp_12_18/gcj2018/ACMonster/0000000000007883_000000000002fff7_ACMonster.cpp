//Problem C

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

double dp[25001];

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int n = get(), vol = n * 250;
		double p = get(), base = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int w = get(), h = get();
			base += 2 * (w + h);
			int l = min(w, h);
			double r = sqrt(w * w + h * h);
			for (int j = vol; j >= l; j--)
				dp[j] = max(dp[j], dp[j - l] + r);
		}
		double ans = 0.0;
		for (int i = 0; i <= vol; i++)
			if (base + 2 * i <= p)
				ans = max(ans, min(p, 2 * dp[i] + base));
		printf("Case #%d: ", test);
		printf("%0.10lf\n", ans);
	}
	return 0;
}
