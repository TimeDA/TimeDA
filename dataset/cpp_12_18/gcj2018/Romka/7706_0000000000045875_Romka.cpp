#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int n, a[7][7];

void solve() {
	scanf("%d", &n);
	forn(i, n) forn(j, n) scanf("%d", &a[i][j]);

	int N = n * n;
	int ans = N;
	forn(mask, 1 << N) {
		int qc = 0;
		for (int x = mask; x > 0; x &= x - 1)
			qc++;
		if (qc > ans) continue;
			
		bool bad = false;
		forn(i, n) {
			int was = 0;
			forn(j, n) {
				int ind = i * n + j;
				if ((1 << ind) & mask) continue;
				if (was & (1 << (a[i][j] + n))) {
					bad = true;
					break;
				}
				was |= 1 << (a[i][j] + n);
			}
		}
		if (!bad)
		forn(j, n) {
			int was = 0;
			forn(i, n) {
				int ind = i * n + j;
				if ((1 << ind) & mask) continue;
				if (was & (1 << (a[i][j] + n))) {
					bad = true;
					break;
				}
				was |= 1 << (a[i][j] + n);
			}
		}
		if (!bad) {
			ans = qc;
		}
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