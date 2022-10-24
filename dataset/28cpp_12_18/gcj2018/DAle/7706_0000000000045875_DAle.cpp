#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <tuple>
#include <numeric>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <regex>
#include <stack>
#include <limits>

using namespace std;

int cnt(const vector<vector<int>>& v, int x, int y, int n) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (i != x && v[i][y] == v[x][y]) { ++res; break; }
	}
	for (int j = 0; j < n; ++j) {
		if (j != y && v[x][j] == v[x][y]) { ++res; break; }
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		int res = 0;
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> v[i][j];

		int d = n+1;
		vector<vector<int>> was(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (was[i][j] == 0 && cnt(v, i, j, n) == 2) {
					was[i][j] = 1;
					v[i][j] = d++;
					++res;
				}
			}

		for (int i = 0; i < n; ++i) {
			set<int> s;
			for (int j = 0; j < n; ++j) {
				s.insert(v[i][j]);
			}
			res += n - s.size();
		}
		for (int j = 0; j < n; ++j) {
			set<int> s;
			for (int i = 0; i < n; ++i) {
				s.insert(v[i][j]);
			}
			res += n - s.size();
		}
		cout << "Case #" << test + 1 << ": " << res << endl;
	}
	return 0;
}
