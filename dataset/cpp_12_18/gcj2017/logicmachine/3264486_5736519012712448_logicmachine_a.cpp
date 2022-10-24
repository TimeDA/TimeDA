#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		string s;
 		int k;
 		cin >> s >> k;
 		const int n = s.size();
 		vector<int> v(n);
 		for(int i = 0; i < n; ++i){
 			v[i] = (s[i] == '+' ? 1 : 0);
 		}
 		int answer = 0;
 		for(int i = 0; i + k <= n; ++i){
 			if(v[i] == 0){
 				++answer;
 				for(int j = 0; j < k; ++j){ v[i + j] ^= 1; }
 			}
 		}
 		for(int i = 0; i < n; ++i){
 			if(v[i] == 0){ answer = -1; }
 		}
 		if(answer < 0){
 			cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
 		}else{
 			cout << "Case #" << case_num << ": " << answer << endl;
 		}
 	}
 	return 0;
 }
 
