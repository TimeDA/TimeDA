#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 typedef long long LL;
 
 int cs;
 LL B, N, x[40];
 double ans=0;
 void test(LL v) {
 	if(v<=0) return;
 	LL bet[40]={}, sum=0, vt[40]={};
 	for(int r=1;r<38;r++) {
 		sum=0;
 		for(int i=0;i<37;i++) vt[i] = v+(i>=r);
 		for(int i=0;i<37;i++)
 			sum += (bet[i] = (x[i]<vt[i]? vt[i]-x[i]: 0));
 		if(sum && sum <= B) {
 			int base=0;
 			LL suc=0;
 			for(int i=0;i<r;i++)
 				if(x[i]<=v) {
 					++base;
 					suc += bet[i];
 				}
 			//printf("suc=%I64d, base=%d, B=%I64d\n", , base, B);
 			ans = max(ans, suc / (double)base * 36.0 - (double)sum);
 		}
 	}
 
 }
 void solve() {
 	scanf("%I64d%I64d", &B, &N);
 	ans=0;
 	for(int i=0;i<N;i++) scanf("%I64d", &x[i]);
 	for(int i=N;i<37;i++) x[i] = 0;
 	sort(x, x+37);
 	for(int i=0;i<37;i++) if(i==0 || x[i]!=x[i-1]) {
 		test(x[i]-1);
 		test(x[i]);
 		LL sum=0;
 		int cnt=0;
 		for(int j=0;j<37;j++) sum += max(x[i]-x[j], 0LL);
 		for(int j=0;j<37;j++) cnt += (x[i]>=x[j]? 1: 0);
 		sum = B - sum;
 		test(x[i]+sum/cnt);
 		test(x[i]+sum/cnt-1);
 		test(x[i]+sum/cnt+1);
 		test(x[i]-2);
 		test(x[i]+1);
 	}
 	printf("Case #%d: %.9f\n", cs, ans);
 	fprintf(stderr, "Case #%d: %.9f\n", cs, ans);
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
