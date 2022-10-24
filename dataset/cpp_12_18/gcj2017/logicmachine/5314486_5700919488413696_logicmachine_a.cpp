#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 static int dp[3][101][101][101] = { { { { 0 } } } };
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	const int m = 100;
 	for(int p = 2; p <= 4; ++p){
 		const int r = p - 2;
 		for(int i = 0; i < m; ++i){
 		for(int j = 0; j < m; ++j){
 		for(int k = 0; k < m; ++k){
 			const int s = (i + j * 2 + k * 3) % p;
 			dp[r][i + 1][j][k] = max(
 				dp[r][i + 1][j][k],
 				dp[r][i][j][k] + (s % p == 0 ? 1 : 0));
 			dp[r][i][j + 1][k] = max(
 				dp[r][i][j + 1][k],
 				dp[r][i][j][k] + (s % p == 0 ? 1 : 0));
 			dp[r][i][j][k + 1] = max(
 				dp[r][i][j][k + 1],
 				dp[r][i][j][k] + (s % p == 0 ? 1 : 0));
 		} } }
 	}
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, p;
 		cin >> n >> p;
 		vector<int> g(n);
 		for(int i = 0; i < n; ++i){ cin >> g[i]; }
 		vector<int> h(4);
 		for(int i = 0; i < n; ++i){ ++h[g[i] % p]; }
 		const int answer = h[0] + dp[p - 2][h[1]][h[2]][h[3]];
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
