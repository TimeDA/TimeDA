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
 
 
 int n, p;
 LLD T, N;
 char s[111];
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
 	scanf("%s", s);
 	n = strlen(s);
 	sscanf(s, "%lld", &N);
 	p = 0;
 	FOR(i,0,n){
 		while (p <= 8){
 			FOR(j,i,n) s[j] = p + 1 + '0';
 			sscanf(s, "%lld", &T);
 			if (T > N) break;
 			++p;
 		}
 		s[i] = p + '0';
 	}
 	sscanf(s, "%lld", &T);
 	printf("%lld\n", T);
 }return 0;}
