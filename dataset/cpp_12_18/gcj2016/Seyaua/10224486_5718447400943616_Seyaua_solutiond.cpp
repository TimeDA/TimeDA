#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 #include <cstdio>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 bool isPossible;
 int used[5];
 
 void go(int i, const vector<int>& pm, const vector<int>& masks) {
 	if (i == pm.size()) {
 		return;
 	}
 	if (!isPossible) {
 		return;
 	}
 	int cmask = masks[pm[i]];
 	bool can = false;
 	for (int bt = 0; bt < masks.size(); ++bt) {
 		if (cmask & (1 << bt)) {
 			if (!used[bt]) {
 				used[bt] = 1;
 				go(i + 1, pm, masks);
 				used[bt] = 0;
 				can = true;
 			}
 		}
 	}
 	if (!can) {
 		isPossible = false;
 	}
 }
 
 bool solve(const vector<int>& masks) {
 	vector<int> pm(masks.size());
 	int n = masks.size();
 	for (int i = 0; i < n; ++i) {
 		pm[i] = i;
 	}
 
 	do {
 		isPossible = true;
 		memset(used, 0, sizeof(used));
 		go(0, pm, masks);
 		if (!isPossible) {
 			return false;
 		}
 	} while (next_permutation(pm.begin(), pm.end()));
 	return true;
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int n;
 	cin >> n;
 	vector<int> vals;
 	int cres = 0;
 	for (int i = 0; i < n; ++i) {
 		string s;
 		cin >> s;
 		int cval = 0;
 		for (int j = 0; j < n; ++j) {
 			if (s[j] == '1') {
 				cval += (1 << j);
 				++cres;
 			}
 		}
 		vals.push_back(cval);
 	}
 
 	int total = n * n;
 
 	int ans = 100;
 
 	for (int gmask = 0; gmask < (1 << total); ++gmask) {
 		vector<int> submask(n, 0);
 		int pres = 0;
 		for (int i = 0; i < n * n; ++i) {
 			int dv = i / n;
 			if (gmask & (1 << i)) {
 				int num = i - dv * n;
 				submask[dv] += (1 << num);
 				++pres;
 			}
 		}
 
 		if (pres >= ans) {
 			continue;
 		}
 
 		bool good = true;
 		for (int i = 0; i < n; ++i) {
 			if ((submask[i] & vals[i]) != vals[i]) {
 				good = false;
 				break;
 			}
 		}
 		if (!good) {
 			continue;
 		}
 
 		if (solve(submask)) {
 			ans = min(ans, pres);
 			//solve(submask);
 		}
 	}
 
 	cout << ans - cres << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int t;
 	scanf("%d", &t);
 
 	for (int i = 1; i <= t; ++i) {
 		solve(i);
 		cerr << i << endl;
 	}
 
 	return 0;
 }