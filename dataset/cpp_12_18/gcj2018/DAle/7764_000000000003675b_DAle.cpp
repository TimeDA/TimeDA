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
		vector<int> a(n), b(n);
 		for (int i = 0; i < n; ++i) {
			int d, ai, bi;
			cin >> d >> ai >> bi;
			a[i] = d + ai;
			b[i] = d - bi;
		}

		int maxn = 1;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			bool second = false;
			int svalue = 0;
			int j = i+1;
			for (; j < n; ++j) {
				if (a[j] == a[i] || !second || second && svalue == b[j]) {
					if (a[j] != a[i] && !second) {
						second = true;
						svalue = b[j];
					}
				}
				else break;
			}

			int len1 = j - i;

			second = false;
			svalue = 0;
			j = i + 1;
			for (; j < n; ++j) {
				if (b[j] == b[i] || !second || second && svalue == a[j]) {
					if (b[j] != b[i] && !second) {
						second = true;
						svalue = a[j];
					}
					
				}
				else break;
			}

			int len2 = j - i;
			int len = max(len1, len2);
			if (len > maxn) {
				maxn = len; cnt = 1;
			}
			else if (len == maxn) ++cnt;
		}
		cout << "Case #" << test + 1 << ": " << maxn << ' ' << cnt << endl;
	}
	return 0;
}
