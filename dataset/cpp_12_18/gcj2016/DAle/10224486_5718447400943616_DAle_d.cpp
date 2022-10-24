#include <iostream>
 #include <fstream>
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <cstring>
 #include <cmath>
 #include <sstream>
 
 using namespace std;
 
 int ones(int i) { int j = 0; while (i) { i &= i - 1; ++j; } return j;}
 
 bool good(int step, const vector<string>& v, vector<int>& wasw, vector<int>& wasm, int n) {
 	if (step == n) return true;
 	for (int w = 0; w < n; ++w)
 		if (wasw[w] == 0) {
 			bool ok = false;
 			wasw[w] = 1;
 			for (int m = 0; m < n; ++m) {
 				if (wasm[m] == 0 && v[w][m] == '1') {
 					ok = true;
 					wasm[m] = 1;
 					if (!good(step + 1, v, wasw, wasm, n)) { return false;  }
 					wasm[m] = 0;
 				}
 			}
 			if (!ok) return false;
 			wasw[w] = 0;
 		}
 	return true;
 }
 
 int main() {
 	ifstream ifs("d.in");
 	ofstream ofs("d.out");
 	int t;
 	ifs >> t;
 
 	for (int test = 0; test < t; ++test) {
 		int n; ifs >> n;
 		vector<string> v(n);
 		for (int i = 0; i < n; ++i) {
 			ifs >> v[i];
 		}
 
 		int cnt = n*n;
 		int best = 1000;
 		for (int mask = 0; mask < (1 << cnt); ++mask) {
 			if (ones(mask) < best) {
 				vector<string> newV = v;
 				for (int i = 0; i < cnt; ++i) {
 					if (mask & (1 << i)) {
 						int x = i / n;
 						int y = i % n;
 						if (v[x][y] == '1') continue;
 						newV[x][y] = '1';
 					}
 				}
 				vector<int> wasm(n, 0);
 				vector<int> wasw(n, 0);
 				if (good(0, newV, wasw, wasm, n)) {
 					best = ones(mask);
 				}
 			}
 		}
 
 		ofs << "Case #" << test + 1 << ": " << best << endl;
 	}
 	return 0;
 }