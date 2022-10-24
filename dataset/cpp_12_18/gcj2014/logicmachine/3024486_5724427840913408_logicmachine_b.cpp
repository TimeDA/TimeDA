#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <cstring>
 
 using namespace std;
 const int INF = 1000000000;
 
 int dp[1002][101][101];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n, p, q;
 		cin >> p >> q >> n;
 		vector<int> h(n), g(n);
 		for(int i = 0; i < n; ++i){ cin >> h[i] >> g[i]; }
 		vector<int> x(n), y(n);
 		for(int i = 0; i < n; ++i){
 			x[i] = (h[i] - 1) / q;
 			y[i] = (h[i] - (x[i] * q) + p - 1) / p;
 		}
 		vector<int> xscan(n + 1);
 		for(int i = 0; i < n; ++i){ xscan[i + 1] = xscan[i] + x[i]; }
 		memset(dp, -1, sizeof(dp));
 		dp[0][0][0] = 0;
 		for(int i = 0; i < 1001; ++i){
 			for(int j = 0; j < n; ++j){
 				for(int k = 0; k < n; ++k){
 					if(dp[i][j][k] < 0){ continue; }
 					dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k]);
 					const int t = xscan[j + 1] + k;
 					const int s = i + y[j];
 					if(s <= t + 1){
 						dp[s][j + 1][k] = max(dp[s][j + 1][k], dp[i][j][k] + g[j]);
 					}
 				}
 			}
 		}
 		int answer = 0;
 		for(int i = 0; i <= 1001; ++i){
 			for(int j = 0; j <= n; ++j){
 				for(int k = 0; k <= n; ++k){
 					answer = max(answer, dp[i][j][k]);
 				}
 			}
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
