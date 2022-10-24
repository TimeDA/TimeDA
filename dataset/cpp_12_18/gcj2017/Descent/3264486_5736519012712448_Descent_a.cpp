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
 
 int m;
 int a[1005];
 char s[1005];
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
 	scanf("%s", s);
 	RI(m);
 	int n = strlen(s), ok = 1, ret = 0;
 	FOR(i,0,n) a[i] = (s[i] == '-');
 	FOR(i,0,n){
 		if (a[i]){
 			if (i + m > n) ok = 0;
 			else{
 				FOR(j,0,m) a[i+j] ^= 1;
 				++ret;
 			}
 		}
 	}
 	if (ok) printf("%d\n", ret);
 	else puts("IMPOSSIBLE");
 }return 0;}
