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

const int N = 105;
int n, m, nn, mm, S;
int R[N], C[N], a[N][N], lr[N], lc[N], p[N][N];;
char s[N];

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n), RI(m), RI(nn), RI(mm);
	S = 0;
	CLR(R, 0); CLR(C, 0);
	
	FOR(i,0,n){
		scanf("%s", s);
		FOR(j,0,m){
		   a[i][j] = (s[j] == '@');
		   R[i] += a[i][j];
		   C[j] += a[i][j];
		}
		S += R[i];
	}
	
	if (S == 0) goto SUCC;
	if (S % ((nn+1)*(mm+1)) != 0) goto FAIL;
	{
	int t = S / (nn+1);
	int sum = 0, cur = 0;
	FOR(i,0,n){
		sum += R[i];
		lr[i] = cur;
		if (sum > t) goto FAIL;
		if (sum == t) sum = 0, ++cur;
	}
	
	t = S / (mm+1);
	sum = cur = 0;
	FOR(i,0,m){
		sum += C[i];
		lc[i] = cur;
		if (sum > t) goto FAIL;
		if (sum == t) sum = 0, ++cur;
	}
	
	CLR(p, 0);
	FOR(i,0,n) FOR(j,0,m) if (a[i][j]){
		p[ lr[i] ] [ lc[j] ]++;
	}
	
	t = S / (nn+1) / (mm+1);
	FOE(i,0,nn) FOE(j,0,mm) if (p[i][j] != t) goto FAIL;
	}
	
	SUCC: puts("POSSIBLE"); continue;
	FAIL: puts("IMPOSSIBLE");
}return 0;}