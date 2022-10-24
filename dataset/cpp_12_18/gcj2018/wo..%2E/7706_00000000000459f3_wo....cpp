#include<cstdio>
#include<algorithm>

using namespace std;

const int S = 35;

int dp[S + 3][505][1010];

int solve(int R, int B){
	if(R > B) swap(R, B);
	for(int i = 0; i < S + 3; ++i){
		for(int j = 0; j < 505; ++j){
			for(int k = 0; k < 1010; ++k){
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][R][0] = B;
	int ans = 0;
	for(int i = 0; i <= S; ++i){
		// i red items per person
		for(int j = 0; j < 505; ++j){
			for(int k = 0; k < 1010; ++k){
				if(dp[i][j][k] == -1) continue;
				int s = 0;
				for(int x = 0; ; ++x){
					int tmp = dp[i][j][k] - s;
					if(tmp < 0) break;
					int ni = i + 1;
					int nj = j - x * i;
					int nk = k + x;
					if(nj < 0) break;
					dp[ni][nj][nk] = max(tmp, dp[ni][nj][nk]);
					ans = max(ans, nk);
//					printf("%d %d %d %d\n", ni, nj, nk, tmp);
					s += x;
				}
			}
		}
	}
	return ans - 1;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int R, B;
		scanf("%d%d", &R, &B);
		int ans = solve(R, B);
		printf("Case #%d: %d\n", t + 1, ans);
	}
	return 0;
}
