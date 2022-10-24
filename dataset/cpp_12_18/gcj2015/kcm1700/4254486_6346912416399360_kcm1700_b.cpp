#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <cstring>
 #include <string>
 
 using namespace std;
 
 int n,K;
 int sum[1024];
 
 struct jump
 {
 	long long s,e;
 };
 
 bool sf(const jump &a, const jump &b) {
 	return a.e-a.s < b.e-b.s;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for (int testcase = 1; testcase <= T; testcase++){
 		scanf("%d%d",&n,&K);
 		for (int i = 0; i < n-K+1; i++) {
 			scanf("%d",&sum[i]);
 		}
 		vector<jump> jumps;
 		long long normaladd = 0;
 		for (int i = 0; i < K; i++) {
 			long long cur = 0;
 			jump ju;
 			ju.s = ju.e = 0;
 			for (int j = i; j+1 < n-K+1; j += K) {
 				cur += sum[j+1] - sum[j];
 				ju.s = min(ju.s, cur);
 				ju.e = max(ju.e, cur);
 			}
 			jumps.push_back(ju);
 			normaladd -= ju.s;
 			// a[i] are set to -ju.s, which is nonnegative
 		}
 		normaladd %= K;
 		normaladd += K;
 		normaladd %= K;
 		long long addition = (sum[0] - normaladd) % K;
 		addition += K;
 		addition %= K;
 		sort(jumps.begin(),jumps.end(),sf);
 		long long ans = jumps.back().e - jumps.back().s;
 
 		for (int i = 0; i < K; i++) {
 			if (ans - (jumps[i].e - jumps[i].s) >= 0) {
 				addition -= ans - (jumps[i].e - jumps[i].s);
 				if(addition < 0) break;
 			}
 		}
 		if(addition > 0) {
 			ans++;
 		}
 		printf("Case #%d: %lld\n", testcase, ans);
 	}
 	return 0;
 }
