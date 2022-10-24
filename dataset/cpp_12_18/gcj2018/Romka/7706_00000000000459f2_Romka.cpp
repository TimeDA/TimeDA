#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

char ans[110][110];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), ml(n), mr(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (a[0] == 0 || a[n-1] == 0) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++)
			ans[i][j] = '.';
		ans[i][n] = 0;
	}

	int nz = 0;
	for (int i = 0; i < n; i++) ml[i] = mr[i] = i;

	for (int cc = 0; cc < n; cc++) {
		while (a[nz] == 0) nz++;
		if (cc < ml[nz]) ml[nz] = cc;
		if (cc > mr[nz]) mr[nz] = cc;
		a[nz]--;
	}

	for (int i = 0; i < n; i++) {
		if (ml[i] < i) {
			for (int j = i - 1; j >= ml[i]; j--)
				ans[n - (i-j)][j] = '\\';
		}
		if (mr[i] > i) {
			for (int j = i + 1; j <= mr[i]; j++)
				ans[n - (j-i)][j] = '/';
		}
	}

	int rows = 0;
	for (int i = 0; i <= n; i++) {
		bool p = i == n;
		for (int j = 0; j < n && !p; j++)
			p |= ans[i][j] != '.';
		rows += p;
	}
	cout << rows << endl;

	for (int i = 0; i <= n; i++) {
		bool p = i == n;
		for (int j = 0; j < n && !p; j++)
			p |= ans[i][j] != '.';
		if (p) printf("%s\n", ans[i]);
	}
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