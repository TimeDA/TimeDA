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
 
 int n, m, a[105];
 char s[105][105], v[105][105][4];
 
 int trans(int w, int &x, int &y, int &z){
 	if (w <= m) x = 0, y = w-1, z = 0;
 	else if (w <= m+n) x = w-m-1, y = m-1, z = 1;
 	else if (w <= m+n+m) x = n-1, y = m-(w-n-m), z = 2;
 	else x = n-(w-n-m-m), y = 0, z = 3;
 }
 
 int pr1[] = {3, 2, 1, 0};
 int pr2[] = {1, 0, 3, 2};
 
 void dfs(int x, int y, int d){
 	if (x < 0 || y < 0 || x >= n || y >= m) return;
 	if (v[x][y][d]) return;
 	v[x][y][d] = 1;
 	
 	if (s[x][y] == '/') dfs(x, y, pr1[d]);
 	if (s[x][y] == '\\') dfs(x, y, pr2[d]);
 	
 	if (d == 0) dfs(x-1, y, 2);
 	if (d == 1) dfs(x, y+1, 3);
 	if (d == 2) dfs(x+1, y, 0);
 	if (d == 3) dfs(x, y-1, 1);
 }
 
 int route(int a1, int a2, int a3, int b1, int b2, int b3){
 	CLR(v, 0);
 	dfs(a1, a2, a3);
 	return v[b1][b2][b3];
 }
 
 int route(int a, int b){
 	int a1, a2, a3, b1, b2, b3;
 	trans(a, a1, a2, a3);
 	trans(b, b1, b2, b3);
 //	printf("%d %d %d %d %d %d [%d,%d]\n",a1,a2,a3,b1,b2,b3,a,b);
 	return route(a1, a2, a3, b1, b2, b3);
 }
 
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:\n", TC);
 	RI(n), RI(m);
 	FOR(i,0,2*(n+m)) RI(a[i]);
 	
 	FOR(i,0,(1<<(n*m))){
 		int t = 0;
 		FOR(j,0,n) { s[j][m] = 0; FOR(k,0,m) s[j][k] = ((i & (1<<t)) ? '/' : '\\'), t++; }
 		int ok = 1;
 	//FOR(j,0,n) printf("%s\n", s[j]);
 		for (int j=0; j<2*(n+m)&&ok; j+=2) ok &= route(a[j], a[j+1]);
 		if (ok){
 			FOR(j,0,n) printf("%s\n", s[j]);
 			goto DONE;
 		}
 	}
 
 	puts("IMPOSSIBLE");
 	DONE:;
 }return 0;}
