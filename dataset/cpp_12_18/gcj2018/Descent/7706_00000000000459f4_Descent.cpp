#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

int n, m, v[22][22], cnt, cnt2;
int a[22][22], b[22][22], A[111][111];
char s[111];

void dfs(int x, int y){
	if (v[x][y] || !b[x][y]) return;
	v[x][y] = 1;
	++cnt2;
	if (x > 0) dfs(x-1, y);
	if (y > 0) dfs(x, y-1);
	if (x < n-1) dfs(x+1, y);
	if (y < m-1) dfs(x, y+1);
}

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);

	RI(n), RI(m);
	FOR(i,0,n){
		scanf("%s", s);
		FOR(j,0,m) a[i][j] = (s[j] == 'B');
	}
	
	int ret = 1;
	
	FOR(bit,1,(1<<(n*m))){
		cnt = 0, cnt2 = 0;
		int t = 0, si, sj;
		FOR(i,0,n) FOR(j,0,m){
			v[i][j] = 0;
			if (bit & (1<<t)){
   			   b[i][j] = 1;
   			   si = i;
   			   sj = j;
   			   ++cnt;
   			}
			else b[i][j] = 0;
			t++;
		}
		
		if (cnt <= ret) continue;
		
		// check conn
		dfs(si, sj);
		if (cnt2 != cnt) continue;
		
		// check pat
		
		FOR(i,0,n*3) FOR(j,0,m*4) A[i][j] = a[i/3][j/4];
		FOR(i,0,n*3) FOR(j,0,m*4){
			int ok = 1;
			
			FOR(k,0,n) FOR(l,0,m) if (b[k][l]) {
			   	if (i + k >= n*3 || j + l >= m*4 || a[k][l] != A[i+k][j+l]) ok = 0;
			}
			if (ok){
				ret = max(ret, cnt);
				goto DONE;
			}
		}
		DONE:;
	}

	printf("%d\n", ret);

}return 0;}