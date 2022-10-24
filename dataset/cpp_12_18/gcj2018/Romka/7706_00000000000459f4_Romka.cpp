#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int n, m;
char s[5][7];
char a[50][70];
int w[5][7];

void dfs(int i, int j) {
	w[i][j] = 2;
	forn(e, 4) {
		int ni = i + di[e];
		int nj = j + dj[e];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m)
			if (w[ni][nj] == 1)
				dfs(ni, nj);
	}
}

bool checkw() {
	int runs = 0;
	forn(i, n) forn(j, m)
		if (w[i][j] == 1) {
			if (runs) return false;
			dfs(i, j);
			runs = 1;
		}
	return true;
}

void solve() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%s", s[i]);

	forn(i, n) forn(j, m) {
		int si = i * 4;
		int sj = j * 4;
		forn(qi, 4)
			forn(qj, 4)
				a[si + qi][sj + qj] = s[i][j];
	}

	int N = n * m;
	int ans = 0;
	for (int mask = (1 << N) - 1; mask >= 1; mask--) {
		int qc = 0;
		forn(i, n) forn(j, m) {
			w[i][j] = bool(mask & (1 << (i * m + j)));
			qc += w[i][j];
		}
		if (qc < ans || !checkw()) continue;
		// printf("check ok\n");

		forn(si, n * 4 - n + 1)
			forn(sj, m * 4 - m + 1) {
				bool found = true;
				forn(i, n)
					forn(j, m) {
						if (mask & (1 << (i * m + j)))
							if (s[i][j] != a[si + i][sj + j]) {
								found = false;
								goto out;
							}
					}
				out:;
				if (found) {
					/*forn(i, n) {
						forn(j, m) {
							if (mask & (1 << (i * m + j))) printf("%c", s[i][j]);
							else printf(".");
						}
						printf("\n");
					}
					printf("------------\n");*/
					ans = qc;
					goto o2;
				}
			}
		o2:;
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}