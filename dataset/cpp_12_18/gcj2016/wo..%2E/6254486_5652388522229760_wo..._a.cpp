#include<cstdio>
 
 using namespace std;
 
 bool used[10];
 
 void markDigits(int n){
 	if(n == 0){
 		used[0] = true;
 		return;
 	}
 	while(n > 0){
 		used[n % 10] = true;
 		n /= 10;
 	}
 }
 
 void solve(int t, int N){
 	if(N == 0){
 		printf("CASE #%d: INSOMNIA\n", t);
 		return;
 	}
 	for(int i = 0; i < 10; ++i) used[i] = false;
 	for(int i = 1; i < 150; ++i){
 		int x = i * N;
 		markDigits(x);
 		bool ok = true;
 		for(int j = 0; j < 10; ++j){
 			if(!used[j]) ok = false;
 		}
 		if(ok){
 			printf("CASE #%d: %d\n", t, x);
 			return;
 		}
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		int N;
 		scanf("%d", &N);
 		solve(datano + 1, N);
 	}
 	return 0;
 }
