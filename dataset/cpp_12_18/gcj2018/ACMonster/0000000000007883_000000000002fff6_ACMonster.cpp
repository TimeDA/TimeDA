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

long long bound[1000], speed[1000], base[1000], a[1000];

long long solve(int m, int n, long long t) {
	for (int i = 0; i < n; i++)
		if (t < base[i])
			a[i] = 0;
		else
			a[i] = min(bound[i], (t - base[i]) / speed[i]);
	sort(a, a + n);
	long long sum = 0;
	for (int i = n - m; i < n; i++)
		sum += a[i];
	return sum;
}

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int m = get(), b = get(), n = get();
		for (int i = 0; i < n; i++) {
			bound[i] = get();
			speed[i] = get();
			base[i] = get();
		}
		long long l = 0, r = 1;
		while (solve(m, n, r) < b) {
			l = r + 1;
			r *= 2;
		}
		while (l < r) {
			long long mid = (l + r) / 2;
			if (solve(m, n, mid) < b)
				l = mid + 1;
			else
				r = mid;
		}
		printf("Case #%d: ", test);
		cout << l << endl;
	}
	return 0;
}
