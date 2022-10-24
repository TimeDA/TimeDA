#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 typedef long long ll;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		ll B, N;
 		cin >> B >> N;
 		vector<ll> X(37, 0ll);
 		for(int i = 0; i < N; ++i){ cin >> X[i]; }
 		sort(X.begin(), X.end());
 		double answer = 0.0;
 		for(ll i = 1; i <= B; ++i){
 			if(X[0] >= i){ continue; }
 			vector<ll> Y(37, 0ll);
 			ll r = B;
 			for(int j = 0; j < 37; ++j){
 				if(X[j] < i){
 					Y[j] = i - X[j];
 					r -= Y[j];
 				}
 			}
 			if(r < 0){ break; }
 			for(int j = 36; r > 0 && j >= 0; --j){
 				if(X[j] > i){ continue; }
 				int m = 0;
 				for(int k = 0; k < 37; ++k){
 					if(X[k] + Y[k] == X[0] + Y[0]){ ++m; }
 				}
 				double e = 0.0;
 				for(int k = 0; k < 37; ++k){
 					if(X[k] + Y[k] == X[0] + Y[0]){
 						e += 36.0 * Y[k] / m;
 					}
 					e -= Y[k];
 				}
 				answer = max(answer, e);
 				if(Y[j] < Y[0]){ ++Y[j]; --r; }
 			}
 			int m = 0;
 			for(int j = 0; j < 37; ++j){
 				if(X[j] + Y[j] == X[0] + Y[0]){ ++m; }
 			}
 			double e = 0.0;
 			for(int j = 0; j < 37; ++j){
 				if(X[j] + Y[j] == X[0] + Y[0]){
 					e += 36.0 * Y[j] / m;
 				}
 				e -= Y[j];
 			}
 			answer = max(answer, e);
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
