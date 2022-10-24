#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

string solve() {
	int n;
	cin >> n;
	vector<int> a0, a1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (i & 1) {
			a1.push_back(x);
		} else {
			a0.push_back(x);
		}
	}
	sort(begin(a0), end(a0));
	sort(begin(a1), end(a1));
	if (a1.size() < a0.size()) {
		a1.push_back((int)1e9);
	}
	vector<int> a;
	for (int i = 0; i < a1.size(); ++i) {
		a.push_back(a0[i]);
		a.push_back(a1[i]);
	}
	if (is_sorted(begin(a), end(a))) {
		return "OK";
	}

	for (int i = 0; i < (int)a.size() - 1; ++i) {
		if (a[i] > a[i + 1]) {
			return to_string(i);
		}
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