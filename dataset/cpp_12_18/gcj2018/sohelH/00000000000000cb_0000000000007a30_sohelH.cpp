#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int n;
		cin >> n;
		int s = n / 3;
		if (n % 3) s++;

		int grid[70][4] = {0};

		while (true) {
			int m = 0;
			int idx = -1;

			for (int i = 2; i < s; i++) {
				int cnt = 0;
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = 1; b <= 3; b++) {
						if (grid[a][b] == 0) cnt++;
					}
				if (cnt > m) {
					m = cnt;
					idx = i;
				}
			}

			cout << idx << " " << 2 << endl;

			int i, j;
			cin >> i >> j;
			if (i == 0 && j == 0) break;
			if (i == -1) break;
			grid[i][j] = 1;
		}
	}
	return 0;
}
