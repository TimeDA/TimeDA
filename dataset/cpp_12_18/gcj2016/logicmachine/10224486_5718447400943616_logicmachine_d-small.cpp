#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 bool is_possible(
 	int n,
 	int done_worker,
 	int done_machine,
 	const int a[4][4])
 {
 	if(done_worker == ((1 << n) - 1)){ return true; }
 	for(int i = 0; i < n; ++i){
 		if(done_worker & (1 << i)){ continue; }
 		bool local = false;
 		for(int j = 0; j < n; ++j){
 			if(a[i][j] == 0){ continue; }
 			if(done_machine & (1 << j)){ continue; }
 			local = true;
 			if(!is_possible(n, done_worker | (1 << i), done_machine | (1 << j), a)){
 				return false;
 			}
 		}
 		if(!local){ return false; }
 	}
 	return true;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		cin >> n;
 		int a[4][4] = { { 0 } };
 		for(int i = 0; i < n; ++i){
 			string s;
 			cin >> s;
 			for(int j = 0; j < n; ++j){ a[i][j] = s[j] - '0'; }
 		}
 		int answer = n * n;
 		for(int i = 0; i < (1 << n * n); ++i){
 			int b[4][4];
 			for(int j = 0, x = i; j < n; ++j){
 				for(int k = 0; k < n; ++k){ 
 					b[j][k] = a[j][k] | (x & 1);
 					x >>= 1;
 				}
 			}
 			if(is_possible(n, 0, 0, b)){
 				answer = min(answer, __builtin_popcount(i));
 			}
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
