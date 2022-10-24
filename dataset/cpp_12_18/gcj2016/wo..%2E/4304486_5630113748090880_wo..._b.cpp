#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int cnt[3000];
 int N;
 
 int a[200][200];
 
 void solve(int datano){
 	for(int i = 0; i < 3000; ++i) cnt[i] = 0;
 	for(int i = 0; i < N * 2 - 1; ++i){
 		for(int j = 0; j < N; ++j){
 			cnt[a[i][j]] ^= 1;
 		}
 	}
 	printf("Case #%d:", datano);
 	for(int i = 1; i<= 2500; ++i){
 		if(cnt[i] == 1){
 			printf(" %d", i);
 		}
 	}
 	printf("\n");
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 1; datano <= T; ++datano){
 		scanf("%d", &N);
 		for(int i = 0; i < N * 2 - 1; ++i){
 			for(int j = 0; j < N; ++j){
 				scanf("%d", &a[i][j]);
 			}
 		}
 		solve(datano);
 	}
 	return 0;
 }
