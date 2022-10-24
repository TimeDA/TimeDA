#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef double Real;

int N;
int p;

int w[110], h[110];
int le[110];
Real ri[110];

void input(){
	scanf("%d", &N);
	scanf("%d", &p);
	for(int i = 0; i < N; ++i){
		scanf("%d%d", w + i, h + i);
	}
}

Real dp[110][110 * 255];

Real solve(){
	int a = 0;
	for(int i = 0; i < N; ++i){
		a += 2 * (w[i] + h[i]);
	}
	Real req = p - a;
	for(int i = 0; i < N; ++i){
		le[i] = min(w[i], h[i]);
		ri[i] = sqrt(w[i] * w[i] + h[i] * h[i]);
		//le[i] *= 2;
		ri[i] *= 2;
	}
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= N * 255; ++j){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= i * 255; ++j){
			if(dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
			dp[i + 1][j + le[i]] = max(dp[i + 1][j + le[i]], dp[i][j] + ri[i]);
		}
	}
	Real ans = 0;
	for(int j = 0; j <= N * 255; ++j){
		if(dp[N][j] == -1) continue;
		if(j * 2 > p - a) continue;
		if(dp[N][j] >= req) ans = req;
		else ans = max(ans, dp[N][j]);
	}
	return a + ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		input();
		Real ans = solve();
		printf("Case #%d: ", t + 1);
		printf("%.12f\n", ans);
	}
	return 0;
}
