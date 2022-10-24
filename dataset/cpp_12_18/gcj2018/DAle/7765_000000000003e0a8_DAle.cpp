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
		vector<long long> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		vector<long long> f(n + 5, numeric_limits<long long>::max() / 2);
		f[0] = 0;
		int maxn = 0;
		for (long long w : v) {
			long long w6 = w * 6;
			int index = lower_bound(begin(f), end(f), w6+1) - begin(f);
			for (int k = index; k > 0; --k) {
				if (f[k] > f[k - 1] + w) {
					maxn = max(maxn, k);
					f[k] = f[k - 1] + w;
				}
			}
		}
		cout << "Case #" << test + 1 << ": " << maxn << endl;
	}
	return 0;
}
