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

		vector<int> v(n), a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
			a[i]--; b[i]--;
		}
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		vector<int> order(n);
		for (int i = 0; i < n; ++i) order.push_back(i);
		int res = v[0];
		do {
			auto v2 = v;
			for (int i = 0; i < n; ++i) {
				int d = min(a[order[i]], b[order[i]]);
				v2[order[i]] += d;
				v2[a[order[i]]] -= d;
				v2[b[order[i]]] -= d;
				res = max(res, v2[0]);
			}
		} while (next_permutation(begin(order), end(order)));
		cout << "Case #" << test + 1 << ": " << res << endl;
	}
	return 0;
}
