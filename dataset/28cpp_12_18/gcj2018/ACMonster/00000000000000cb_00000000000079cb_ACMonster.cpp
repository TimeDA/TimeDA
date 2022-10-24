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

const int MAXN = 100000;

int a[MAXN], x[MAXN], y[MAXN];

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int n = get(), n0 = 0, n1 = 0;
		for (int i = 0; i < n; i++) {
			a[i] = get();
			if (~i & 1)
				x[n0++] = a[i];
			else
				y[n1++] = a[i];
		}
		sort(x, x + n0);
		sort(y, y + n1);
		for (int i = 0; i < n0; i++)
			a[i * 2] = x[i];
		for (int i = 0; i < n1; i++)
			a[i * 2 + 1] = y[i];
		int p = 0;
		while (p + 1 < n && a[p] <= a[p + 1])
			p++;
		printf("Case #%d: ", test);
		if (p + 1 == n)
			printf("OK\n");
		else
			printf("%d\n", p);
	}
	return 0;
}
