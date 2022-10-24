#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 #define N 1005
 using namespace std;
 
 int tc, n, m, as, cs, rs, am, cm, rm, cnt;
 int S[N], M[N], l[N], qn[N], v[N];
 
 void dfs(int x){
 	++cnt;
 	EXP(i,l[x]) if (!v[i]) dfs(i);
 }
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%d%d", &n, &m);
 	scanf("%d%d%d%d", &S[0], &as, &cs, &rs);
 	scanf("%d%d%d%d", &M[0], &am, &cm, &rm);
 	CLR(l, 0);
 	FOR(i,1,n){
 		S[i] = (S[i-1] * as + cs) % rs;
 		M[i] = (M[i-1] * am + cm) % rm;
 		qn[i] = l[M[i] % i];
 		l[M[i] % i] = i;
 	}
 	
 	int ret = 1;
 	FOR(i,0,n) if (S[0] >= S[i] && S[i] + m >= S[0]){
 		FOR(j,0,n){
 			v[j] = 0;
 			if (S[j] < S[i] || S[j] > S[i] + m) v[j] = 1;
 		}
 		cnt = 0;
 		dfs(0);
 		ret = max(ret, cnt);
 	//	printf("%d %d\n", M[i], cnt);
 	}
 	printf("%d\n", ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
