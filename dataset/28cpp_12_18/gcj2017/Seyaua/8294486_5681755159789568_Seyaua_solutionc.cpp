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
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 110;
 double dp[maxN][maxN];
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int n, q;
 	cin >> n >> q;
 
 	vector<long long> e(n);
 	vector<double> s(n);
 	for (int i = 0; i < n; ++i) {
 		cin >> e[i] >> s[i];
 	}
 
 	vector<vector<long long>> d(n, vector<long long>(n));
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < n; ++j) {
 			cin >> d[i][j];
 			if (d[i][j] == -1) {
 				d[i][j] = 1000000000000000000LL;
 			}
 		}
 	}
 
 	vector<int> ss(q);
 	vector<int> sf(q);
 	for (int i = 0; i < q; ++i) {
 		cin >> ss[i] >> sf[i];
 	}
 
 	for (int k = 0; k < n; ++k) {
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < n; ++j) {
 				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
 			}
 		}
 	}
 	
 	for (int i = 0; i <= n; ++i) {
 		for (int j = 0; j <= n; ++j) {
 			dp[i][j] = 1e18;
 		}
 	}
 
 	dp[1][0] = d[0][1] / s[0];
 	for (int i = 1; i + 1 < n; ++i) {
 		for (int j = 0; j < n; ++j) {
 			auto curd = d[j][i + 1];
 			if (curd <= e[j]) {
 				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d[i][i + 1] / s[j]);
 			}
 			if (d[i][i + 1] <= e[i]) {
 				dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + d[i][i + 1] / s[i]);
 			}
 		}
 	}
 
 	double res = 1e18;
 	for (int i = 0; i < n; ++i) {
 		res = min(res, dp[n - 1][i]);
 	}
 	printf("%.10lf\n", res);
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