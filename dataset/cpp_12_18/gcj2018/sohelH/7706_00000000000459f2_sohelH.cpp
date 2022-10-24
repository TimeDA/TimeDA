#include<bits/stdc++.h>

using namespace std;

int debug = 0;
vector<int> v;
int n;
const string imp = "IMPOSSIBLE";

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}

		int target[105];
		bool yes = true;
		if (v[0] == 0 || v.back() == 0) {
			yes = false;
		}

		if (!yes) {
			printf("Case #%d: %s\n", cases, imp.c_str());
			continue;
		}

		for (int i = 0; i < n; i++) {
			target[i] = -1;
		}

		target[0] = 0;
		v[0]--;
		target[n-1] = n-1;
		v[n-1]--;

		for (int i = 0; i < n; i++) {
			if (v[i] > 0) {
				for (int j = 0; j < n; j++) {
					if (target[j] == -1) {
						target[j] = i;
						v[i]--;
						if (v[i] == 0) break;
					}
				}
			}
			if (v[i] > 0) yes = false;
		}

		if (!yes) {
			printf("Case #%d: %s\n", cases, imp.c_str());
			continue;
		}

		vector<string> res;
		for (int i = 0; i < 200; i++) {
			string s = "";
			for (int j = 0; j < n; j++)
				s += ".";
			res.push_back(s);
		}
		for (int i = 0; i < n; i++) {
			if (target[i] == i) continue;
			int dif = i - target[i];
			if (dif > 0) {
				int rr = 0;
				int cc = i;
				while(dif--) {
					res[rr][cc] = '/';
					rr++;
					cc--;
				}
			} else {
				dif *= -1;
				int rr = 0;
				int cc = i;
				while (dif--) {
					res[rr][cc] = '\\';
					rr++;
					cc++;
				}
			}
		}

		if (debug) {
			cout << "debug" << endl;
			for (int i = 0; i < 20; i++)
				cout << res[i] << endl;
		}

		int iRes;
		for (int i = 0; i < 200; i++) {
			bool allDot = true;
			for (int j = 0; j < n; j++) {
				if (res[i][j] != '.') allDot = false;
			}
			if (allDot) {
				iRes = i + 1;
				break;
			}
		}

		printf("Case #%d: %d\n", cases, iRes);
		for (int i = 0; i < iRes; i++) {
			cout << res[i] << endl;
		}

	}
	return 0;
}
