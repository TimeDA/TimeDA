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

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << "Case #" << test + 1 << ": ";

		vector<int> t(n);
		bool ok = v[0] > 0 && v.back() > 0;
		int maxd = 0;
		if (ok) {
			int s = v[0];
			int curi = 0;
			for (int i = 0; i < n; ++i) {
				while (i == s) {
					++curi;
					s += v[curi];
				}
				t[i] = curi;
				maxd = max(maxd, abs(i - t[i]));
			}

			vector<string> res(maxd + 1, string(n, '.'));
			for (int i = 0; i < n; ++i) {
				if (t[i] < i) {
					for (int j = 0; j < i - t[i]; ++j) {
						res[j][i - j] = '/';
					}
				}
				if (t[i] > i) {
					for (int j = 0; j < t[i] - i; ++j) {
						res[j][i + j] = '\\';
					}
				}
			}
			cout << maxd + 1 << endl;
			for (auto s : res) {
				cout << s << endl;
			}
		}
		if (!ok) {
			cout << "IMPOSSIBLE"				<< endl;
		}
	}
	return 0;
}
