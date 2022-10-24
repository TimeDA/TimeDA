#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 void solve_single_case(){
 	int n, l;
 	cin >> n >> l;
 	vector<string> good(n);
 	string bad;
 	for(int i = 0; i < n; ++i){ cin >> good[i]; }
 	cin >> bad;
 	for(int i = 0; i < n; ++i){
 		if(good[i] == bad){
 			cout << "IMPOSSIBLE" << endl;
 			return;
 		}
 	}
 	for(int i = 0; i < l - 1; ++i){ cout << "?"; }
 	if(l == 1){ cout << "0"; }
 	cout << " ";
 	for(int i = 0; i < (l + 1) / 2 + 3; ++i){ cout << "01"; }
 	cout << "0?";
 	for(int i = 0; i < (l + 1) / 2 + 3; ++i){ cout << "10"; }
 	cout << endl;
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
 
 
