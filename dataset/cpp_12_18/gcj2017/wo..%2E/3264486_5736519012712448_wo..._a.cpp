#include<cstdio>
 #include<cstring>
 
 using namespace std;
 
 bool flg[1010];
 int N;
 int K;
 
 void input(){
 	char ch[1010];
 	scanf("%s%d", ch, &K);
 	N = strlen(ch);
 	for(int i = 0; i < N; ++i){
 		flg[i] = (ch[i] == '+');
 	}
 }
 
 int solve(){
 	int cnt = 0;
 	for(int i = 0; i + K <= N; ++i){
 		if(!flg[i]){
 			cnt++;
 			for(int j = 0; j < K; ++j){
 				flg[i + j] = !flg[i + j];
 			}
 		}
 	}
 	bool ok = true;
 	for(int i = 0; i < N; ++i){
 		ok = ok & flg[i];
 	}
 	if(!ok) return -1;
 	else return cnt;
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		int ans = solve();
 		if(ans == -1){
 			printf("Case #%d: IMPOSSIBLE\n", datano + 1);
 		}else{
 			printf("Case #%d: %d\n", datano + 1, ans);
 		}
 	}
 	return 0;
 }
