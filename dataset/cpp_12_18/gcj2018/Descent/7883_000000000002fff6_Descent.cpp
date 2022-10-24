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

const int N = 1005;
int n, tot, m, a[N], b[N], c[N], p[N];
LLD INF = 1LL<<62;

int solve(LLD T){
	FOR(i,0,m){
		if (c[i] > T) p[i] = 0;
		else p[i] = min((LLD)a[i], (T-c[i])/b[i]);
	}
	sort(p, p+m); reverse(p, p+m);
	LLD sum = 0;
	FOR(i,0,n) sum += p[i];
	return sum >= (LLD)tot;
}

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n), RI(tot), RI(m);
	FOR(i,0,m) RI(a[i]), RI(b[i]), RI(c[i]);
	LLD ret = INF;
	for (LLD lo=0, hi=INF, mid; hi>=lo;){
		mid = lo + (hi-lo)/2;
		if (solve(mid)) ret = mid, hi = mid - 1;
		else lo = mid+1;
	}
	printf("%lld\n", ret);
}return 0;}