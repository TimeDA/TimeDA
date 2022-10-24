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
 
 const int N = 55*55*4;
 
 struct CONJ2{
 	int n, ed, m, sz, t;
 	int l[N], qd[N*10], qn[N*10], v[N], w[N], stk[N], act[N], scc[N];
 
 	void init(int x){
 		n = x * 2, ed = 0;
 		for (int i=0; i<n; i++) l[i] = 0;
 		CLR(v,0); CLR(w,0); CLR(stk,0), CLR(act,0), CLR(scc,0);
 	}
 	void add(int x, int w, int y, int z){
 		x = x * 2 + w;
 		y = y * 2 + z;
 		qd[++ed] = y;
 		qn[ed] = l[x];
 		l[x] = ed;
 	}
 	void dfs(int x){
 		v[x] = w[x] = ++t;
 		stk[++sz] = x, act[x] = 1;
 
 		for (int i=l[x]; i; i=qn[i]){
 			if (!v[qd[i]]) dfs(qd[i]), w[x] = min(w[x], w[qd[i]]);
 			else if (act[qd[i]]) w[x] = min(w[x], v[qd[i]]);
 		}
 
 		if (v[x] == w[x]){
 			m++;
 			do{
 				scc[stk[sz]] = m;
 				act[stk[sz]] = 0;
 			}   while (stk[sz--] != x);
 		}
 	}
 	void trace(int x, int sol[]){
 		act[x] = 1;
 		for (int i=l[x]; i; i=qn[i]) if (!act[qd[i]]) trace(qd[i], sol);
 		if (sol[x>>1] == -1) sol[x>>1] = x & 1;
 	}
 	int solve(int sol[]){
 		m = sz = t = 0;
 		for (int i=0; i<n; i++) v[i] = 0, sol[i>>1] = -1;
 		for (int i=0; i<n; i++) if (!v[i]) dfs(i);
 		for (int i=0; i<n; i+=2) if (scc[i] == scc[i+1]) return 0;
 		for (int i=0; i<n; i++) if (!act[i]) trace(i, sol);
 		return 1;
 	}
 }	S;
 
 int n, m, res;
 char s[55][55];
 int var[55*55], cov[55][55][2], sol[N];
 int lbl[55][55];
 
 /*
 	- : false
 	| : true
 */
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	RI(n), RI(m);
 	CLR(lbl, 0);
 	CLR(s, 0);
 	res = 0;
 	FOR(i,0,n) scanf("%s", s[i]);
 	
 	int var = 0;
 	FOR(i,0,n) FOR(j,0,m) if (s[i][j] == '-' || s[i][j] == '|'){
 		s[i][j] = 'X';
 		lbl[i][j] = var;
 		++var;
 	}
 	
 	S.init(var);
 	CLR(cov, -1);
 	
 	
 	FOR(i,0,n) FOR(j,0,m) if (s[i][j] == 'X'){
 		
   		for (int k=j-1; k>=0; k--){
 			if (s[i][k] == 'X'){
 				S.add(lbl[i][j], 0, lbl[i][j], 1);
 				break;
 			}
 			if (s[i][k] == '#') break;
 			if (cov[i][k][0] != -1) cov[i][k][0] = -2;
 			else if (cov[i][k][0] != -2) cov[i][k][0] = lbl[i][j];
 		}
 		
 		for (int k=j+1; k<m; k++){
 			if (s[i][k] == 'X'){
 				S.add(lbl[i][j], 0, lbl[i][j], 1);
 				break;
 			}
 			if (s[i][k] == '#') break;
 			if (cov[i][k][0] != -1) cov[i][k][0] = -2;
 			else if (cov[i][k][0] != -2) cov[i][k][0] = lbl[i][j];
 		}
 		
 
 		for (int k=i-1; k>=0; k--){
 			if (s[k][j] == 'X'){
 				S.add(lbl[i][j], 1, lbl[i][j], 0);
 				break;
 			}
 			if (s[k][j] == '#') break;
 			if (cov[k][j][1] != -1) cov[k][j][1] = -2;
 			else if (cov[k][j][1] != -2) cov[k][j][1] = lbl[i][j];
 		}
 		
 		for (int k=i+1; k<n; k++){
 			if (s[k][j] == 'X'){
 				S.add(lbl[i][j], 1, lbl[i][j], 0);
 				break;
 			}
 			if (s[k][j] == '#') break;
 			if (cov[k][j][1] != -1) cov[k][j][1] = -2;
 			else if (cov[k][j][1] != -2) cov[k][j][1] = lbl[i][j];
 		}
 	}
 	
 	
 	FOR(i,0,n) FOR(j,0,m) if (s[i][j] == '.'){
 		if (cov[i][j][0] < 0 && cov[i][j][1] < 0) goto DOOM;
 		if (cov[i][j][0] >= 0 && cov[i][j][1] >= 0){
 			S.add(cov[i][j][0], 1, cov[i][j][1], 1);
 			S.add(cov[i][j][1], 0, cov[i][j][0], 0);
 		}
 		else if (cov[i][j][0] >= 0){
 			S.add(cov[i][j][0], 1, cov[i][j][0], 0);
 		}
 		else if (cov[i][j][1] >= 0){
 			S.add(cov[i][j][1], 0, cov[i][j][1], 1);
 		}
 	}
 	res = S.solve(sol);
 	if (!res) goto DOOM;
 
 	FOR(i,0,n) FOR(j,0,m) if (s[i][j] == 'X'){
 		if (!sol[lbl[i][j]]) s[i][j] = '-';
 		else s[i][j] = '|';
 	}
 	puts(" POSSIBLE");
 	FOR(i,0,n) printf("%s\n", s[i]);
 
 	continue;
 	DOOM:
 	puts(" IMPOSSIBLE");
 }return 0;}
