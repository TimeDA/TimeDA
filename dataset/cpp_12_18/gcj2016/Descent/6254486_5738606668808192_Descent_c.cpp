#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <string>
 #include <set>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, m, np, ok, crt[66], b[55], P[1000005];
 char p[10000005]; set<string> S; char s[100];
 
 void bla(){
 	int n = 30000;
 	for (int i=2; i<=n; i++) p[i] = 1;
 	for (int i=2; i<=n; i++){
 		for (int j=i+i; p[i] && j<=n; j+=i) p[j] = 0;
 		if (p[i]) P[np++] = i;
 	}
 }
 
 int mod(int bse, int n, int P){
 	int res = 0, B = 1;
 	FOD(i,n,0){
 		if (b[i]) res = (res + B) % P;
 		B = B * bse % P;
 	}
 	return res;
 }
 
 int main(){ bla();	int tc;	scanf("%d", &tc); FOE(TC,1,tc){ printf("Case #%d:\n", TC);
 	scanf("%d%d", &n, &m);
 	FOR(i,0,m){
 		RE_DO:
 		FOR(j,0,n) b[j] = rand() % 2;
 		b[0] = b[n-1] = 1;
 		FOR(j,0,n) s[j] = b[j] + '0'; s[n] = 0;
 		if (S.find((string)s) != S.end()) goto RE_DO;
 		S.insert((string)s);
 		ok = 1;
 		FOE(j,2,10){
 			ok = 0;
 			FOR(k,0,np){
 				if (mod(j, n, P[k]) == 0){
 					crt[j] = P[k];
 					ok = 1;
 					goto OK_PT;
 				}
 			}
 			if (!ok) goto RE_DO;
 			OK_PT:;
 		}
 		FOR(j,0,n) printf("%d", b[j]);
 		FOR(j,2,11) printf(" %d", crt[j]); puts("");
 	}
 
 }	return 0;	}
