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
 
 //#define int li
 
 int testNum = 1;
 
 
 void solve() {
 	cout << "Case #" << testNum++ << ": ";
 
 	vector<int> b(100, 0);
 
 	for (int w = 0; w < 2; ++w) {
 		int a;
 		cin >> a;
 		for (int i = 0; i < 4; ++i)
 			for (int j = 0; j < 4; ++j) {
 				int cur;
 				cin >> cur;
 				if (i + 1 == a)
 					++b[cur];
 			}
 	}
 
 	int id = -1;
 	for (int i = 1; i < 100; ++i) {
 		if (b[i] == 2) {
 			if (id != -1) {
 				cout << "Bad magician!\n";
 				return;
 			}
 			id = i;
 		}
 	}
 
 	if (id == -1) {
 		cout << "Volunteer cheated!\n";
 		return;
 	}
 
 	cout << id << "\n";
 
 }
