#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int a, b;
		cin >> a >> b;
		int n;
		cin >> n;

		int low = 1;
		int high = b;

		while (low <= high) {
			int mid = (low + high) / 2;
			cout << mid << endl;
			string s; cin >> s;
			if (s == "CORRECT") break;
			if (s == "TOO_SMALL") {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
	}
	return 0;
}
