#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 110;
int a[MAXN];
int maxr;
char ans[MAXN][MAXN];
int n;

void myput(int s, int t) {
	if (s == t) return;
	if (s < t) {
		int r = 0;
		for (int i = s ; i < t ; ++i) {
			ans[r++][i] = '\\';
			if (r > maxr) maxr = r;
		}
		return;
	}
	if (s > t) {
		int r = 0;
		for (int i = s ; i > t ; --i) {
			ans[r++][i] = '/';
			if (r > maxr) maxr = r;
		}
	}
	return;
}

bool check() {
	for (int j = 0 ; j < maxr ; ++j)
		if (ans[j][0] != '.' || ans[j][n-1] != '.') return false;
	return true;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		memset(ans, '.', sizeof(ans));

		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&a[i]);

		maxr = 0;
		for (int i = 0 ; i < n ; ++i) {
			int tsum = 0;
			for (int j = 0 ; j < n ; ++j) {
				tsum += a[j];
				if (tsum >= i+1) {
					myput(i, j);
					break;
				}
			}
		}

		printf("Case #%d: ", ca);
		if (!check()) {
			printf("IMPOSSIBLE\n");
			continue;
		} else {
			++maxr;
			printf("%d\n", maxr);
			for (int i = 0 ; i < maxr ; ++i) {
 				for (int j = 0 ; j < n ; ++j)
					printf("%c", ans[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
	
}