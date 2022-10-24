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

const int maxN = 500;
char s[maxN][maxN];

void solve(int test) {
	int n;
	scanf("%d", &n);
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	if (a[0] == 0 || a[n - 1] == 0) {
		printf("Case #%d: IMPOSSIBLE\n", test);
		return;
	}
	vector < int > b(n), mx(n);
	vector < pair < int, int > > q;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			q.push_back(make_pair(a[i], i));
		}
	}

	for (int i = 0; i < n; ++i) {
		int total = i + 1;
		for (int j = 0; j < q.size(); ++j) {
			if (total <= q[j].first) {
				b[i] = q[j].second;
				break;
			} else {
				total -= q[j].first;
			}
		}
	}

	int m = 0;
	for (int i = 0; i < n; ++i) {
		m = max(m, abs(i - b[i]));
	}
	++m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			s[i][j] = '.';
		}
	}
	for (int i = 0; i < n; ++i) {
		char c = '.';
		if (i > b[i]) {
			c = '/';
		}
		if (i < b[i]) {
			c = '\\';
		}
		int j = i;
		int r = 0;
		while (j != b[i]) {
			s[r][j] = c;
			if (j > b[i]) {
				--j;
			} else if (j < b[i]) {
				++j;
			}
			++r;
		}
	}
	printf("Case #%d: %d\n", test, m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}

	return 0;
}
