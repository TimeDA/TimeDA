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

int n, a[111];
char res[222][111];

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n);
	FOR(i,0,n) RI(a[i]);
	if (!a[0] || !a[n-1]){
		puts("IMPOSSIBLE");
		continue;
	}
	
	FOR(i,0,n+n){
		FOR(j,0,n) res[i][j] = '.';
		res[i][n] = 0;
	}
	
	int t = 0, mx = 0;
	FOR(i,0,n) if (a[i] > 0){
		int lo = t, hi = t + a[i] - 1;
		
		if (lo == 0){
			for (int k=hi; k>=1; k--) res[hi-k][k] = '/';
			mx = max(mx, hi);
		}
		else{
			
			if (i < lo){
				for (int k=hi, t=0; k>i; k--, t++){
					res[t][k] = '/';
					mx = max(mx, t+1);
				}
			}
			else if (i > hi){
				for (int k=lo, t=0; k<i; k++, t++){
					res[t][k] = '\\';
					mx = max(mx, t+1);
				}
			}
			else{
				for (int k=lo, t=0; k<i; k++, t++){
					res[t][k] = '\\';
					mx = max(mx, t+1);
				}
				for (int k=hi, t=0; k>i; k--, t++){
					res[t][k] = '/';
					mx = max(mx, t+1);
				}
			}
		}
		t += a[i];
	}

	printf("%d\n", mx+1);
	
	FOR(i,0,mx+1) printf("%s\n", res[i]);
}return 0;}