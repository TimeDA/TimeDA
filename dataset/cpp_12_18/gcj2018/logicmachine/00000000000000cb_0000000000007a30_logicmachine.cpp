#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
	const int n = 14, m = 15;
	int a;
	cin >> a;
	vector<vector<int>> f(n, vector<int>(m));
	bool finish = false;
	for(int i = 0; !finish && i < n; ++i){
		for(int j = 0; !finish && j < m; ++j){
			while(f[i][j] == 0){
				cout << min(i + 2, n - 1) << " " << min(j + 2, m - 1) << endl << flush;
				int y, x;
				cin >> y >> x;
				if(y == 0 && x == 0){
					finish = true;
					break;
				}else{
					f[y - 1][x - 1] = 1;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		solve();
	}
	return 0;
}

