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
 		cin >> s;
 		const int n = s.size();
 		vector<int> v(n);
 		for(int i = 0; i < n; ++i){
 			v[i] = (s[i] == '+' ? 1 : -1);
 		}
 		bool flip = false;
 		int answer = 0;
 		while(true){
 			while(!v.empty() && v.back() == 1){ v.pop_back(); }
 			if(v.empty()){ break; }
 			if(v[0] == 1){
 				for(auto &x : v){
 					if(x != 1){ break; }
 					x *= -1;
 				}
 			}else{
 				reverse(v.begin(), v.end());
 				for(auto &x : v){ x *= -1; }
 			}
 			++answer;
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
