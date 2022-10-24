#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 using ll = long long;
 static const int INF = 1000000000;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, m;
 		cin >> n >> m;
 		vector<ll> r(n);
 		for(int i = 0; i < n; ++i){ cin >> r[i]; }
 		vector<vector<ll>> q(n, vector<ll>(m));
 		for(int i = 0; i < n; ++i){
 			for(int j = 0; j < m; ++j){ cin >> q[i][j]; }
 			sort(q[i].begin(), q[i].end());
 		}
 		vector<int> x(n, 0);
 		int answer = 0;
 		while(count(x.begin(), x.end(), m) == 0){
 			ll count = INF, min_idx = 0;
 			for(int i = 0; i < n; ++i){
 				const ll t = (q[i][x[i]] * 10) / (r[i] * 9);
 				if(t < count){
 					count = t;
 					min_idx = i;
 				}
 			}
 			bool accept = true;
 			for(int i = 0; i < n; ++i){
 				const ll lo = r[i] * count * 9, hi = r[i] * count * 11;
 				const ll t = q[i][x[i]] * 10;
 				if(t < lo || hi < t){ accept = false; }
 			}
 			if(accept){
 				for(int i = 0; i < n; ++i){ ++x[i]; }
 				++answer;
 			}else{
 				++x[min_idx];
 			}
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
