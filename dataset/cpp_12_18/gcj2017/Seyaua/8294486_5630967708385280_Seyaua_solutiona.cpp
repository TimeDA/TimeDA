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
 
 	double d;
 	int n;
 	cin >> d >> n;
 
 	vector<double> ps(n);
 	vector<double> s(n);
 
 	double res = 0;
 
 	for (int i = 0; i < n; ++i) {
 		cin >> ps[i] >> s[i];
 		res = max(res, (d - ps[i]) / s[i]);
 	}
 
 	printf("%.10lf\n", d / res);
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