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
 
 int n, m, x, y;
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	RI(m), RI(n);
 	double T = 0;
 	FOR(i,0,n){
 		RI(x), RI(y);
 		T = max(T, (m-x) * 1. / y);
 	}
 	printf(" %.9f\n", m / T);
 }return 0;}
