#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 
 using namespace std;
 
 int a[1000000];
 int sum[1000001];
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N, p, q, r, s; cin >> N >> p >> q >> r >> s;
 		sum[0] = 0;
 		for(int i=0;i<N;i++){
 			a[i] = (i*(long long)p + q)%r + s;
 			sum[i+1] = sum[i] + a[i];
 		}
 		double res = 0.0;
 		for(int i=0;i<N;i++){
 			for(int j=i;j<N;j++){
 				res = max(res, (sum[N]-max(sum[i], max(sum[j+1]-sum[i], sum[N]-sum[j+1])))/(double)sum[N]);
 			}
 		}
 		printf("Case #%d: %.10lf\n", test, res);
 	}
 }
