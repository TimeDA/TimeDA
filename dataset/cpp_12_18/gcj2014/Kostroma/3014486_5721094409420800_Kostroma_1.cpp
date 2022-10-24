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
 
 int n;
 int a[100500];
 
 int pref[100500], suff[100500];
 
 void solve() {
 	cin >> n;
 	int mxPos = 0;
 	for (int i = 0; i < n; ++i) {
 		cin >> a[i];
 		if (a[i] > a[mxPos])
 			mxPos = i;
 	}
 
 	/*memset(pref, 0, sizeof pref);
 	memset(suff, 0, sizeof suff);
 
 	pref[0] = 0;
 	for (int i = 1; i < n; ++i) {
 		pref[i] = pref[i - 1];
 		for (int j = 0; j < i; ++j)
 			if (a[j] > a[i])
 				++pref[i];
 	}
 
 	suff[n - 1] = 0;
 	for (int i = n - 2; i >= 0; --i) {
 		suff[i] = suff[i + 1];
 		for (int j = i + 1; j < n; ++j)
 			if (a[i] < a[j])
 				++suff[i];
 	}
 
 	int ans = 1e9;
 
 	for (int pos = 0; pos < n; ++pos) {
 		ans = min(ans, pref[pos] + suff[pos + 1]);
 	}
 
 	cout << ans << " ";*/
 
 	int res = 1e9;
 
 	int best[10];
 	int p[10];
 	for (int i = 0; i < n; ++i)
 		p[i] = i;
 
 	do {
 
 		int mx = 0;
 		for (int j = 0; j < n; ++j)
 			if (a[p[j]] > a[p[mx]])
 				mx = j;
 
 		bool flag = true;
 		for (int j = 0; j < mx; ++j)
 			if (a[p[j]] > a[p[j + 1]]) {
 				flag = false;
 				break;
 			}
 
 		for (int j = mx; j + 1 < n; ++j)
 			if (a[p[j]] < a[p[j + 1]]) {
 				flag = false;
 				break;
 			}
 
 		if (!flag)
 			continue;
 
 		int now = 0;
 		for (int i = 0; i < n; ++i)
 			for (int j = i + 1; j < n; ++j)
 				if (p[i] > p[j])
 					++now;
 
 		if (res > now) {
 			res = now;
 			for (int i= 0; i < n; ++i)
 				best[i] = p[i];
 		}
 		
 
 	}
 	while (next_permutation(p, p + n));
 
 	cout << res << "\n";
 
 	/*if (res != ans) {
 		cout << n << "\n";
 		for (int i = 0; i < n; ++i)
 			cout << a[i] << ' ';
 		cout << endl;
 		for (int i=0; i <n; ++i)
 			cout << best[i] + 1 << ' ';
 		cout<<"\n";
 		for (int i=0; i <n; ++i)
 			cout << a[best[i]] << ' ';
 		exit(0);
 	}*/
 
 }
