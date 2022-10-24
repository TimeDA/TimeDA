#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
static const int LIMIT = 34;
static int dp[LIMIT][501][501];

void solve(){
	int n, m;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for(int j = 0, acc = 0; j < LIMIT; ++j){
		acc += j;
		if(acc <= m){ dp[0][n][m - acc] = j; }
	}
	for(int k = 0; k + 1 < LIMIT; ++k){
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				if(dp[k][i][j] < 0){ continue; }
				int r = i, b = j;
				for(int l = 0; l < LIMIT; ++l){
					r -= (k + 1);
					b -= l;
					if(r < 0 || b < 0){ break; }
					dp[k + 1][r][b] = max(dp[k + 1][r][b], dp[k][i][j] + l + 1);
				}
				dp[k + 1][i][j] = max(dp[k + 1][i][j], dp[k][i][j]);
			}
		}
	}
	int answer = 0;
	for(int i = 0; i < LIMIT; ++i){
		for(int j = 0; j <= n; ++j){
			for(int k = 0; k <= m; ++k){
				answer = max(answer, dp[i][j][k]);
			}
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

