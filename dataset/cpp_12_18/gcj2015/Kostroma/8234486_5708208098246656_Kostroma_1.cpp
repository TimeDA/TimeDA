﻿#pragma comment (linker, "/STACK:128000000")
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
 	cout.sync_with_stdio(0);
 	cin.tie(0);
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
 
 int getNum(char c) {
 	if (c == '<')
 		return 0;
 	if (c == '^')
 		return 1;
 	if (c == '>')
 		return 2;
 	if (c == 'v')
 		return 3;
 	assert(false);
 }
 
 void solve() {
 	int n, m;
 	cin >> n >> m;
 
 	vector<string> s(n);
 	for (int i = 0; i < n; ++i) {
 		cin >> s[i];
 	}
 
 	vector<vector<vector<int>>> banned(n, vector<vector<int>>(m));
 
 	for (int i = 0; i < n; ++i) {
 		int lef = m, rig = -1;
 		for (int j = 0; j < m; ++j) {
 			if (s[i][j] != '.') {
 				lef = min(lef, j);
 				rig = max(rig, j);
 			}
 		}
 		if (rig == -1) {
 			continue;
 		}
 		banned[i][lef].push_back(0);
 		banned[i][rig].push_back(2);
 	}
 
 	for (int i = 0; i < m; ++i) {
 		int lef = n, rig = -1;
 		for (int j = 0; j < n; ++j) {
 			if (s[j][i] != '.') {
 				lef = min(lef, j);
 				rig = max(rig, j);
 			}
 		}
 		if (rig == -1) {
 			continue;
 		}
 		banned[lef][i].push_back(1);
 		banned[rig][i].push_back(3);
 	}
 
 	int res = 0;
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < m; ++j) {
 			sort(all(banned[i][j]));
 			banned[i][j].erase(unique(all(banned[i][j])), banned[i][j].end());
 			if (banned[i][j].size() == 4) {
 				cout << "IMPOSSIBLE\n";
 				return;
 			}
 			for (int to : banned[i][j]) {
 				if (to == getNum(s[i][j])) {
 					++res;
 					break;
 				}
 			}
 		}
 	}
 
 	cout << res << "\n";
 
 }