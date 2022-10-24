#include<cstdio>
 #include<map>
 #include<cstdlib>
 #include<algorithm>
 
 using namespace std;
 
 map<long long, long long> dp;
 
 long long get(long long n, long long x){
 	if(dp.count(n) == 1){
 		return dp[n];
 	}
 	if(n <= x){
 		return 0;
 	}
 	long long a = (n - 1) / 2;
 	long long b = n - 1 - a;
 	long long c = get(a, x);
 	long long d = get(b, x);
 	return dp[n] = c + d + 1;
 }
 
 void solve(int datano, long long N, long long K){
 	long long lb = 0, ub = N;
 	while(ub - lb > 1){
 		long long mid = (ub + lb) / 2;
 		fflush(stdout);
 		map<long long, long long> tmp;
 		swap(dp, tmp);
 		long long c = get(N, mid);
 		if(c <= K - 1){
 			ub = mid;
 		}else{
 			lb = mid;
 		}
 	}
 	long long x = ub;
 	long long mi = (ub - 1) / 2;
 	long long ma = x - 1 - mi;
 	printf("Case #%d: %lld %lld\n", datano + 1, ma, mi);
 	fflush(stdout);
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		long long N, K;
 		scanf("%lld%lld", &N, &K);
 		solve(datano, N, K);
 	}
 	return 0;
 }
