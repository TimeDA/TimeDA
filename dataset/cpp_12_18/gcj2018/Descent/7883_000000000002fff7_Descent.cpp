#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

const int N = 111;
int n, m, a[N], b[N];
double P, ret;

int reach[33333];
double dp[33333];

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n), RI(m);
	P = 0.0;
	FOR(i,0,n) RI(a[i]), RI(b[i]), P += 2 * (a[i]+b[i]);
	
 	ret = P;
 	CLR(reach, 0);
	reach[0] = 1;
 	dp[0] = 0.;
 	
 	FOR(i,0,n){
 	   int    lo =  min(a[i], b[i]);
	   double hi =  sqrt(a[i] * 1. * a[i] + b[i] * 1. * b[i]);
	   
	   for (int j=250*i; j>=0; j--) if (reach[j]){
		   if (!reach[j+lo]){
		   	  reach[j + lo] = 1;
		   	  dp[j + lo] = dp[j] + hi;
		   }
		   else dp[j+lo] = max(dp[j+lo], dp[j]+hi);
	   }
 	}
 	
 	FOE(i,0,250*n) if (reach[i]){
 		double LO = P + 2.0 * i;
 		double HI = P + 2.0 * dp[i];
 		if (HI <= m) ret = max(ret, HI);
 		if (LO <= m && HI >= m) ret = max(ret, m*1.);
 	}
 	
 	
 	printf("%.9f\n", ret);
}return 0;}