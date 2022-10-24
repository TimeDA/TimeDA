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
 #define N 2005
 using namespace std;
 
 int n, m, C, x, y, ret1;
 int a[1005][1005];
 int f[N], v[N], l[N], list[N], qd[N*N], qn[N*N], ed;
 
 void bd(int x, int y){
 	qd[++ed] = y, qn[ed] = l[x], l[x] = ed;
 }
 
 int dfs(int x){
 	for (int i=l[x]; i; i=qn[i]) if (!v[qd[i]]){
 		v[qd[i]] = 1;
 		if (f[qd[i]] == -1 || dfs(f[qd[i]])){
 			f[qd[i]] = x;
 			return 1;
 		}
 	}
 	return 0;
 }
 
 
 int BM(int n){
 	int ret = 0;
 	memset(f, -1, sizeof(f));
 	for (int i=0; i<n; i++){
 		memset(v, 0, sizeof(v));
 		ret += dfs(i);
 	}
 	return ret;
 }
 
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	CLR(a,0);
 	RI(n),RI(C),RI(m);
 	FOR(i,0,m){ RI(x),RI(y); ++a[y-1][x]; }
 int a00,a10,a01=0,a11=0;
 	{
 		
 		a00 = a[0][1], a10 = a[1][1];
 		FOE(i,2,n) a01 += a[0][i], a11 += a[1][i];
 		if (a11 >= a00 || a01 >= a10) ret1=max(a00+a01, a10+a11);
 		else ret1=max(a00+a01, a00+a10);
 	}
 	
 	int t = 0, tt = 0;
 	ed = 0;
 	CLR(l, 0);
 	FOE(i,2,n) FOR(j,0,a[1][i]) list[++t] = i;
 	
 	FOE(i,2,n){
 		FOR(j,0,a[0][i]){
 			FOE(k,1,t) if (i != list[k]) bd(tt, k);
 			++tt;
 		}
 	}
 
 	int MM = BM(tt), ret2;
 		if (a11 >= a00 || a01 >= a10){
 			int gap = min( a11-a00, a01-a10  );
 			
 			ret2 = max(0, gap - MM);
 		}
 		else ret2=0;
 	
 	printf(" %d %d\n", ret1, ret2);
 
 }return 0;}
