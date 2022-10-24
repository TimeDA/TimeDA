#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <cstring>
 
 using namespace std;
 
 int dp[102][102];
 int nMax[31] = { 0 }, sMax[31] = { 0 };
 
 int main(){
 	int T;
 	cin >> T;
 	for(int i = 0; i <= 10; ++i){
 		for(int j = i; j <= 10; ++j){
 			for(int k = j; k <= 10; ++k){
 				int diff = k - i, sum = i + j + k;
 				if(diff <= 1){
 					nMax[sum] = max(nMax[sum], k);
 				}else if(diff == 2){
 					sMax[sum] = max(sMax[sum], k);
 				}
 			}
 		}
 	}
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int N, S, p;
 		cin >> N >> S >> p;
 		vector<int> t(N);
 		for(int i = 0; i < N; ++i){ cin >> t[i]; }
 		memset(dp, 0, sizeof(dp));
 		for(int i = 0; i < N; ++i){
 			for(int j = 0; j <= S; ++j){
 				dp[i + 1][j] = max(
 					dp[i + 1][j], dp[i][j] + (nMax[t[i]] >= p ? 1 : 0));
 				if(t[i] <= 28){
 					dp[i + 1][j + 1] = max(
 						dp[i + 1][j], dp[i][j] + (sMax[t[i]] >= p ? 1 : 0));
 				}
 			}
 		}
 		cout << "Case #" << caseNum << ": " << dp[N][S] << endl;
 	}
 	return 0;
 }
 
