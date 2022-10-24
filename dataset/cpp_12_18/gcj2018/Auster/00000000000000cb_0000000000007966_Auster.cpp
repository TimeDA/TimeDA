#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int dmg(const string& s) {
	int res = 0;
	int d = 1;
	for (char c : s) {
		if (c == 'C') {
			d *= 2;
			if (d > (int)1e9)
				d = (int)1e9 + 1;
		} else {
			res += d;
			if (res > (int)1e9)
				res = (int)1e9 + 1;
		}
	}
	return res;
}

string solve() {
	int d;
	cin >> d;
	string s;
	cin >> s;
	if (count(begin(s), end(s), 'S') > d) {
		return "IMPOSSIBLE";
	}
	for(int res = 0; ;res++) {
		int have = dmg(s);
		if (have <= d) {
			return to_string(res);
		}
		int i = (int)s.size() - 1;
		while (i > 0 && (s[i] == 'C' || s[i - 1] == 'S')) {
			i--;
		}
		swap(s[i], s[i - 1]);
	}
	return "";
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
		cout << "Case #" << i << ": " << solve() << '\n';
	return 0;
}