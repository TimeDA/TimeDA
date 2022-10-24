#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000100;
const int INF = 1e9;
int S;
int d[MAXN], a[MAXN], b[MAXN];

int main() {
	int T, ca;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d", &S);
		for (int i = 0 ; i < S ; ++i) {
			scanf("%d%d%d",&d[i],&a[i],&b[i]);
		}
		int best = 0, cnt = 0;
		for (int i = 0 ; i < S ; ++i) {
			int v1 = d[i] + a[i];
			int v2 = INF;
			int j;
			for (j = i+1 ; j < S ; ++j) {
				// case 1, left
				if (d[j]+a[j] == v1 || d[j]-b[j] == v2)
					continue;
				if (v2 == INF) {
					v2 = d[j]-b[j];
				} else break;
			}
			int tmpj = j;
			if (j - i > best) {best = j - i; cnt = 1; /*printf("(%d,%d)\n", i, j-1);*/}
			else if (j - i == best) {++cnt; /*printf("(%d,%d)\n", i, j-1);*/}

			v1 = INF;
			v2 = d[i] - b[i];
			for (j = i + 1 ; j < S ; ++j) {
				if (d[j] + a[j] == v1 || d[j] - b[j] == v2)
					continue;
				if (v1 == INF) v1 = d[j] + a[j];
				else break;
			}
			if (j <= tmpj) continue;
			if (j - i > best) {best = j - i; cnt = 1; /*printf("(%d,%d)\n", i, j-1); */}
			else if (j - i == best) {++cnt; /*printf("(%d,%d)\n", i, j-1);*/}
		}
		printf("Case #%d: %d %d\n", ca, best, cnt);
	}
	return 0;
}