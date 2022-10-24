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

const int maxN = 120;
int s;
int a[maxN], b[maxN], d[maxN];

void solve(int tcase) {
	printf("Case #%d: ", tcase);

	scanf("%d", &s);

	vector<int> pts;

	for (int i = 0; i < s; ++i) {
		scanf("%d%d%d", &d[i], &a[i], &b[i]);
		pts.push_back(a[i] + d[i]);
		pts.push_back(d[i] - b[i]);
	}

	set<pair<int, int> > res;

	int resM = 0;

	vector<int> used(s, 0);
	for (int i = 0; i < pts.size(); ++i) {
		for (int j = 0; j < pts.size(); ++j) {
			int N = pts[i], M = pts[j];

			for (int k = 0; k < s; ++k) {
				if (a[k] + d[k] == N || d[k] - b[k] == M) {
					used[k] = 1;
				} else {
					used[k] = 0;
				}
			}

			int tm = 0;
			for (int k = 0; k < s; ) {
				if (used[k]) {
					int j = k;
					int tr = 0;
					while (j < s && used[j]) {
						++tr;
						++j;
					}
					tm = max(tm, tr);
					k = j;
				} else {
					++k;
				}
			}

			if (tm >= resM) {
				if (tm > resM) {
					res.clear();
				}
				resM = tm;
				for (int k = 0; k < s;) {
					if (used[k]) {
						int j = k;
						int tr = 0;
						while (j < s && used[j]) {
							++tr;
							++j;
						}
						if (tr == resM) {
							res.insert(make_pair(k, j));
						}
						k = j;
					} else {
						++k;
					}
				}
			}
		}
	}

	printf("%d %d\n", resM, res.size());
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