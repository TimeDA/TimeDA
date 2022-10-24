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

const int maxN = 12;
int x[maxN], y[maxN], z[maxN];
int n;

struct Plane {
	long long A, B, C, D;
	long long value(long long x, long long y, long long z) {
		long long r = A * x + B * y + C * z + D;
		if (r > 0) {
			return 1;
		}
		if (r < 0) {
			return -1;
		}
		return 0;
	}
};

Plane p[maxN][maxN][maxN];

long long det(long long x1, long long y1, long long z1,
	long long x2, long long y2, long long z2,
	long long x3, long long y3, long long z3)
{
	return x1 * (y2 * z3 - z2 * y3) - y1 * (x2 * z3 - z2 * x3) + z1 * (x2 * y3 - y2 * x3);
}


Plane build(long long x1, long long y1, long long z1,
	long long x2, long long y2, long long z2,
	long long x3, long long y3, long long z3)
{
	Plane res;
	res.D = det(x1, y1, z1, x2, y2, z2, x3, y3, z3);
	res.A = -det(1, y1, z1, 1, y2, z2, 1, y3, z3);
	res.B = -det(x1, 1, z1, x2, 1, z2, x3, 1, z3);
	res.C = -det(x1, y1, 1, x2, y2, 1, x3, y3, 1);
	return res;
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				p[i][j][k] = build(x[i], y[i], z[i], x[j], y[j], z[j], x[k], y[k], z[k]);
			}
		}
	}
	vector < int > order(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i;
	}
	printf("Case #%d:", test);
	do {
		bool good = true;
		for (int i = 1; i + 2 < n && good; ++i) {
			Plane &q = p[order[i]][order[i + 1]][order[i + 2]];
			long long s = q.value(x[order[i]], y[order[i]], 0);
			for (int j = 0; j < i; ++j) {
				long long c = q.value(x[order[j]], y[order[j]], z[order[j]]);
				if (c != s) {
					good = false;
					break;
				}
			}
		}
		if (good) {
			for (int i = 0; i < order.size(); ++i) {
				printf(" %d", order[i] + 1);
			}
			break;
		}
	} while (next_permutation(order.begin(), order.end()));
	printf("\n");
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
