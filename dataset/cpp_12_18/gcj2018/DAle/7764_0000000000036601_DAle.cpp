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

int f[300][300];
vector<int> v;
int n;

int Go(int i, int left) {
	int& res = f[i][left];
	if (res != -1) return res;
	if (left == 0 && v[i] == 0) return 0;
	res = 0;
	int start = (v[i] == 0 ? 1 : 0);
	for (int j = start; j <= left; ++j) {
		int k = v[i] + j;
		int percent = int(k*100.0 / n + 0.5);
		res = max(res, percent + Go(i + 1, left - j));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		memset(f, -1, sizeof(f));
		v.clear();
		int l;
		cin >> n >> l;
		int s = 0;
		for (int i = 0; i < l; ++i) {
			int j;
			cin >> j;
			s += j;
			v.push_back(j);
		}

		for (int i = s; i <= n; ++i) {
			v.push_back(0);
		}
		cout << "Case #" << test + 1 << ": " << Go(0, n-s) << endl;
	}
	return 0;
}
