#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <tuple>
 
 using namespace std;
 typedef tuple<int, int, int> tiii;
 
 vector<int> optimize(int n, vector<int> v){
 	const int m = (1 << n);
 	for(int i = 0; i < n; ++i){
 		const int step = (1 << i);
 		for(int j = 0; j < m; j += step + step){
 			bool flag = false;
 			for(int k = 0; !flag && k < step; ++k){
 				if(v[j + k] == v[j + step + k]){ continue; }
 				if(v[j + k] > v[j + step + k]){ flag = true; }
 				break;
 			}
 			if(flag){
 				for(int k = 0; k < step; ++k){
 					swap(v[j + k], v[j + step + k]);
 				}
 			}
 		}
 	}
 	return v;
 }
 
 vector<int> solve(int n, const int *a, int root){
 	int b[] = { a[0], a[1], a[2] };
 	queue<tiii> q;
 	q.emplace(root, n, 0);
 	vector<int> answer(1 << n);
 	while(!q.empty()){
 		const auto p = q.front();
 		q.pop();
 		const int h = get<0>(p);
 		--b[h];
 		answer[get<2>(p)] = h;
 		for(int i = 0; i < get<1>(p); ++i){
 			q.emplace((h + 1) % 3, i, get<2>(p) ^ (1 << i));
 		}
 	}
 	if(b[0] != 0 || b[1] != 0 || b[2] != 0){ return vector<int>(); }
 	return optimize(n, answer);
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, a[3];
 		cin >> n >> a[1] >> a[0] >> a[2];
 		vector<int> answer = solve(n, a, 0);
 		if(answer.empty()){ answer = solve(n, a, 1); }
 		if(answer.empty()){ answer = solve(n, a, 2); }
 		string s;
 		if(answer.empty()){
 			s = "IMPOSSIBLE";
 		}else{
 			s = string(1 << n, ' ');
 			for(int i = 0; i < (1 << n); ++i){
 				s[i] = "PRS"[answer[i]];
 			}
 		}
 		cout << "Case #" << case_num << ": " << s << endl;
 	}
 	return 0;
 }
 
