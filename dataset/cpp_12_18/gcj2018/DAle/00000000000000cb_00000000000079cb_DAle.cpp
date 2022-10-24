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
		vector<int> odd, even;
		for (int i = 0; i < n; ++i) {
			int j;
			cin >> j;
			if (i % 2 == 0) {
				even.push_back(j);
			} else {
				odd.push_back(j);
			}
		}
		sort(begin(odd), end(odd));
		sort(begin(even), end(even));

		vector<int> all;
		int eveni = 0, oddi = 0;
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				all.push_back(even[eveni++]);
			} else {
				all.push_back(odd[oddi++]);
			}
		}

		bool ok = true;
		int index = -1;
		for (int i = 0; i+1 < n; ++i) {
			if (all[i] > all[i + 1]) {
				ok = false;
				index = i;
				break;
			}
		}
		cout << "Case #" << test + 1 << ": " << (ok ? "OK" : to_string(index)) << endl;
	}
	return 0;
}
