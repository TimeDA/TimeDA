#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 #define N 1000005
 using namespace std;
 
 int n;
 LLD sp, sq, sr, ss, a[N], s[N];
 
 void solve(int tc){
 	scanf("%d%lld%lld%lld%lld", &n, &sp, &sq, &sr, &ss);
 	LLD S = 0;
 	FOR(i,0,n){
 		a[i] = (i * sp + sq) % sr + ss;
 		S += a[i];
 		s[i+1] = s[i] + a[i];
 	}
 	LLD c1 = 0, c2, c3, ret = S;
 	int j = 0;
 	FOR(i,0,n){
 		LLD r = S - c1;
 		while ((s[j+1] - s[i]) * 2 < r) ++j;
 		FOE(k,j-2,j+2) if (k >= 0 && k < n){
 			c2 = s[k+1] - s[i];
 			c3 = S - c1 - c2;
 			ret = min(ret, max(c1, max(c2, c3)));
 		}
 		c1 += a[i];
 	}
 	
 	printf("Case #%d: %.12f\n", tc, 1. - ret * 1. / S);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
