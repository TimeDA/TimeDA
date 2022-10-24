#include<bits/stdc++.h>

using namespace std;

int n;

int grid[10][10];
int res;

void dfs(int r, int c, int d) {
	if (d >= res) return;

	if (c == n) {
		c = 0;
		r++;
	}

	if (r == n) {
		if (d < res) {
			res = d;
		}
		return;
	}

	// don't change
	bool yes = true;
	for (int i = r - 1; i >= 0; i--) {
		if (grid[r][c] == grid[i][c]) yes = false;
	}
	for (int j = c - 1; j >= 0; j--) {
		if (grid[r][c] == grid[r][j]) yes = false;
	}

	if (yes) {
		dfs(r, c + 1, d);
	}

	// change
	for (int k = -n; k <= n; k++) {
		int newCol = 0;
		bool yes = true;
		for (int i = 0; i < n; i++) {
			if (i == r) continue;
			if (grid[i][c] == k) yes = false;
		}
		for (int j = 0; j < n; j++) {
			if (j == c) continue;
			if (grid[r][j] == k) yes = false;
		}
		if (yes) {
			int origin = grid[r][c];
			grid[r][c] = k;
			dfs(r, c + 1, d + 1);
			grid[r][c] = origin;
			break;
		}
	}

}


int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				cin >> grid[i][j];
		}
		res = n*n;

		dfs(0, 0, 0);
		printf("Case #%d: %d\n", cases, res);
	}
	return 0;
}
