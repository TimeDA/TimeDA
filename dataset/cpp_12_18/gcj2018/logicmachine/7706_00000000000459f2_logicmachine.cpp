#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	if(a.front() == 0 || a.back() == 0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<int> b;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < a[i]; ++j){ b.push_back(i); }
	}
	int num_rows = 1;
	for(int i = 0; i < n; ++i){
		num_rows = max(num_rows, abs(b[i] - i) + 1);
	}
	vector<string> solution(num_rows, string(n, '.'));
	for(int i = 0; i < n; ++i){
		if(b[i] < i){
			for(int j = i, k = 0; j > b[i]; --j, ++k){
				solution[k][j] = '/';
			}
		}else if(b[i] > i){
			for(int j = i, k = 0; j < b[i]; ++j, ++k){
				solution[k][j] = '\\';
			}
		}
	}
	cout << num_rows << endl;
	for(const auto& s : solution){
		cout << s << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		cout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}

