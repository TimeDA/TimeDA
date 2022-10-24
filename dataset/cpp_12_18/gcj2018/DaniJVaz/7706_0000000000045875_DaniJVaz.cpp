#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int getbit(ll mask, int bit) {
	return 1&(mask >> bit);
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		int i, j;

		scanf("%d", &n);
		int matrix[n][n];
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				scanf("%d", &matrix[i][j]);
		
		ll maskLim = 1 << (n*n);
		int minC = n*n;

		for (ll mask=0; mask<maskLim; mask++) {
			int c = 0;
			for (i=0; i<n; i++) {
				if (c < 0)
					break;
				for (j=0; j<n; j++) {
					if (c < 0)
						break;

					if (getbit(mask, i*n+j)) {
						c++;
						continue;
					}

					for (int ii = 0; ii < n; ii++) {
						if (ii == i)
							continue;
						if (getbit(mask, ii*n+j))
							continue;
						if (matrix[i][j] == matrix[ii][j])
							c = -1;
					}

					for (int jj = 0; jj < n; jj++) {
						if (jj == j)
							continue;
						if (getbit(mask, i*n+jj))
							continue;
						if (matrix[i][j] == matrix[i][jj])
							c = -1;
					}
				}
			}

			if (c >= 0)
				minC = min(minC, c);
		}

		printf("Case #%d: %d\n", iC, minC);
	}
	return 0;
}