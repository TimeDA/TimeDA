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

vector<int> a;

int status[maxN];
int need[maxN];
int leftgap[maxN];
int needsmallest;
int res;

void rec(int left, int idx, int sum, int p) {
	if (left == 0 && idx >= a.size()) {
		res = max(res, sum);
		return;
	}
	int lim = 1;

	if (idx < a.size()) {
		lim = a[idx];
	}

	for (int i = lim; i <= min(left, p); ++i) {
		rec(left - i, idx + 1, sum + status[i], i);
	}
}

void solve(int tcase) {
	printf("Case #%d: ", tcase);

	int n, l;
	scanf("%d%d", &n, &l);
	a.resize(l);
	int cur = 0;
	for (int i = 0; i < l; ++i) {
		scanf("%d", &a[i]);
		cur += a[i];
	}

	for (int i = 1; i <= n; ++i) {
		double val = (double)(i) / n * 100.;
		status[i] = int(val + 0.5);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	res = -1;
	rec(n, 0, 0, n);

	printf("%d\n", res);
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