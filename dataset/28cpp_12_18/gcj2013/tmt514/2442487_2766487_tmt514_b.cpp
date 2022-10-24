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
 
 void solve() {
 	int N;
 	LL P, A=0, B=0;
 	scanf("%d%I64d", &N, &P);
 	LL accum=0;
 	for(int i=N-1;i>=0;i--) {
 		accum += (1LL<<i);
 		if(P > accum) A = min((1LL<<N)-1, A+2*(1LL<<(N-1-i)));
 	}
 	accum = 0;
 	for(int i=0;i<N;i++) {
 		accum += (1LL<<i);
 		if(P > accum) B += 1LL<<(N-1-i);
 	}
 	printf("Case #%d: %I64d %I64d\n", cs, A, B);
 	fprintf(stderr, "Case #%d: %I64d %I64d\n", cs, A, B);
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++)
 		solve();
 	return 0;
 }
