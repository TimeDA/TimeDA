#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define RI(x) scanf("%d", &x)
 #define RL(x) scanf("%lld", &x)
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, m, x, a[6];
 int dp[111][111][111], buf[111][111][111];
 
 void upd(int j0, int j1, int j2, int j3, int v){
 	dp[j1][j2][j3] = min(dp[j1][j2][j3], v);
 }
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	CLR(a,0);
 	RI(n),RI(m);FOR(i,0,n) RI(x),++a[x%m];
 	
 	FOE(j1,0,n) FOE(j2,0,n) FOE(j3,0,n) dp[j1][j2][j3] = 999;
 	dp[0][0][0] = 0;
 	FOR(i,0,n){
 		FOE(j1,0,n) FOE(j2,0,n) FOE(j3,0,n){
 			buf[j1][j2][j3] = dp[j1][j2][j3];
 			dp[j1][j2][j3] = 999;
 		}
 		FOE(j1,0,n) FOE(j2,0,n) FOE(j3,0,n) if (buf[j1][j2][j3] < 999){
 		//	printf("%d %d %d %d %d\n", i,j1,j2,j3,buf[j1][j2][j3]);
 			int j0=i-j1-j2-j3;
 			int l = !!((j1 + 2*j2 + 3*j3) % m);
 			if (j0 < a[0]) upd(j0+1, j1, j2, j3, buf[j1][j2][j3] + l);
 			if (j1 < a[1]) upd(j0, j1+1, j2, j3, buf[j1][j2][j3] + l);
 			if (j2 < a[2]) upd(j0, j1, j2+1, j3, buf[j1][j2][j3] + l);
 			if (j3 < a[3]) upd(j0, j1, j2, j3+1, buf[j1][j2][j3] + l);
 		}
 	}
 	int ret = 999;
 	FOE(j1,0,n) FOE(j2,0,n) FOE(j3,0,n) ret=min(ret,dp[j1][j2][j3]);
 	printf(" %d\n",n-ret);
 
 
 
 
 }return 0;}
