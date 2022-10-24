#include <iostream>
 #include <string>
 #include <vector>
 #include <stack>
 #include <array>
 #include <algorithm>
 #include <cstdint>
 
 using namespace std;
 using array_type = array<uint8_t, 10>;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	vector<string> inputs(T);
 	for(int i = 0; i < T; ++i){ cin >> inputs[i]; }
 	vector<int> solution(T);
 #pragma omp parallel for schedule(dynamic)
 	for(int case_num = 1; case_num <= T; ++case_num){
 		string s = inputs[case_num - 1];
 		const int n = s.size();
 		array_type init = { 0 };
 		for(int i = 0; i < n; ++i){ init[i] = s[i] - '0'; }
 		stack<array_type> q;
 		q.push(init);
 		int answer = 0;
 		while(!q.empty()){
 			++answer;
 			const auto a = q.top();
 			q.pop();
 			int sum = 0;
 			for(int i = 0; i < n; ++i){ sum += a[i]; }
 			if(sum > n){ continue; }
 			array_type b = { 0 };
 			for(int i = 0, j = n - sum; i < n; ++i){
 				for(int k = 0; k < a[i]; ++k){ b[j++] = i + 1; }
 			}
 			do {
 				if(b != a){ q.push(b); }
 			} while(next_permutation(b.begin(), b.begin() + n));
 		}
 		solution[case_num - 1] = answer;
 	}
 	for(int case_num = 1; case_num <= T; ++case_num){
 		cout << "Case #" << case_num << ": " << solution[case_num - 1] << endl;
 	}
 	return 0;
 }
 
