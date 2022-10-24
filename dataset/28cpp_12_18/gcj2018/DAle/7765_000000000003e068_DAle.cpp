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
		int res = 0;
		int n;
		cin >> n;
		vector<int> v(n);
		vector<bool> sold(n, false);
		for (int i = 0; i < n; ++i) {
			int cnt;
			cin >> cnt;
			vector<int> f(cnt);
			for (int j = 0; j < cnt; ++j) {
				cin >> f[j];
			}

			int besti = -1, best = numeric_limits<int>::max();
			for (int fl : f) {
				if (v[fl] < best && !sold[fl]) {
					best = v[fl];
					besti = fl;
				}
				v[fl]++;
			}

			if (besti == -1) {
				cout << -1 << endl; 
			}
			else {
				sold[besti] = true;
				cout << besti << endl;
			}
		}
	}
	return 0;
}
