#include<cstdio>
 
 using namespace std;
 
 int bits[32];
 
 int N, J;
 
 long long calc(int B, int *a, int ln){
 	long long res = 0;
 	long long coe = 1;
 	for(int i = ln - 1; i >= 0; --i){
 		res += coe * a[i];
 		coe *= B;
 	}
 	return res;
 }
 
 void solve(){
 	for(int i = 0; i < J; ++i){
 		for(int j = 0; j < N; ++j) bits[j] = 0;
 		bits[0] = 1;
 		bits[N / 2 - 1] = 1;
 		int tmp = i;
 		for(int j = 0; j < N / 2 - 2; ++j){
 			bits[N / 2 - 2 - j] = (tmp >> j) & 1;
 		}
 		for(int j = N / 2; j < N; ++j){
 			bits[j] = bits[j - N / 2];
 		}
 		for(int j = 0; j < N; ++j){
 			printf("%d", bits[j]);
 		}
 		for(int b = 2; b <= 10; ++b){
 			long long val = calc(b, bits + N / 2, N / 2);
 			printf(" %lld", val);
 		}
 		printf("\n");
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	printf("Case #%d:\n", 1);
 	scanf("%d%d", &N, &J);
 	solve();
 	return 0;
 }
