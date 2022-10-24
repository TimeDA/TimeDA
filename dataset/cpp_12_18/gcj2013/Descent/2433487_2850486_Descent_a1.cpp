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
 LLD m, a[40], bet[40];
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%lld%d", &m, &n);
 	CLR(a, 0);
 	FOR(i,0,n) scanf("%lld", &a[i]);
 	sort(a, a + 37);
 	double ret = 0;
 	
 	FOE(i,1,37){
 		FOR(j,0,37) bet[j] = a[j];
 		LLD x = bet[i-1], R = m, T = 0;
 		FOR(j,0,i) R -= x - bet[j], T += x - bet[j];
 		FOR(j,i,37) if (bet[j] <= x){
 			R -= x + 1 - bet[j];
 			bet[j] = x + 1;
 		}
 		if (R < 0) break;
 		ret = max(ret, 36. * T / i - (m - R));
 		
 		while (R >= i){
 			R -= i;
 			T += i;
 			++x;
 			FOR(j,i,37) while (bet[j] <= x){
 				++bet[j];
 				--R;
 			}
 			if (R >= 0) ret = max(ret, 36. * T / i - (m - R));
 		}
 	}
 	
 	printf("%.9f\n", ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
