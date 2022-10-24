#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define RI(x) scanf("%d", &x)
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, m;
 double a[222], b[222], ret, dp[222];
 
 double solve(){
 	FOE(i,0,n) dp[i] = 0.0;
 	dp[0] = 1.;
 	FOR(i,0,m){
 		for (int j=m; j>=1; j--) dp[j] = dp[j] * b[i] + dp[j-1] * (1. - b[i]);
 		dp[0] *= b[i];
 	}
 	return dp[m/2];
 }
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	RI(n), RI(m);
 	FOR(i,0,n) scanf("%lf", &a[i]);
 	sort(a, a + n);
 	
 	double ret = 0;
 	FOE(i,0,m){
 		int t = 0;
 		FOR(j,0,i) b[t++] = a[j];
 		FOD(j,n,0) b[t++] = a[j];
 		ret = max(ret, solve());
 	}
 	
 	printf(" %.9f\n", ret);
 }return 0;}
