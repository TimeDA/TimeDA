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
 
 int n;
 double V, X, r[105], c[105];
 
 void solve(int tc){
 	scanf("%d%lf%lf", &n, &V, &X);
 	FOR(i,0,n) scanf("%lf%lf", &r[i], &c[i]);
 	printf("Case #%d: ", tc);
 	if (n == 1){
 		if (fabs(X - c[0]) < 1e-9) printf("%.9f\n", V / r[0]);
 		else puts("IMPOSSIBLE");
 	}
 	else{
 		if (fabs(c[1] - c[0]) < 1e-9){
 			if (fabs(X - c[0]) < 1e-9) printf("%.9f\n", V / (r[0] + r[1]));
 			else puts("IMPOSSIBLE");
 		}
 		else if (min(c[0], c[1]) <= X && X <= max(c[0], c[1])){
 			double a = (X - c[1]) / (c[0] - c[1]);
 			printf("%.9f\n", max(V*a/r[0], V*(1-a)/r[1]));
 		}
 		else puts("IMPOSSIBLE");
 	}
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
