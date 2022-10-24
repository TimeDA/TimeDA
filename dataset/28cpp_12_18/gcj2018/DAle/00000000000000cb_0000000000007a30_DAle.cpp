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
		while (n % 9 != 0) ++n;
		for (int i = 0; i < n / 9; ++i) {
			int sx = 2 + 3 * i;
			int cnt = 0;
			int a[3][3] = {};
			while (cnt < 9) {
				cout << sx << ' ' << 2 << endl;
				int x, y;
				cin >> x >> y;
				if (x == 0 && y == 0) break;
				int cx = x - sx + 1;
				int cy = y - 1;
				if (a[cx][cy] == 0) {
					a[cx][cy] = 1;
					++cnt;
				}
			}
		}
	}
	return 0;
}
