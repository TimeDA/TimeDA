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

const int maxN = 200;
int b[maxN];
int n;
map<pair<int, int>, int> vals;

void solve(int tcase) {
	printf("Case #%d: ", tcase);
	scanf("%d", &n);
	vals.clear();

	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	if (b[0] == 0 || b[n - 1] == 0) {
		printf("IMPOSSIBLE\n");
		return;
	}

	int mxrows = 0;

	int current = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < b[i]; ++j) {
			++current;

			if (current == i) {
				continue;
			}
			if (current < i) {
				int dep = 0;
				for (int k = current; k < i; ++k) {
					vals[make_pair(dep, k)] = 1;
					++dep;
					mxrows = max(mxrows, dep);
				}
			} else if (current > i) {
				int dep = 0;
				for (int k = current; k > i; --k) {
					vals[make_pair(dep, k)] = 2;
					++dep;
					mxrows = max(mxrows, dep);
				}
			}
		}
	}
	++mxrows;
	printf("%d\n", mxrows);
	for (int i = 0; i < mxrows; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vals.count(make_pair(i, j))) {
				int val = vals[make_pair(i, j)];
				if (val == 1) {
					printf("\\");
				} else {
					printf("/");
				}
			} else {
				printf(".");
			}
		}
		printf("\n");
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