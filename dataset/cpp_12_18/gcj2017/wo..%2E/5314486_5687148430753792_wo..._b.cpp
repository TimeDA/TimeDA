#include<cstdio>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int, int> P;
 
 int C;
 int cnt[1010][1010];
 int N;
 
 void input(){
 	int M;
 	scanf("%d%d%d", &N, &C, &M);
 	for(int i = 0; i < 1010; ++i){
 		for(int j = 0; j < 1010; ++j){
 			cnt[i][j] = 0;
 		}
 	}
 	for(int i = 0; i < M; ++i){
 		int x, y;
 		scanf("%d%d", &x, &y);
 		x--;
 		y--;
 		cnt[y][x]++;
 	}
 }
 
 P solve(){
 	int res = -1;
 	for(int i = 0; i < C; ++i){
 		int tmp = 0;
 		for(int j = 0; j < N; ++j){
 			tmp += cnt[i][j];
 		}
 		res = max(res, tmp);
 	}
 	int sum = 0;
 	for(int j = 0; j < N; ++j){
 		for(int i = 0; i < C; ++i){
 			sum += cnt[i][j];
 		}
 		int x = sum / (j + 1);
 		if(sum % (j + 1) != 0) x++;
 		res = max(res, x);
 	}
 	int valid = 0;
 	for(int j = 0; j < N; ++j){
 		int tmp = 0;
 		for(int i = 0; i < C; ++i){
 			tmp += cnt[i][j];
 		}
 		valid += min(tmp, res);
 	}
 	return P(res, sum - valid);
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		P p = solve();
 		printf("Case #%d: %d %d\n", datano + 1, p.first, p.second);
 	}
 	return 0;
 }
