#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int igraph[4];
 int ngraph[4];
 
 int N;
 
 bool check(int i){
 	for(int state = 0; state < (1 << N); ++state){
 		if(((state >> i) & 1) == 1) continue;
 		int a = 0;
 		int cnt = 0;
 		bool valid = true;
 		for(int j = 0; j < N; ++j){
 			if(((state >> j) & 1) == 1){
 				if((ngraph[i] & ngraph[j]) == 0) valid = false;
 				a |= ngraph[j];
 				cnt++;
 			}
 		}
 		if(!valid) continue;
 		int c = 0;
 		for(int j = 0; j < N; ++j){
 			if(((ngraph[i] >> j) & 1) == 1){
 				c++;
 			}
 		}
 		if((a & ngraph[i]) == ngraph[i]){
 			if(c <= cnt){
 				return false;
 			}
 		}
 	}
 	return true;
 }
 
 bool check(){
 	for(int i = 0; i < N; ++i){
 		bool flg = check(i);
 		if(!flg) return false;
 	}
 	return true;
 }
 
 void solve(int tnum){
 	int ans = -1;
 	for(int state = 0; state < (1 << (N * N)); ++state){
 		bool ok = true;
 		for(int i = 0; i < N; ++i){
 			ngraph[i] = (state >> (i * N)) & ((1 << N) - 1);
 			if((igraph[i] & ngraph[i]) != igraph[i]) ok = false;
 		}
 		if(!ok){
 			continue;
 		}
 		bool flg = check();
 		if(flg){
 			int cnt = 0;
 			for(int i = 0; i < N; ++i){
 				for(int j = 0; j < N; ++j){
 					if(((igraph[i] >> j) & 1) == 0){
 						if(((ngraph[i] >> j) & 1) == 1){
 							cnt++;
 						}
 					}
 				}
 			}
 			if(ans == -1 || ans > cnt) ans = cnt;
 		}
 	}
 	printf("Case #%d: %d\n", tnum, ans);
 }
 
 void input(){
 	scanf("%d", &N);
 	char ch[10];
 	for(int i = 0; i < N; ++i){
 		scanf("%s", ch);
 		igraph[i] = 0;
 		for(int j = 0; j < N; ++j){
 			if(ch[j] == '1'){
 				igraph[i] |= (1 << j);
 			}
 		}
 	}
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
