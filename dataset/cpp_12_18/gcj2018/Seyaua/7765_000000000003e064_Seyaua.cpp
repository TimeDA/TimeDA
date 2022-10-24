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

int allowed[12][26];
set<string> have;
int n, l;
string cur;
string ans = "-";

void rec(int idx) {
	if (ans != "-") {
		return;
	}
	if (idx == l) {
		if (!have.count(cur)) {
			ans = cur;
			return;
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (allowed[idx][i]) {
			cur += char('A' + i);
			rec(idx + 1);
			cur.pop_back();
		}
	}
}

void solve(int tcase) {
	memset(allowed, 0, sizeof(allowed));
	printf("Case #%d: ", tcase);
	cin >> n >> l;
	vector<string> words(n);
	for (int i = 0; i < n; ++i) {
		cin >> words[i];
		for (int j = 0; j < l; ++j) {
			allowed[j][words[i][j] - 'A'] = 1;
		}
	}

	have = set<string>(words.begin(), words.end());

	cur = "";
	ans = "-";
	rec(0);

	cout << ans << endl;
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