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
 
 const int N = 105;
 int n, m;
 int a[N], b[N], u[N];
 LLD G[N][N];
 double v[N];
 
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
 	RI(n), RI(m);
 	FOR(i,0,n) RI(a[i]), RI(b[i]);
 	
 	FOR(i,0,n) FOR(j,0,n) scanf("%lld", &G[i][j]);
 	FOR(i,0,n) G[i][i] = 0;
 	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) if (G[i][k] != -1 && G[k][j] != -1){
 		LLD D = G[i][k] + G[k][j];
 		if (G[i][j] == -1) G[i][j] = D;
 		else G[i][j] = min(G[i][j], D);
 	}
 	
 	while (m--){
 		int x, y;
 		RI(x), RI(y); x--, y--;
 		FOR(i,0,n) v[i] = 1e90, u[i] = 0;
 		v[x] = 0;
 		
 		FOR(itr,0,n-1){
 			int s = -1;
 			double mn = 1e90;
 			FOR(i,0,n) if (!u[i] && v[i] < mn){
 				mn = v[i];
 				s = i;
 			}
 			if (s == -1) break;
 			u[s] = 1;
 			FOR(j,0,n) if (G[s][j] > 0 && G[s][j] <= a[s]){
 				v[j] = min(v[j], v[s] + G[s][j] * 1. / b[s]);
 			}
 		}
 		printf(" %.9f", v[y]);
 	}
 	puts("");
 
 
 
 
 }return 0;}
