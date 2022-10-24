#include<bits/stdc++.h>

using namespace std;

const int debug = 0;

int R, C;
int H, V;
vector<string> v;
int perGroup;
string impossible = "IMPOSSIBLE";
string possible = "POSSIBLE";

bool ok(int h1, int h2, vector<int> &vIndex) {
	int last = 0;

	for (int i = 0; i < vIndex.size(); i++) {
		int cnt = 0;
		for (int a = h1; a <= h2; a++) {
			for (int b = last; b <= vIndex[i]; b++) {
				if (v[a][b] == '@') cnt++;
			}
		}
		if (cnt != perGroup) return false;
		last = vIndex[i] + 1;
	}
	return true;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> R >> C >> H >> V;

		v.clear();

		for (int i = 0; i < R; i++) {
			string s; cin >> s; v.push_back(s);
		}

		int choc = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (v[i][j] == '@') choc++;
			}
		}

		int groups = (H + 1) * (V + 1);
		cout << "Case #" << cases << ": ";
		perGroup = choc / groups;
		if (choc % groups) {
			if (debug) cout << "1>>>" << endl;
			cout << impossible << endl;
			continue;
		}

		int vGroup = choc / ( V + 1);
		int hGroup = choc / ( H + 1);

		vector<int> vIndex;
		bool yes = true;

		int j = 0;
		for (int k = 0; k <= V && yes; k++) {
			int sum = 0;
			for (; j < C; j++) {
				for (int i = 0; i < R; i++) {
					if (v[i][j] == '@') sum++;
				}
				if (sum == vGroup) {
					break;
				} else if (sum > vGroup) {
					yes = false;
					if (debug) cout << "... " << sum << " " << j << endl;
					break;
				}
			}
			if (yes) {
				vIndex.push_back(j);
				j++;
			}
		}

		if (!yes) {
			if (debug) cout << "2>>>" << endl;
			cout << impossible << endl;
			continue;
		}

		int i = 0;
		int lastH = -1;
		for (int k = 0; k <= H; k++) {
			int sum = 0;
			for ( ; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (v[i][j] == '@') sum++;
				}
				if (sum == hGroup) {
					break;
				} else if (sum > hGroup) {
					yes = false;
					break;
				}
			}
			if (!yes) break;
			if ( !ok(lastH + 1, i, vIndex) ) {
				if (debug) cout << "3>>>" << endl;
				yes = false;
				break;
			}
			lastH = i;
			i++;
		}
		if (yes) cout << possible  << endl;
		else cout << impossible << endl;
	}
	return 0;
}
