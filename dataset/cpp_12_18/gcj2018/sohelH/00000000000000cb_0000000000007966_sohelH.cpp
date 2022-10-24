#include<bits/stdc++.h>

using namespace std;

int D;

bool ok(string s) {
	int sum = 0;
	int heat = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'S') sum += heat;
		else heat *= 2;
	}
	return sum <= D;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> D;
		string s; cin >> s;

		int res = -1;
		for (int cnt = 0; ; cnt++) {
			if ( ok(s) ) {
				res = cnt;
				break;
			}
			bool done = true;
			for (int i = s.size() - 1; i > 0; i--) {
				if (s[i-1] == 'C' && s[i] == 'S') {
					done = false;
					swap(s[i-1], s[i]);
					break;
				}
			}
			if (done) break;
		}
		cout << "Case #" << cases << ": ";
		if (res == -1) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << res << endl;
		}
	}
	return 0;
}
