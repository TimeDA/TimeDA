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
 
 bool doing = true;
 
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
 
 int mult(int a, int b) {
 	if (a == b)
 		return -1;
 	if (a < 0) {
 		return -mult(-a, b);
 	}
 	if (b < 0) {
 		return -mult(a, -b);
 	}
 	if (a == 1) {
 		return b;
 	}
 	if (b == 1) {
 		return a;
 	}
 	if (b == a + 1 || a == b + 2) {
 		return (b == 4) ? 2 : (b + 1);
 	}
 	return -mult(b, a);
 }
 
 void solve() {
 	int l, x;
 	cin >> l >> x;
 	string s;
 	cin >> s;
 	string q;
 	for (int i = 0; i < x; ++i) {
 		q += s;
 	}
 	s.swap(q);
 	vector<int> a(s.length());
 
 	int n = s.length();
 	vector<int> was(5);
 	int cur = 1;
 	for (int i = 0; i < n; ++i) {
 		if (cur == 2) {
 			was[cur] = 1;
 		}
 		else {
 			if (was[2] && cur == 4) {
 				was[cur] = 1;
 			}
 		}
 		cur = mult(cur, s[i] - 'i' + 2);
 	}
 
 	if (was[4] && cur == -1) {
 		cout << "YES\n";
 	}
 	else {
 		cout << "NO\n";
 	}
 
 }
 
 
