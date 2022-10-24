#define _CRT_SECURE_NO_WARNINGS
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
 //#include <unordered_map>
 //#include <unordered_set>
 #include <ctime>
 #include <stack>
 #include <queue>
 using namespace std;
 //#define FILENAME ""
 #define mp make_pair
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve();
 //void precalc();
 clock_t start;
 //int timer = 1;
 
 
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
 	//precalc();
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
 
 int m, n;
 string s[100];
 
 int doing (vector<int>& now) {
 	set<int> strings;
 	for (int i : now) {
 		int h = 0;
 		for (int j = 0; j < s[i].length(); ++j) {
 			h = h * 2011 + s[i][j];
 			strings.insert(h);
 		}
 	}
 	return strings.size() + 1;
 }
 
 void solve() {
 	cin >> m >> n;
 	for (int i = 0; i < m; ++i)
 		cin >> s[i];
 
 	int big = 1;
 	for (int i = 0; i < m; ++i)
 		big *= n;
 
 	int ans = 0, ways = 0;
 
 	for (int mask = 0; mask < big; ++mask) {
 		vector<int> number[10];
 		int cur = mask;
 		for (int j = 0; j < m; ++j) {
 			number[cur % n].push_back(j);
 			cur /= n;
 		}
 		bool flag = true;
 		for (int i = 0; i < n; ++i)
 			if (number[i].empty()) {
 				flag = false;
 				break;
 			}
 		if (flag) {
 			int curRes = 0;
 			for (int i = 0; i < n; ++i)
 				curRes += doing(number[i]);
 			if (curRes > ans) {
 				ans = curRes;
 				ways = 1;
 			}
 			else
 				if (curRes == ans)
 					++ways;
 		}
 	}
 	
 	cout << ans << ' ' << ways << "\n";
 
 }
