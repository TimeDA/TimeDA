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

int damage(const string& s) {
	int curStrength = 1;
	int totalDamage = 0;
	for (char ch : s) {
		if (ch == 'C') curStrength *= 2;
		if (ch == 'S') totalDamage += curStrength;
	}
	return totalDamage;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		int res = 0;
		int D;
		string s;
		cin >> D >> s;
		while (damage(s) > D) {
			int pos = s.rfind("CS");
			if (pos < 0) break;
			swap(s[pos], s[pos+1]);
			++res;
		}
		cout << "Case #" << test + 1 << ": " << (damage(s) <= D ? to_string(res) : "IMPOSSIBLE") << endl;
	}
	return 0;
}
