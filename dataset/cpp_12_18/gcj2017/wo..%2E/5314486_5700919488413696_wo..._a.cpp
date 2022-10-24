#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int P;
 int cnt[4];
 int dp[110][110][110][4];
 
 void input(){
 	int N;
 	scanf("%d%d", &N, &P);
 	for(int i = 0; i < 4; ++i) cnt[i] = 0;
 	for(int i = 0; i < N; ++i){
 		int x;
 		scanf("%d", &x);
 		cnt[x % P]++;
 	}
 }
 
 inline int dec(int cur, int d){
 	int res = cur - d;
 	if(res < 0) res += P;
 	return res;
 }
 
 inline void chmax(int &a, int b){
 	if(a < b) a = b;
 }
 
 int solve(){
 	for(int i = 0; i < 110; ++i){
 		for(int j = 0; j < 110; ++j){
 			for(int k = 0; k < 110; ++k){
 				for(int l = 0; l < 4; ++l){
 					dp[i][j][k][l] = 0;
 				}
 			}
 		}
 	}
 	for(int i = 0; i <= cnt[1]; ++i){
 		for(int j = 0; j <= cnt[2]; ++j){
 			for(int k = 0; k <= cnt[3]; ++k){
 				for(int l = 0; l < P; ++l){
 					if(i == 0 && j == 0 && k == 0) continue;
 					if(i != 0){
 						int prv = dec(l, 1);
 						if(prv == 0) chmax(dp[i][j][k][l], dp[i - 1][j][k][prv] + 1);
 						else chmax(dp[i][j][k][l], dp[i - 1][j][k][prv]);
 					}
 					if(j != 0){
 						int prv = dec(l, 2);
 						if(prv == 0) chmax(dp[i][j][k][l], dp[i][j - 1][k][prv] + 1);
 						else chmax(dp[i][j][k][l], dp[i][j - 1][k][prv]);
 					}
 					if(k != 0){
 						int prv = dec(l, 1);
 						if(prv == 0) chmax(dp[i][j][k][l], dp[i][j][k - 1][prv] + 1);
 						else chmax(dp[i][j][k][l], dp[i][j][k - 1][prv]);
 					}
 				}
 			}
 		}
 	}
 	return dp[cnt[1]][cnt[2]][cnt[3]][(cnt[1] + cnt[2] * 2 + cnt[3] * 3) % P] + cnt[0];
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		int ans = solve();
 		printf("Case #%d: %d\n", datano + 1, ans);
 	}
 	return 0;
 }
