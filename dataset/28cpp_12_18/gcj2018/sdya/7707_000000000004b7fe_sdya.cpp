#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 11000;
int n, x[maxN], y[maxN];

long long dist(long long x1, long long y1, long long x2, long long y2) {
	return max(abs(x1 - x2), abs(y1 - y2));
}

long long getD(long long u, long long v) {
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, dist(u, v, x[i], y[i]));
	}
	return res;
}

bool check(long long D) {
	long long lx = (long long)(x[0]) - D, rx = (long long)(x[0]) + D;
	long long ly = (long long)(y[0]) - D, ry = (long long)(y[0]) + D;

	for (int i = 1; i < n; ++i) {
		long long lx1 = (long long)(x[i]) - D, rx1 = (long long)(x[i]) + D;
		long long ly1 = (long long)(y[i]) - D, ry1 = (long long)(y[i]) + D;

		lx = max(lx, lx1);
		rx = min(rx, rx1);

		ly = max(ly, ly1);
		ry = min(ry, ry1);
		if (lx > rx) {
			return false;
		}
		if (ly > ry) {
			return false;
		}
	}
	return true;
}

long long dx[] = {-1, 0, 0, 1};
long long dy[] = { 0,-1, 1, 0};

long long solve() {
	long long l = 0, r = 1000000000;
	while (r - l > 1) {
		long long m = (l + r) / 2;
		if (check(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	if (check(l)) {
		return l;
	}
	return r;
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	long long res = solve();
	printf("Case #%d: %d\n", test, (int)(res));
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}

	return 0;
}
