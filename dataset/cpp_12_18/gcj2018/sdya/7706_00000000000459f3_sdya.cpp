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

const int maxN = 510;
int r[maxN][maxN];

void smarter(int cur, int start, int n, int m, int rn, int rm, int bound = 1000) {
	r[rn][rm] = max(r[rn][rm], cur);

	if (start > n) {
		return;
	}
	for (int i = 0; i <= bound; ++i) {
		int sx = (i + 1) * start;
		int sy = i * (i + 1) / 2;
		if (sx > n || sy > m) {
			break;
		}
		int ncur = cur;
		ncur += i - (start == 0 ? 1 : 0) + 1;
		smarter(ncur, start + 1, n - sx, m - sy, rn + sx, rm + sy, i);
	}
}

void solve(int test) {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("Case #%d: %d\n", test, r[n][m]);
}

void precalc() {
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			r[i][j] = 0;
		}
	}
	smarter(0, 0, 500, 500, 0, 0);
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (i > 0) {
				r[i][j] = max(r[i][j], r[i - 1][j]);
			}
			if (j > 0) {
				r[i][j] = max(r[i][j], r[i][j - 1]);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	precalc();

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}

	return 0;
}
