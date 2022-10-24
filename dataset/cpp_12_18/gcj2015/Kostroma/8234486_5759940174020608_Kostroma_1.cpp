#pragma comment (linker, "/STACK:128000000")
 //#include "testlib.h"
 #include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <iostream>
 #include <memory.h>
 #include <string>
 #include <vector>
 #include <set>
 #include <map>
 #include <cmath>
 #include <bitset>
 //#include <unordered_map>
 //#include <unordered_set>
 #include <ctime>
 #include <stack>
 #include <queue>
 #include <fstream>
 #include <sstream>
 using namespace std;
 //#define FILENAME ""
 #define mp make_pair
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve();
 void precalc();
 clock_t start;
 //int timer = 1;
 
 bool todo = true;
 
 int main() {
 #ifdef room111
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #else
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	//freopen(FILENAME".in", "r", stdin);
 	//freopen(FILENAME ".out", "w", stdout);
 #endif
 	int t = 1;
 	//cout.sync_with_stdio(0);
 	//cin.tie(0);
 	precalc();
 	cout.precision(10);
 	cout << fixed;
 	cin >> t;
 	start = clock();
 	int testNum = 1;
 	while (t--) {
 		cout << "Case #" << testNum++ << ": ";
 		solve();
 		//++timer;
 	}
 
 #ifdef room111
 	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
 	return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 //#define int li
 
 void precalc() {
 
 }
 
 int binpow(int q, int w, int mod) {
 	if (!w)
 		return 1;
 	if (w & 1)
 		return q * binpow(q, w - 1, mod) % mod;
 	return binpow(q * q % mod, w / 2, mod);
 }
 
 int gcd(int q, int w) {
 	while (w) {
 		q %= w;
 		swap(q, w);
 	}
 	return q;
 }
 
 //#define int li
 
 //int mod = 1000000007;
 
 li getHash(const string& s) {
 	li res = 0;
 	for (int i = 0; i < s.length(); ++i) {
 		res = res * 27 + (int(s[i] - 'a') + 1);
 	}
 	return res;
 }
 
 void solve() {
 	int n;
 	cin >> n;
 
 	vector<li> has;
 
 	string input;
 	getline(cin, input);
 	vector<vector<li>> sents(n);
 
 	for (int i = 0; i < n; ++i) {
 		getline(cin, input);
 		stringstream dict(input);
 		string s;
 		while (dict >> s) {
 			li cur = getHash(s);
 			sents[i].push_back(cur);
 			has.push_back(cur);
 		}
 	}
 
 	sort(all(has));
 	has.erase(unique(all(has)), has.end());
 
 	for (int i = 0; i < n; ++i) {
 		for (auto& item : sents[i]) {
 			item = lower_bound(all(has), item) - has.begin();
 		}
 	}
 
 	vector<vector<int>> langs(has.size(), vector<int>(2, 0));
 
 	for (int i = 0; i < 2; ++i) {
 		for (auto item : sents[i]) {
 			langs[item][i] = 1;
 		}
 	}
 
 
 	int res = 1e9;
 
 	vector<vector<int>> was(has.size(), vector<int>(2, 0));
 
 	int tim = 1;
 
 	n -= 2;
 
 	for (int mask = 0; mask < (1 << n); ++mask) {
 
 		++tim;
 
 		for (int i = 0; i < n; ++i) {
 			int lang = 0;
 			if (mask & (1 << i)) {
 				lang = 1;
 			}
 			
 			for (li curString : sents[i + 2]) {
 				was[curString][lang] = tim;
 			}
 		}
 		
 		int curRes = 0;
 		for (int i = 0; i < was.size(); ++i) {
 			if ((was[i][0] == tim || langs[i][0]) && (was[i][1] == tim || langs[i][1])) {
 				++curRes;
 			}
 		}
 		
 		res = min(res, curRes);
 	}
 
 	cout << res << "\n";
 }