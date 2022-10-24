#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdio>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 	int n, p;
 	cin >> n >> p;
 	vector<int> a(n);
 	vector<int> c(4);
 	for (int i = 0; i < n; ++i) {
 		cin >> a[i];
 		++c[a[i] % p];
 	}
 
 	int res = c[0];
 	if (p == 2) {
 		res += (c[1] + 1) / 2;
 		cout << res << endl;
 		return;
 	}
 
 	if (p == 3) {
 		int val = min(c[1], c[2]);
 		res += val;
 		c[1] -= val;
 		c[2] -= val;
 		res += (c[1] + c[2] + 2) / 3;
 		cout << res << endl;
 		return;
 	}
 
 	if (p == 4) {
 		res += c[2] / 2;
 		c[2] %= 2;
 		int val = min(c[1], c[3]);
 		res += val;
 		c[1] -= val;
 		c[3] -= val;
 
 		if (c[2]) {
 			if (c[1] >= 2) {
 				++res;
 				--c[2];
 				c[1] -= 2;
 			} else if (c[3] >= 2) {
 				++res;
 				--c[2];
 				c[3] -= 2;
 			}
 		}
 		res += (c[1] + c[3] + 3) / 4;
 		cout << res << endl;
 		return;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	cin >> tests;
 
 	for (int i = 1; i <= tests; ++i) {
 		cerr << "Starting tcase: " << i << endl;
 		solve(i);
 	}
 
 	return 0;
 }