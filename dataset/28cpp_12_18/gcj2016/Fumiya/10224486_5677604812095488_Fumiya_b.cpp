#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int bitCount(int t){
 	int res = 0;
 	for(int i=t;i;i&=i-1) res++;
 	return res;
 }
 
 double solveSmall(const vector<double> vd){
 	int n = vd.size();
 	double dp[20][20];
 	for(int i=0;i<=n;i++)
 		for(int j=0;j<=n;j++) dp[i][j] = 0.0;
 	dp[0][0] = 1.0;
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			dp[i+1][j+1] += dp[i][j] * vd[i];
 			dp[i+1][j  ] += dp[i][j] * (1-vd[i]);
 		}
 	}
 	return dp[n][n/2];
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int N, K;
 		cin >> N >> K;
 		vector<double> vd(N);
 		for(int i=0;i<N;i++) cin >> vd[i];
 		vector<double> vk(K);
 		double res = 0.0;
 		for(int i=0;i<(1<<N);i++){
 			if(bitCount(i) != K) continue;
 			int idx = 0;
 			for(int j=0;j<N;j++){
 				if(!((i&(1<<j)))) continue;
 				vk[idx] = vd[j];
 				++idx;
 			}
 			res = max(res, solveSmall(vk));
 		}
 		printf("Case #%d: %.8lf\n", t, res);
 	}
 }
