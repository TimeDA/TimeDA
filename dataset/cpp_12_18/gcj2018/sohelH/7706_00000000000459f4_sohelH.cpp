#include<bits/stdc++.h>

using namespace std;

const int debug = 0;
int R, C;
int n;
vector<string> v;
int grid[5][5];
int move_[][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void dfs(int r, int c) {
	grid[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int rr = r + move_[i][0];
		int cc = c + move_[i][1];
		if (rr >= 0 && cc >= 0 && rr < R && cc < C && grid[rr][cc] == 1) {
			dfs(rr, cc);
		}
	}
}

bool isConnected(int state) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			grid[i][j] = 0;

	for (int i = 0; i < n; i++) {
		if (state & (1<<i)) {
			grid[i/C][i%C] = 1;
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (grid[i][j] == 1) {
				dfs(i, j);
				goto done;
			}
	done:
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (grid[i][j] == 1) return false;
	return true;
}

bool possible(int state) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			grid[i][j] = 0;

	for (int i = 0; i < n; i++) {
		if (state & (1<<i)) {
			grid[i/C][i%C] = 1;
		}
	}

	if (debug) {
		for (int i = 0; i < R; i++, cout << endl)
			for (int j = 0; j < C; j++)
				cout << grid[i][j];
	}

	int tCol = C * 2 * 2 * 2 * 2 * 2;
	int tRow = R * 2 * 2 * 2 * 2 * 2;
	vector<string> g;
	for (int i = 0; i < tRow; i++) {
		string s = "";
		for (int j = 0; j < tCol; j++) {
			s += ".";
		}
		g.push_back(s);
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int si = 32 * (i);
			int sj = (j % C) * 32;
			for (int a = si; a < si + 32; a++)
				for (int b = sj; b < sj + 32; b++)
					g[a][b] = v[i][j];
		}

	if (debug) {
		for (int i = 0; i < tRow; i++)
				cout << g[i] << endl;
	}

	for (int i = 0; (i + R) <= tRow; i++) {
		for (int j = 0; (j + C) <= tCol; j++) {
			bool yes = true;
			for (int a = 0; a < R && yes; a++)
				for (int b = 0; b < C; b++) {
					if (grid[a][b]) {
						if (v[a][b] != g[i + a][j + b]) yes = false;
					}
				}
			if (yes) return true;
		}
	}
	return false;


}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> R >> C;
		v.clear();
		for (int i = 0; i < R; i++) {
			string s; cin >> s; v.push_back(s);
		}

		n = R * C;
		int res = 0;
		for (int i = 1; i < (1<<n); i++) {
			bool connected = isConnected(i);
			if (!connected) continue;
			//if (debug) cout << i << endl;
			if (debug) {
				if (i != 31) continue;
			}
			if (possible(i)) {
				res = max(res, __builtin_popcount(i));
			}
		}
		printf("Case #%d: %d\n", cases, res);
	}
	return 0;
}
