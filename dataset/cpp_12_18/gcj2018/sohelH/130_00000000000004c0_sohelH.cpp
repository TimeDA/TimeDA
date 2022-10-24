#include<bits/stdc++.h>

using namespace std;

bool allZero(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 0) return false;
	}
	return true;
}

int maxIndex(vector<int> &v) {
	int idx = -1;
	int mx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > mx) {
			mx = v[i];
			idx = i;
		}
	}
	return idx;
}

bool valid(vector<int> &v) {
	int sum = accumulate(v.begin(), v.end(), 0);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] * 2 > sum) return false;
	}
	return true;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}
		printf("Case #%d:", cases);
		while( !allZero(v) ) {
			int m = maxIndex(v);
			v[m]--;
			string s = "";
			s += (m + 'A');
			if (!valid(v)) {
				m = maxIndex(v);
				v[m]--;
				s += (m + 'A');
			}

			cout << " " << s;
		}
		cout << endl;

	}
	return 0;
}
