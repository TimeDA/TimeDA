#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 static double dp[201][201];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, k;
 		cin >> n >> k;
 		vector<double> p(n);
 		for(int i = 0; i < n; ++i){ cin >> p[i]; }
 		sort(p.begin(), p.end());
 		double answer = 0.0;
 		for(int i = 0; i <= k; ++i){
 			vector<double> a;
 			for(int j = 0; j < i; ++j){ a.push_back(p[j]); }
 			for(int j = 0; j < (k - i); ++j){ a.push_back(p[n - 1 - j]); }
 			sort(a.begin(), a.end());
 			for(int y = 0; y <= k; ++y){
 				for(int x = 0; x <= y; ++x){ dp[y][x] = 0.0; }
 			}
 			dp[0][0] = 1.0;
 			for(int y = 0; y < k; ++y){
 				for(int x = 0; x <= y; ++x){
 					dp[y + 1][x] += dp[y][x] * (1.0 - a[y]);
 					dp[y + 1][x + 1] += dp[y][x] * a[y];
 				}
 			}
 			answer = max(answer, dp[k][k / 2]);
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
