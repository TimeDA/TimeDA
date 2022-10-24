#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 #include <set>
 
 using namespace std;
 
 const int MOD = 1000000007;
 
 int main(){
 	int T; cin >> T;
 	long long dp[2][101];
 	int a[6][6];
 	for(int test=1;test<=T;test++){
 		int R, C; cin >> R >> C;
 		memset(dp, 0, sizeof(dp));
 		dp[0][0] = dp[1][0] = 1;
 		for(int i=1;i<=R;i++){
 			// 2roll
 			dp[1][i] += dp[0][i-1];
 			dp[1][i] %= MOD;
 			// 3roll
 			if(i >= 2){
 				dp[0][i] += dp[1][i-2];
 				dp[0][i] %= MOD;
 			}
 			if(i >= 2 && C%3 == 0){
 				dp[1][i] += 3*dp[0][i-2];
 				dp[1][i] %= MOD;
 			}
 			if(i >= 2 && C%6 == 0){
 				dp[1][i] += 6*dp[0][i-2];
 				dp[1][i] %= MOD;
 			}
 			if(i >= 3 && C%4 == 0){
 				dp[1][i] += 4*dp[0][i-3];
 				dp[1][i] %= MOD;
 			}
 		}
 		printf("Case #%d: %d\n", test, (dp[0][R]+dp[1][R])%MOD);
 	}
 }
