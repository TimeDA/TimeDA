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

const int maxN = 10;
int n;
int a[maxN][maxN];
int best;
int cntA[maxN][maxN][maxN], cntB[maxN][maxN][maxN];

void rec(int index, int cur) {
	if (cur >= best) {
		return;
	}
	if (index == n * n) {
		best = min(best, cur);
		return ;
	}

	int x = index / n;
	int y = index % n;
	int old = a[x][y];
	if (old > 0 && cntA[x][y][old] == 0) {
		int i = old;
		for (int j = 0; j < n; ++j) {
			if (j != y) {
				++cntA[x][j][i];
			}
			if (j != x) {
				++cntA[j][y][i];
			}
		}
		rec(index + 1, cur + (i == old ? 0 : 1));
		for (int j = 0; j < n; ++j) {
			if (j != y) {
				--cntA[x][j][i];
			}
			if (j != x) {
				--cntA[j][y][i];
			}
		}
	}
	if (old < 0 && cntB[x][y][-old] == 0) {
		int i = -old;
		for (int j = 0; j < n; ++j) {
			if (j != y) {
				++cntB[x][j][i];
			}
			if (j != x) {
				++cntB[j][y][i];
			}
		}
		rec(index + 1, cur + (i == -old ? 0 : 1));
		for (int j = 0; j < n; ++j) {
			if (j != y) {
				--cntB[x][j][i];
			}
			if (j != x) {
				--cntB[j][y][i];
			}
		}
	}
	rec(index + 1, cur + 1);
}

void solve(int test) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			for (int k = 1; k <= n; ++k) {
				cntA[i][j][k] = cntB[i][j][k] = 0;
			}
		}
	}
	best = n * n;
	rec(0, 0);
	printf("Case #%d: %d\n", test, best);
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
