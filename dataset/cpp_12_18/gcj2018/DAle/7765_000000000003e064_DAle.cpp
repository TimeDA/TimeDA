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
		string res;
		int n, l;
		cin >> n >> l;

		unordered_set<string> words;
		vector<vector<char>> v(l);
		vector<set<char>> swords(l);

		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			words.insert(s);
			for (int j = 0; j < l; ++j) {
				swords[j].insert(s[j]);
			}
		}

		for (int i = 0; i < l; ++i) {
			v[i].assign(swords[i].begin(), swords[i].end());
		}
		
		const int MAX_ITER = 200000;
		int it = 0;
		bool found = false;
		while (!found && (it++ < MAX_ITER)) {
			string tmp;
			for (int i = 0; i < l; ++i) {
				int r = rand() % v[i].size();
				tmp += v[i][r];
			}
			if (words.count(tmp) == 0) {
				found = true;
				res = tmp;
			}
		}
		cout << "Case #" << test + 1 << ": " << (found ? res : "-") << endl;
	}
	return 0;
}
