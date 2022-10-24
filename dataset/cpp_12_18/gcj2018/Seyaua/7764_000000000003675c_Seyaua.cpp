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

int m;
int r1[9], r2[9];
int g[9];
int curnum;

char used[45000000];
char solved[45000000];

int have[9];
int nine[9];

int get(int curnum) {
	if (used[curnum]) {
		return solved[curnum];
	}
	used[curnum] = 1;

	int val = curnum;
	int idx = 0;
	while (val > 0) {
		have[idx] = val % 9;
		val /= 9;
		++idx;
	}
	for (int i = idx; i < m; ++i) {
		have[idx] = 0;
	}

	solved[curnum] = have[0];

	for (int i = 0; i < m; ++i) {
		if (have[r1[i]] && have[r2[i]]) {
			solved[curnum] = max((int)solved[curnum], get(curnum - nine[r1[i]] - nine[r2[i]] + nine[i]));
		}
	}
	return solved[curnum];
}

void solve(int tcase) {
	memset(solved, 0, sizeof(solved));
	memset(used, 0, sizeof(used));
	nine[0] = 1;
	for (int i = 1; i < 9; ++i) nine[i] = 9 * nine[i - 1];
	printf("Case #%d: ", tcase);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &r1[i], &r2[i]);
		--r1[i], --r2[i];
	}
	curnum = 0;

	for (int i = 0; i < m; ++i) {
		scanf("%d", &g[i]);
		curnum += g[i] * nine[i];
	}

	printf("%d\n", get(curnum));
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