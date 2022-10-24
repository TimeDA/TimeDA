#include<cstdio>
#include<algorithm>

using namespace std;

int N;
long long ms[1010], ss[1010], ps[1010];

int B;
int R;

long long dp[1010][1010];

void input(){
	scanf("%d%d%d", &R, &B, &N);
	for(int i = 0; i < N; ++i){
		scanf("%lld%lld%lld", ms + i, ss + i, ps + i);
	}
}

long long calc(int id, long long t){
	t -= ps[id];
	if(t < 0) return 0;
	t /= ss[id];
	return min(ms[id], t);
}

long long solve(){
	long long lb = -1, ub = 1e13;
	while(ub - lb > 1){
		long long mid = (ub + lb) / 2;
		for(int i = 0; i <= N; ++i){
			for(int j = 0; j <= N; ++j){
				dp[i][j] = 0;
			}
		}
		for(int i = 0; i < N; ++i){
			for(int j = 0; j <= i; ++j){
				long long tmp = dp[i][j] + calc(i, mid);
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], tmp);
			}
		}
		if(dp[N][R] >= B) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		input();
		long long ans = solve();
		printf("Case #%d: ", t + 1);
		printf("%lld\n", ans);
	}
	return 0;
}
