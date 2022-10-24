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

int done, cnt, a[222][222], tot, m;

void doit(int x, int y){
	if (done) return;
	printf("%d %d\n", x, y);
	fflush(stdout);
	int xx, yy;
	RI(xx), RI(yy);
	if (!xx && !yy) done = 1;
	a[xx][yy] = 1;
}

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){
	RI(m);
	CLR(a, 0);
	done = cnt = tot = 0;
	while (!done){
		FOE(i,1,15) FOE(j,1,15) if (!a[i][j]){
			int x = i, y = j;
			if (x == 1) ++x;
			if (x == 15) --x;
			if (y == 1) ++y;
			if (y == 15) --y;
			doit(x, y);
		}
	}
}return 0;}