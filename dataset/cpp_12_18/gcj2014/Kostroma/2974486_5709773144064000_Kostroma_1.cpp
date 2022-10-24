#pragma comment (linker, "/STACK:128000000")
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
 	//cout.sync_with_stdio(0);
 	//precalc();
 	cout.precision(10);
 	cout << fixed;
 	cin >> t;
 	start = clock();
     while (t--) {
         solve();
 		//++timer;
 	}
 
 #ifdef room111
 	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
     return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 int testNum = 1;
 
 //#define int li
 
 
 
 void solve() {
 	cout << "Case #" << testNum++ << ": ";
 
 	double c, f, x;
 	cin >> c >> f >> x;
 
 	double curAdd = 2, curTime = 0;
 	double ans = 1e9;
 	for (int i = 0; i < 2e6; ++i) {
 		ans = min(ans, curTime + x / curAdd);
 		curTime += c / curAdd;
 		curAdd += f;
 	}
 
 	cout << ans << "\n";
 
 }
