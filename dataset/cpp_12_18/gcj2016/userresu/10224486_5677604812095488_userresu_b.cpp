#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 using namespace std;
 #define MAXN 201
 
 int N, K;
 double A[MAXN], B[MAXN];
 double dp[MAXN][MAXN];
 double calc () {
 	dp[0][0] = 1;
 	for (int i=1;i<=K;++i) {
 		dp[i][0] = (1 - B[i]) * dp[i-1][0];
 		for (int j=1;j<=K;++j) dp[i][j] = B[i] * dp[i-1][j-1] + (1-B[i]) * dp[i-1][j];
 	}
 	return dp[K][K/2];
 }
 
 void main2 () {
 	scanf("%d %d",&N,&K);
 	for (int i=1;i<=N;++i) scanf("%lf",&A[i]);
 	sort(A+1,A+N+1);
 	int cnt;
 	double best = 0;
 	for (int i=0;i<=K;++i) {
 		cnt = 0;
 		for (int j=1;j<=i;++j) B[++cnt] = A[j];
 		for (int j=N-K+i+1;j<=N;++j) B[++cnt] = A[j];
 		best=max(best,calc());
 	}
 	printf("%.9lf\n",best);
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
