#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

double dp[100*2*250+1];

double solve(){
	int N, P; cin >> N >> P;
	vector<int> W(N), H(N);
	int sum = 0;
	for(int i=0;i<N;i++){
		cin >> W[i] >> H[i];
		sum += 2 * (W[i] + H[i]);
	}
	dp[0] = 0.0;
	for(int i=1;i<=N*500;i++) dp[i] = -1e12;
	for(int i=0;i<N;i++){
		int addMin = 2 * min(W[i], H[i]);
		double addMax = 2.0 * sqrt(W[i] * W[i] + H[i] * H[i]);
		for(int j=N*500;j>=0;j--){
			if(j + addMin > N * 500) continue;
			if(dp[j] < 0.0) continue;
			dp[j+addMin] = max(dp[j+addMin], dp[j] + addMax);
		}
	}
	double res = sum;
	for(int i=0;i<=N*500;i++){
		if(sum + i > P) break;
		res = max(res, min((double)P, sum + dp[i]));
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		printf("Case #%d: %.10lf\n", t, solve());
	}
}
