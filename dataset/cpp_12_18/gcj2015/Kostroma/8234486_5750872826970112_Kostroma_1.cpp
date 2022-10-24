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
 
 ld eps = 1e-9;
 
 void solve() {
 	int n;
 	cin >> n;
 	ld V, x;
 	cin >> V >> x;
 
 	bool hasLess = false, hasMore = false;
 
 	vector<pair<ld, ld>> tanks(n); //c, r
 	for (int i = 0; i < n; ++i) {
 		cin >> tanks[i].second >> tanks[i].first;
 		if (tanks[i].first > x - eps) {
 			hasMore = true;
 		}
 		if (tanks[i].first < x + eps) {
 			hasLess = true;
 		}
 	}
 
 	if (!hasLess || !hasMore) {
 		cout << "IMPOSSIBLE\n";
 		return;
 	}
 
 	sort(all(tanks));
 
 	ld L = 0, R = 1e12;
 	for (int w = 0; w < 300; ++w) {
 		ld T = (L + R) / 2;
 
 		ld minSum = 0.0;
 		ld sumAlpha = 0.0;
 
 		for (int i = 0; i < n; ++i) {
 			ld add = T * tanks[i].second / V;
 			add = min(add, 1.0 - sumAlpha);
 			minSum += add * tanks[i].first;
 			sumAlpha += add;
 		}
 
 		sumAlpha = 0.0;
 		ld maxSum = 0.0;
 		for (int i = n - 1; i >= 0; --i) {
 			ld add = T * tanks[i].second / V;
 			add = min(add, 1.0 - sumAlpha);
 			maxSum += add * tanks[i].first;
 			sumAlpha += add;
 		}
 
 		if (maxSum < x || x < minSum) {
 			L = T;
 		}
 		else {
 			R = T;
 		}
 	}
 
 	cout << R << "\n";
 
 }