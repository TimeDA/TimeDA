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

int n, m;

vector < string > duplicate(vector < string > &s) {
	int n = s.size();
	int m = s[0].size();
	vector < string > res(2 * n, string(2 * m, '.'));
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * m; ++j) {
			res[i][j] = s[i / 2][j / 2];
		}
	}
	return res;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool used[5][5];
int b[1 << 12];

bool isValid(int u, int v) {
	return 0 <= u && u < n && 0 <= v && v < m;
}

void dfs(int x, int y, int mask) {
	used[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int value = nx * m + ny;
		if (isValid(nx, ny) && !used[nx][ny] && (mask & (1 << value))) {
			dfs(nx, ny, mask);
		}
	}
}

bool isConnected(int mask, vector < string > &s) {
	int n = s.size(), m = s[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			used[i][j] = false;
		}
	}
	int u = -1, v = -1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mask & (1 << (i * m + j))) {
				u = i;
				v = j;
				++cnt;
			}
		}
	}
	dfs(u, v, mask);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j]) {
				--cnt;
			}
		}
	}
	return cnt == 0;
}

void getPatterns(vector < string > &s, vector < pair < int, int > > &S) {
	int n = s.size();
	int m = s[0].size();

	for (int i = 1; i < (1 << (n * m)); ++i) {
		if (!isConnected(i, s)) {
			continue;
		}

		int color = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (i & (1 << (j * m + k))) {
					color *= 2;
					if (s[j][k] == 'W') {
						++color;
					}
				}
			}
		}
		S.push_back(make_pair(i, color));
	}
}

bool check(int mask, int colors, vector < string > &s) {
	int a = s.size(), b = s[0].size();
	for (int i = 0; i + n - 1 < a; ++i) {
		for (int j = 0; j + m - 1 < b; ++j) {
			int curcolors = 0;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (mask & (1 << (x * m + y))) {
						curcolors *= 2;
						if (s[i + x][j + y] == 'W') {
							++curcolors;
						}
					}
				}
			}
			if (curcolors == colors) {
				return true;
			}
		}
	}
	return false;
}

void solve(int test) {
	cin >> n >> m;
	vector < string > s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector < pair < int, int > > p;
	getPatterns(s, p);

	vector < vector < string > > combos;
	combos.push_back(s);
	for (int i = 0; i < 5; ++i) {
		s = duplicate(s);
		combos.push_back(s);
	}
	reverse(combos.begin(), combos.end());

	int res = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (b[p[i].first] <= res) {
			continue;
		}
		int u = 0;
		for (int j = 0; j < 2; ++j) {
			if (check(p[i].first, p[i].second, combos[j])) {
				++u;
			}
		}
		if (u >= 2 && b[p[i].first] > res) {
			res = max(res, b[p[i].first]);
			/*for (int a = 0; a < n; ++a) {
				for (int b = 0; b < m; ++b) {
					if (p[i].first & (1 << (a * m + b))) {
						cerr << "1";
					} else {
						cerr << "0";
					}
				}
				cerr << endl;
			}
			cerr << p[i].first << " " << p[i].second << endl;*/
		}
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < (1 << 12); ++i) {
		b[i] = 0;
		for (int j = 0; j < 12; ++j) {
			if (i & (1 << j)) {
				++b[i];
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}

	return 0;
}
