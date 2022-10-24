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
 #include <iomanip>
 
 using namespace std;
 
 int ones(int i) { int j = 0; while (i) { i &= i - 1; ++j; } return j; }
 
 int main() {
 	ifstream ifs("b.in");
 	ofstream ofs("b.out");
 	int t;
 	ifs >> t;
 
 	for (int test = 0; test < t; ++test) {
 		int k, n;
 		ifs >> n >> k;
 		vector<double> v(n);
 		for (int i = 0; i < n; ++i) {
 			ifs >> v[i];
 		}
 
 		double a[20];
 		double best = 0;
 		for (int mask = 0; mask < (1 << n); ++mask) {
 			if (ones(mask) == k) {
 				int cnt = 0;
 				for (int i = 0; i < n; ++i) {
 					if (mask & (1 << i)) {
 						a[cnt++] = v[i];
 					}
 				}
 				double allp = 0;
 				for (int imask = 0; imask < (1 << k); ++imask) {
 					if (ones(imask) == k / 2) {
 						double p = 1;
 						for (int i = 0; i < k; ++i) {
 							if (imask & (1 << i)) {
 								p *= a[i];
 							} else {
 								p *= 1 - a[i];
 							}
 						}
 						allp += p;
 					}
 				}
 				best = max(best, allp);
 			}
 		}
 		ofs << "Case #" << test + 1 << ": " << fixed << setprecision(16) << best << endl;
 	}
 	return 0;
 }