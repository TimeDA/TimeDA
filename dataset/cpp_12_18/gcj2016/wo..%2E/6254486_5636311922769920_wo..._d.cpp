#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 long long digits[110][110];
 
 long long K, C, S;
 
 long long calcVal(long long *a){
 	long long res = 0;
 	long long coe = 1;
 	for(int i = 0; i < C; ++i){
 		res += coe * a[i];
 		if(i + 1 < C) coe *= K;
 	}
 	return res;
 }
 
 void solve(int datano){
 	if(C * S < K){
 		printf("Case #%d: IMPOSSIBLE\n", datano);
 		return;
 	}
 	int d = 0;
 	int num = 0;
 	for(int i = 0; i < S; ++i){
 		for(int j = 0; j < C; ++j){
 			digits[i][j] = d % K;
 			++d;
 		}
 		if(d >= K){
 			num = i;
 			break;
 		}
 	}
 	vector<long long> ans;
 	for(int i = 0; i <= num; ++i){
 		long long val = calcVal(digits[i]);
 		ans.push_back(val);
 	}
 	sort(ans.begin(), ans.end());
 	ans.erase(unique(ans.begin(), ans.end()), ans.end());
 	printf("Case #%d:", datano);
 	for(int i = 0; i < ans.size(); ++i){
 		printf(" %lld", ans[i] + 1);
 	}
 	printf("\n");
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		scanf("%d%d%d", &K, &C, &S);
 		solve(datano + 1);
 	}
 	return 0;
 }
