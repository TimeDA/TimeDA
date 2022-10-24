#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int solve(int R, int B){
	static int dp[2][501][501];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=R;i++){
		const int cur = i%2;
		const int next = 1-cur;
		memset(dp[next], 0, sizeof(dp[next]));
		for(int j=0;j<=R;j++){
			for(int k=0;k<=B;k++){
				dp[next][j][k] = max(dp[next][j][k], dp[cur][j][k]);
				int m = 1;
				int add = (i==0 ? 1 : 0);
				int nextJ = j;
				int nextK = k;
				while(nextJ + i <= R && nextK + add <= B){
					nextJ += i;
					nextK += add;
					dp[next][nextJ][nextK] = max(dp[next][nextJ][nextK], dp[cur][j][k] + m);
					++add;
					++m;
				}
			}
		}
	}
	return dp[1-R%2][R][B];
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int R, B; cin >> R >> B;
		printf("Case #%d: %d\n", t, solve(R, B));
	}
}

