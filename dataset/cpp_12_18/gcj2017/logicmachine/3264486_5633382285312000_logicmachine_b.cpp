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
 		string answer(n, '0');
 		for(int i = 0; i <= n; ++i){
 			if(s[i] == '0'){ continue; }
 			string t(s);
 			if(i < n){ t[i] -= 1; }
 			for(int j = i + 1; j < n; ++j){ t[j] = '9'; }
 			bool accept = true;
 			for(int j = 1; j < n; ++j){
 				if(t[j - 1] > t[j]){ accept = false; }
 			}
 			if(accept){
 				answer = max(answer, t);
 			}
 		}
 		cout << "Case #" << case_num << ": ";
 		for(int i = 0; i < n; ++i){
 			if(answer[i] != '0'){
 				cout << answer.c_str() + i << endl;
 				break;
 			}
 		}
 	}
 	return 0;
 }
 
