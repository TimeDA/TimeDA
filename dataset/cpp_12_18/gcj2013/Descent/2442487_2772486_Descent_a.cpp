#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 #define N 1005
 using namespace std;
 
 int Cost(int d, int n){
 	return n * (d + 1) - d * (d + 1) / 2;
 }
 
 int n, m, x, y, w;
 int a[N], b[N], d[N];
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%d%d", &n, &m);
 	CLR(a, 0);
 	CLR(b, 0);
 	LLD tot = 0;
 	FOR(i,0,m){
 		scanf("%d%d%d", &x, &y, &w);
 		x--, y--;
 		tot += Cost(y - x, n) * w;
 		a[x] += w, b[y] += w;
 	}
 
 	LLD ret = 0;
 	CLR(d, 0);
 	FOR(i,0,n){
 		FOD(j,n,1) d[j] = d[j - 1];
 		d[0] = a[i];
 		FOR(j,0,n){
 			int t = min(b[i], d[j]);
 			b[i] -= t;
 			d[j] -= t;
 			ret += Cost(j, n) * t;
 		}
 	}
 	printf("%lld\n", tot - ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
