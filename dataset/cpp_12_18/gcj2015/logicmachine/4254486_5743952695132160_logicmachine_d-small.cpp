#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <unordered_map>
 #include <cassert>
 
 using namespace std;
 
 static int triangle[30][30] = { { 0 } };
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	for(int i = 0; i < 30; ++i){
 		triangle[i][0] = 1;
 		for(int j = 1; j <= i; ++j){
 			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
 		}
 	}
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		cin >> n;
 		vector<int> e(n), f(n);
 		for(int i = 0; i < n; ++i){ cin >> e[i]; }
 		for(int i = 0; i < n; ++i){ cin >> f[i]; }
 		assert(e[0] == 0);
 		const int nz = __builtin_ctz(f[0]);
 		vector<int> answer(nz, 0);
 		unordered_map<int, int> mp;
 		mp.insert(make_pair(0, f[0]));
 		for(int i = 1; i < n; ++i){
 			const int v = e[i], t = mp[v];
 			if(f[i] == t){ continue; }
 			const int c = ((f[i] - t) >> nz);
 			for(int j = 0; j < c; ++j){ answer.push_back(v); }
 			unordered_map<int, int> next;
 			for(const auto &p : mp){
 				for(int j = 0; j <= c; ++j){
 					next[p.first + v * j] += p.second * triangle[c][j];
 				}
 			}
 			mp.swap(next);
 		}
 		cout << "Case #" << case_num << ":";
 		for(const auto &x : answer){ cout << " " << x; }
 		cout << endl;
 	}
 	return 0;
 }
 
