#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 
 using namespace std;
 
 long long mx = -1;
 
 void gen(long long current, int last, long long lim) {
 	if (current <= lim) {
 		mx = max(current, mx);
 	}
 	if (current > lim / 10 || current > lim) {
 		return;
 	}
 	for (int i = last; i <= 9; ++i) {
 		gen(current * 10LL + i, i, lim);
 	}
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	mx = -1;
 	long long n;
 	cin >> n;
 	gen(0, 1, n);
 	cout << mx << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tcase;
 	cin >> tcase;
 
 	for (int i = 0; i < tcase; ++i) {
 		solve(i + 1);
 		cerr << i << endl;
 	}
 
 	return 0;
 }
