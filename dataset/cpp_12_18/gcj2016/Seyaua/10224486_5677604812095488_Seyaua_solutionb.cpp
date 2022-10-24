#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 #include <cstdio>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 210;
 
 double p[maxN];
 
 double solve(const vector<double>& p) {
 	vector<vector<double> > dp(p.size() + 1, vector<double>(p.size() + 1, 0.0));
 
 	dp[0][0] = 1;
 
 	int n = p.size();
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < n; ++j) {
 			if (dp[i][j] < 1e-15) {
 				continue;
 			}
 			double cp = p[i];
 			dp[i + 1][j] += dp[i][j] * (1. - cp);
 			dp[i + 1][j + 1] += dp[i][j] * cp;
 		}
 	}
 	return dp[n][n / 2];
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int n, k;
 	cin >> n >> k;
 	for (int i = 0; i < n; ++i) {
 		cin >> p[i];
 	}
 	sort(p, p + n);
 
 	double ans = 0;
 
 	for (int i = 0; i <= k; ++i) {
 		vector<double> res;
 		for (int j = 0; j < i; ++j) {
 			res.push_back(p[j]);
 		}
 		int need = k - i;
 		for (int j = n - 1; j >= n - need; --j) {
 			res.push_back(p[j]);
 		}
 		ans = max(ans, solve(res));
 	}
 	printf("%.10lf\n", ans);
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int t;
 	scanf("%d", &t);
 
 	for (int i = 1; i <= t; ++i) {
 		cerr << i << endl;
 		solve(i);
 	}
 
 	return 0;
 }