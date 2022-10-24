#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110
#define M 250
const db eps = 1e-8;
db f[N][N*M+5];
int n, P;
int a[N], b[N];

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> P;
		for (int i = 0; i < n; i ++) cin >> a[i] >> b[i];
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= i*M; j ++)
				f[i][j] = -1.0;
		f[0][0] = 0;
		for (int i = 0; i < n; i ++) {
			int mi = min(a[i], b[i]);
			db ma = sqrt(a[i]*a[i]+b[i]*b[i]);
			for (int j = 0; j <= i*M; j ++) if (f[i][j] > -eps) {
				// not add
				f[i+1][j] = max(f[i+1][j], f[i][j]);
				// add
				f[i+1][j+mi] = max(f[i][j+mi], f[i][j]+ma);
			}
		}
		// original
		int S0 = 0;
		for (int i = 0; i < n; i ++)
			S0 += 2*(a[i]+b[i]);
		db S = S0;
		for (int i = 0; i <= n*M; i ++) if (f[n][i] > -eps)
			if (S0 + i*2 <= P)
				S = max(S, min((db)P, S0+f[n][i]*2));
		printf ("Case #%d: %.9lf\n", __, S);
	}
	return 0;
}
