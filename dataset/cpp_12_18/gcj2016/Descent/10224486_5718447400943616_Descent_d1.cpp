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
 
 int n, ok, p[66], v[66], xx[666], yy[666], m;
 char s[66][66];
 
 void dfs(int x){
 	if (x == n) return;
 	int oc = 0;
 	FOR(i,0,n) if (s[p[x]][i] == '1' && !v[i]){
 		oc = 1;
 		v[i] = 1;
 		dfs(x+1);
 		v[i] = 0;
 	}
 	if (!oc) ok = 0;
 }
 
 int check(){
 	FOR(i,0,n) p[i] = i;
 	do{
 		FOR(j,0,n) v[j] = 0;
 		ok = 1;
 		dfs(0);
 		if (ok == 0) return 0;
 	}   while (next_permutation(p, p+n));
 	return 1;
 }
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	RI(n);
 	FOR(i,0,n) scanf("%s", s[i]);
 	
 	int m = 0;
 	FOR(i,0,n) FOR(j,0,n) if (s[i][j] == '0'){
 		xx[m] = i, yy[m] = j;
 		++m;
 	}
 	int ret = m;
 	FOR(i,0,1<<m){
 		FOR(j,0,m) s[xx[j]][yy[j]] = (i & (1<<j)) ? '1' : '0';
 		if (check()) ret = min(ret, __builtin_popcount(i));
 	}
 	printf(" %d\n", ret);
 }return 0;}
