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
 
 int dx[] = {-1, 0, 1, 0};
 int dy[] = {0, 1, 0, -1};
 char dir[] = {'^', '>', 'v', '<'};
 int n, m;
 char a[105][105];
 
 void solve(int tc){
 	int ret = 0;
 	scanf("%d%d", &n, &m);
 	FOR(i,0,n) scanf("%s", a[i]);
 	printf("Case #%d: ", tc);	
 	
 	FOR(i,0,n) FOR(j,0,m) if (a[i][j] != '.'){
 		int d;
 		FOR(k,0,4) if (a[i][j] == dir[k]) d = k;
 		int x = i, y = j, f = 0;
 		while (1){
 			x += dx[d], y += dy[d];
 			if (x < 0 || y < 0 || x >= n || y >= m){
 				f = 1;
 				break;
 			}
 			if (a[x][y] != '.') break;
 		}
 		if (!f) continue;
 		
 		int ok = 0;
 		FOR(k,0,4){
 			x = i, y = j;
 			f = 0;
 			while (1){
 				x += dx[k], y += dy[k];
 				if (x < 0 || y < 0 || x >= n || y >= m) break;
 				if (a[x][y] != '.'){
 					ok = 1;
 					break;
 				}
 			}
 			if (ok) break;		
 		}
 		
 		if (!ok){
 			puts("IMPOSSIBLE");
 			return;
 		}
 		++ret;
 	}
 	printf("%d\n", ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
 
