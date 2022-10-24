#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 int digits[20];
 
 long long solve(long long x){
 	long long tmp_ = x;
 	for(int i = 0; i < 20; ++i){
 		digits[i] = tmp_ % 10;
 		tmp_ /= 10;
 	}
 	bool flg = true;
 	for(int i = 0; i + 1 < 20; ++i){
 		if(digits[i] < digits[i + 1]){
 			flg = false;
 			break;
 		}
 	}
 	if(flg){
 		return x;
 	}
 	reverse(digits, digits + 20);
 	int tmp[20];
 	long long res = -1;
 	for(int i = 1; i + 1 < 20; ++i){
 		copy_n(digits, 20, tmp);
 		if(tmp[i - 1] < tmp[i]){
 			tmp[i]--;
 			for(int j = i + 1; j < 20; ++j){
 				tmp[j] = 9;
 			}
 		}
 		bool ok = true;
 		for(int j = 0; j + 1 < 20; ++j){
 			if(tmp[j] > tmp[j + 1]){
 				ok = false;
 				break;
 			}
 		}
 		if(ok){
 			long long cur = 0;
 			for(int j = 0; j < 20; ++j){
 				cur *= 10;
 				cur += tmp[j];
 			}
 			if(res < cur) res = cur;
 		}
 	}
 	if(res == -1){
 		fprintf(stderr, "error\n");
 	}
 	return res;
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		long long x;
 		scanf("%lld", &x);
 		long long ans = solve(x);
 		printf("Case #%d: %lld\n", datano + 1, ans);
 	}
 	return 0;
 }
