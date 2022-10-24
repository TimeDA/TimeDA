#include <iostream>
 #include <iomanip>
 #include <string>
 #include <cstring>
 
 using namespace std;
 typedef long long ll;
 
 long double dp[1 << 20];
 long double count[1 << 20];
 
 int main(){
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		string s;
 		cin >> s;
 		const int N = s.size();
 		memset(dp, 0, sizeof(dp));
 		memset(count, 0, sizeof(count));
 		int init = 0;
 		for(int i = 0; i < N; ++i){
 			if(s[i] == 'X'){ init |= (1 << i); }
 		}
 		dp[init] = 0.0;
 		count[init] = 1.0;
 		for(int i = 0; i < (1 << N) - 1; ++i){
 			if(count[i] <= 0){ continue; }
 			for(int j = 0; j < N; ++j){
 				ll bits = i | (static_cast<ll>(i) << N);
 				bits >>= j;
 				int w = __builtin_ctzll(~bits);
 				int k = i | (1 << ((w + j) % N));
 				dp[k] += dp[i] + count[i] * (N - w);
 				count[k] += count[i];
 			}
 		}
 		double answer = dp[(1 << N) - 1] / count[(1 << N) - 1];
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
