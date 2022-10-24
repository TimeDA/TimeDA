#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 void solve_single_case(){
 	string s;
 	cin >> s;
 	const int n = s.size();
 	vector<int> v(n);
 	for(int i = 0; i < n; ++i){ v[i] = (s[i] == 'C' ? 0 : 1); }
 	int answer = 0;
 	while(true){
 		const int m = v.size();
 		int k = 0;
 		for(int i = 0; i < m; ++i){
 			if(i + 1 < m && v[i] == v[i + 1]){
 				++i;
 				answer += 10;
 			}else{
 				v[k++] = v[i];
 			}
 		}
 		if(k == m){ break; }
 		v.resize(k);
 	}
 	answer += v.size() / 2 * 5;
 	cout << answer << endl;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		cout << "Case #" << case_num << ": ";
 		solve_single_case();
 	}
 	return 0;
 }
 
 
