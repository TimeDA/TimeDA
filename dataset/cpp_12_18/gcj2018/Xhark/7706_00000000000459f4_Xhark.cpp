
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_N = 32;
int R, C;
char str[MAX_N][MAX_N];
int pattern[MAX_N][MAX_N];
bool chk[MAX_N][MAX_N];

void setPattern(int sr, int er, int sc, int ec, char ch) {
	for (int r = sr; r <= er; r++) {
		for (int c = sc; c <= ec; c++) {
			pattern[r][c] = (str[r][c] == ch) ? 1 : 0;
		}
	}
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
int dfs(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (pattern[r][c] == 0) return 0;

	if (chk[r][c]) return 0;
	chk[r][c] = true;
	int res = 1;
	for (int d = 0; d < 4; d++) {
		res += dfs(r + dx[d], c + dy[d]);
	}
	return res;
}
int getCount() {
	for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) chk[r][c] = false;
	int res = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			res = max(res, dfs(r, c));
		}
	}
	return res;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int sol = 1;
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++) scanf("%s", str[i]);
		for (int t = 0; t < 2; t++) {
			char c = ((t == 0) ? 'B' : 'W');
			setPattern(0, R - 1, 0, C - 1, c);
			sol = max(sol, getCount());
		}
		for (int t = 0; t < 2; t++) {
			char c1 = ((t == 0) ? 'B' : 'W');
			char c2 = ((t == 0) ? 'W' : 'B');
			for (int i = 0; i < R - 1; i++) {
				setPattern(0, i, 0, C - 1, c1);
				setPattern(i + 1, R - 1, 0, C - 1, c2);
				sol = max(sol, getCount());
			}
			for (int i = 0; i < C - 1; i++) {
				setPattern(0, R - 1, 0, i, c1);
				setPattern(0, R - 1, i+1, C - 1, c2);
				sol = max(sol, getCount());
			}
		}
		for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++) for (int c = 0; c < 2; c++) for (int d = 0; d < 2; d++) {
			char ca = ((a == 0) ? 'B' : 'W');
			char cb = ((b == 0) ? 'B' : 'W');
			char cc = ((c == 0) ? 'B' : 'W');
			char cd = ((d == 0) ? 'B' : 'W');
			bool found = false;
			for (int r = 0; r < R - 1; r++) {
				for (int c = 0; c < C - 1; c++) {
					if (str[r][c] == ca && str[r][c + 1] == cb && str[r + 1][c] == cc && str[r + 1][c + 1] == cd) {
						found = true;
					}
				}
			}
			if (!found) continue;
			for (int r = 0; r < R - 1; r++) {
				for (int c = 0; c < C - 1; c++) {
					setPattern(0, r, 0, c, ca);
					setPattern(0, r, c+1, C-1, cb);
					setPattern(r+1, R-1, 0, c, cc);
					setPattern(r+1, R-1, c+1, C-1, cd);
					sol = max(sol, getCount());
				}
			}
		}
		static int cs = 1;
		printf("Case #%d: %d\n", cs++, sol);
	}
	return 0;
}