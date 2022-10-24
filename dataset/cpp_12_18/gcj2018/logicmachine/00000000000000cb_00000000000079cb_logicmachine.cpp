#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	vector<int> even, odd;
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			even.push_back(a[i]);
		}else{
			odd.push_back(a[i]);
		}
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			b[i] = even[i / 2];
		}else{
			b[i] = odd[i / 2];
		}
	}
	int fail = 0;
	while(fail + 1 < n){
		if(b[fail] > b[fail + 1]){ break; }
		++fail;
	}
	if(fail + 1 == n){
		cout << "OK" << endl;
	}else{
		cout << fail << endl;
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

