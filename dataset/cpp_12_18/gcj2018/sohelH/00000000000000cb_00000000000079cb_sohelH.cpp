#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int n; cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (i % 2 == 0) even.push_back(a);
			else odd.push_back(a);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());

		vector<int> v(n);
		for (int i = 0; i < even.size(); i++) {
			v[i*2] = even[i];
		}
		for (int i = 0; i < odd.size(); i++) {
			v[i*2 + 1] = odd[i];
		}

		int ii = -1;
		for (int i = 1; i < n; i++) {
			if (v[i] < v[i-1]) {
				ii = i;
				break;
			}
		}
		cout << "Case #" << cases << ": ";
		if (ii == -1) cout << "OK" << endl;
		else cout << ii - 1 << endl;
	}
	return 0;
}
