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

const int maxN = 210;

int totalcnt[maxN];
int used[maxN];

void solve(int tcase) {
	int n;
	cin >> n;
	memset(totalcnt, 0, sizeof(totalcnt));
	memset(used, 0, sizeof(used));
	if (n == -1) {
		exit(0);
	}

	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;

		if (d == -1) {
			exit(0);
		}

		int mn = 5000;
		int idx = -1;

		for (int j = 0; j < d; ++j) {
			int x;
			cin >> x;
			++totalcnt[x];

			if (totalcnt[x] < mn && !used[x]) {
				mn = totalcnt[x];
				idx = x;
			}
		}

		if (idx >= 0) {
			used[idx] = 1;
		}

		cout << idx << endl;
	}
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