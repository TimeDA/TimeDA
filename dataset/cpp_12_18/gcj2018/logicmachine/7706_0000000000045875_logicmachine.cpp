#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			if(x >= 0){
				a[i][j] = x - 1;
			}else{
				a[i][j] = n + (-x - 1);
			}
		}
	}
	const int m = 2 * n;
	vector<vector<int>> hor(n, vector<int>(m));
	vector<vector<int>> ver(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			hor[i][a[i][j]]++;
			ver[j][a[i][j]]++;
		}
	}
	bool modified = true;
	while(modified){
		modified = false;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(a[i][j] < 0){ continue; }
				const int c = a[i][j];
				if(hor[i][c] >= 2 && ver[j][c] == 1){
					for(int k = 0; k < n; ++k){
						if(k == j){ continue; }
						if(a[i][k] == c){
							a[i][k] = -1;
							--ver[k][c];
						}
					}
					hor[i][c] = 1;
					modified = true;
				}else if(hor[i][c] == 1 && ver[j][c] >= 2){
					for(int k = 0; k < n; ++k){
						if(k == i){ continue; }
						if(a[k][j] == c){
							a[k][j] = -1;
							--hor[k][c];
						}
					}
					ver[j][c] = 1;
					modified = true;
				}
			}
		}
		if(modified){ continue; }
		for(int i = 0; !modified && i < n; ++i){
			for(int j = 0; !modified && j < n; ++j){
				if(a[i][j] < 0){ continue; }
				const int c = a[i][j];
				if(hor[i][c] >= 2 && ver[j][c] >= 2){
					for(int k = 0; k < n; ++k){
						if(k == j){ continue; }
						if(a[i][k] == c){
							a[i][k] = -1;
							--ver[k][c];
						}
					}
					for(int k = 0; k < n; ++k){
						if(k == i){ continue; }
						if(a[k][j] == c){
							a[k][j] = -1;
							--hor[k][c];
						}
					}
					hor[i][c] = 1;
					ver[j][c] = 1;
					modified = true;
				}
			}
		}
	}
	int answer = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a[i][j] < 0){ ++answer; }
		}
	}
	cout << answer << endl;
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

