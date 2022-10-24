#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 LLD n, m;
 
 LLD Goodest(LLD n, LLD m){
 	LLD a, b;
 	a = m;
 	b = (1LL<<n) - a - 1;
 	LLD R = 0, N = (1LL<<n);
 	FOR(i,0,n){
 		if (b){
 			--b;
 			if (a & 1) a = (a + 1) / 2, b >>= 1;
 			else a >>= 1, b >>= 1;
 		}
 		else{
 			R += (N >> 1), --a;
 			a >>= 1;
 		}
 		N >>= 1;
 	}
 	return R;
 }
 
 LLD Baddest(LLD n, LLD m){
 	LLD a, b;
 	a = m;
 	b = (1LL<<n) - a - 1;
 	LLD R = 0, N = (1LL<<n);
 	FOR(i,0,n){
 		if (a){
 			--a, R += (N >> 1);
 			a >>= 1;
 			b = (N>>1) - 1 - a;
 		}
 		else{
 			--b;
 			b >>= 1;
 		}
 		N >>= 1;
 	}
 	return R;
 }
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%lld%lld", &n, &m);
 	LLD N = (1<<n) - 1, ret;
 	for (LLD i=0, j=N, k; j>=i;){
 		k = (i + j) >> 1;
 		if (Baddest(n, k) + 1 <= m) ret = k, i = k + 1;
 		else j = k - 1;
 	}
 	printf("%lld ", ret);
 	for (LLD i=0, j=N, k; j>=i;){
 		k = (i + j) >> 1;
 		if (Goodest(n, k) + 1 <= m) ret = k, i = k + 1;
 		else j = k - 1;
 	}
 	printf("%lld\n", ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
