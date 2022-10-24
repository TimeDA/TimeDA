#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 110;
int n;
int a[MAXN][MAXN];

int row[MAXN][MAXN*2];
int col[MAXN][MAXN*2];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j)
				scanf("%d",&a[i][j]);

		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				++row[i][a[i][j]+n];
				++col[j][a[i][j]+n];
			}
		}

		int ans = 0;
		while (1) {
			int ma = -100, mi = -1, mj = -1;
			for (int i = 0 ; i < n ; ++i)
				for (int j = 0 ; j < n ; ++j)
					if (row[i][a[i][j]+n] > 1 || col[j][a[i][j]+n] > 1) {
						int tmp = row[i][a[i][j]+n] + col[j][a[i][j]+n] - 2;
						if (tmp > ma) {
							ma = tmp;
							mi = i; mj = j;
						}
					}
			if (ma == -100) break;
			--row[mi][a[mi][mj]+n];
			--col[mj][a[mi][mj]+n];
			++ans;
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}