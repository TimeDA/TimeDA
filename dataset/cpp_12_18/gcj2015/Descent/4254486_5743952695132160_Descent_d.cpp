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
 
 int n, ret, a[1<<20], f[1<<20], F[1<<20];
 
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%d", &n);
 	FOR(i,0,n) scanf("%d", &a[i]);
 	FOR(i,0,n) scanf("%d", &f[i]), F[i] = 0;
 	
 	while (f[0]) f[0] >>= 1, F[0]++;
 	FOR(i,0,F[0]-1) printf(" 0");
 	F[0] = (1 << (F[0] - 1));
 	
 	FOR(i,1,n) while (f[i] > F[i]){
 		FOD(j,n,0) if (F[j]){
 			int p = lower_bound(a, a + n, a[i] + a[j]) - a;
 			F[p] += F[j];
 		}
 		printf(" %d", a[i]);
 	}
 	puts("");
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
