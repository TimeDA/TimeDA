#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;


bool go(int x, int y) {
	set<pair<int, int>> S;
	while (S.size() < 9)
	{
		cout << x << " " << y << endl;
		int rx, ry;
		cin >> rx >> ry;
		if (rx == 0 && ry == 0)
			return 1;
		S.insert({ rx, ry });
	}
	return 0;
}

void solve() {
	for (int i = 15; i <= 27; i += 3) {
		for (int j = 15; j <= 27; j += 3) {
			if (go(i, j))
				return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int a;
		cin >> a;
		solve();
	}
	//cout << "Case #" << i << ": " << "" << '\n';
	return 0;
}