#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 510;
int vis[MAXN][MAXN];
int a, b;
int best;

void solve(int a, int b, int p, int cnt) {
	// printf("(a=%d,b=%d,p=%d)\n", a, b, p);
	if (cnt > best) best = cnt;
	if (a < p) return;
	int tmp = 0;
	for (int i = 0 ; ; ++i) {
		if (a - p >= 0 && b - i >= 0) {
			a -= p;
			b -= i;
			++tmp;
			solve(a, b, p+1, cnt+tmp);
		} else break;
	}
}

int cnt[36][MAXN][MAXN];

void init() {
	memset(cnt, -1, sizeof(cnt));
	cnt[0][0][0] = 0;
	for (int r = 0 ; r < 35 ; ++r) {
		for (int sa = 0 ; sa < MAXN ; ++sa)
			for (int sb = 0 ; sb < MAXN ; ++sb)
				if (cnt[r+1][sa][sb] < cnt[r][sa][sb])
					cnt[r+1][sa][sb] = cnt[r][sa][sb];
		int ta = 0, tb = 0;
		for (int i = 0 ; i < 35 ; ++i) {
			ta += r;
			tb += i;
			for (int sa = 0 ; ta + sa < MAXN ; ++sa)
				for (int sb = 0 ; tb + sb < MAXN ; ++sb) {
					if (cnt[r][sa][sb] < 0) continue;
					if (cnt[r+1][ta+sa][tb+sb] < cnt[r][sa][sb] + i + 1)
						cnt[r+1][ta+sa][tb+sb] = cnt[r][sa][sb] + i + 1;
				}
		}
	}
}

int main() {
	init();
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d",&a,&b);
		int best = 0;
		for (int r = 0 ; r < 35 ; ++r)
			for (int i = 0 ; i <= a ; ++i)
				for (int j = 0 ; j <= b ; ++j)
					if (cnt[r][i][j] > best) best = cnt[r][i][j];
		printf("Case #%d: %d\n", ca, best-1);
		
	}
	return 0;
}