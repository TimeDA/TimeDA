#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 const int INF = 1000000000;
 
 int dp[1001][1001];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n;
 		cin >> n;
 		vector<int> a(n);
 		for(int i = 0; i < n; ++i){ cin >> a[i]; }
 		vector<int> b(a);
 		sort(b.begin(), b.end());
 		for(int i = 0; i < n; ++i){
 			a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
 		}
 		vector<int> c(n);
 		for(int i = 0; i < n; ++i){
 			for(int j = 0; j < i; ++j){
 				if(a[j] > a[i]){ ++c[a[i]]; }
 			}
 		}
 		for(int i = 0; i <= n; ++i){
 			for(int j = 0; j <= n; ++j){ dp[i][j] = INF; }
 		}
 		dp[0][0] = 0;
 		for(int i = 0; i < n; ++i){
 			for(int j = 0; j <= i; ++j){
 				const int m = n - i;
 				dp[i + 1][j + 1] = min(
 					dp[i + 1][j + 1], dp[i][j] + c[i]);
 				dp[i + 1][j] = min(
 					dp[i + 1][j], dp[i][j] + (m - c[i] - 1));
 			}
 		}
 		int answer = INF;
 		for(int i = 0; i <= n; ++i){
 			answer = min(answer, dp[n][i]);
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
