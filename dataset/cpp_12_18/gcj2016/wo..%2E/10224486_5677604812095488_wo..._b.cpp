#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 typedef double Real;
 
 Real ps[220];
 int N;
 int K;
 
 Real calc(vector<Real> ps){
 	int n = ps.size();
 	Real dp[220][220];
 	for(int i = 0; i < 220; ++i) for(int j = 0; j < 220; ++j){
 		dp[i][j] = 0;
 	}
 	dp[0][0] = 1;
 	for(int i = 0; i < n; ++i){
 		Real p = ps[i];
 		for(int j = 0; j <= i; ++j){
 			dp[i + 1][j + 1] += dp[i][j] * p;
 			dp[i + 1][j] += dp[i][j] * (1.0 - p);
 		}
 	}
 	return dp[n][n / 2];
 }
 
 Real calc(int sm){
 	vector<Real> vec;
 	for(int i = 0; i < sm; ++i){
 		vec.push_back(ps[i]);
 	}
 	for(int i = 0; i < (K - sm); ++i){
 		vec.push_back(ps[N - 1 - i]);
 	}
 	return calc(vec);
 }
 
 void solve(int tnum){
 	Real best = -1;
 	for(int i = 0; i <= K; ++i){
 		Real tmp = calc(i);
 		if(best < tmp) best = tmp;
 	}
 	printf("Case #%d: %.9f\n", tnum, best);
 }
 
 void input(){
 	scanf("%d%d", &N, &K);
 	for(int i = 0; i < N; ++i){
 		scanf("%lf", ps + i);
 	}
 	sort(ps, ps + N);
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		solve(datano + 1);
 	}
 	return 0;
 }
