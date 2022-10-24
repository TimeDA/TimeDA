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

#define N 500
int f[N+5][N+5][40];
int g[N+5][N+5][40];

int main() {
	memset(f, 0, sizeof f);
	for (int i = 0; i <= 35; i ++) {
		memcpy(g, f, sizeof g);
		for (int j = 35; j >= 0; j--) {
			int nn = i*j;
			int mm = j*(j-1)/2;
			for (int i1 = 0; i1+nn <= N; i1 ++)
				for (int j1 = 0; j1+mm <= N; j1 ++)
					f[i1+nn][j1+mm][j] = max(f[i1+nn][j1+mm][j], g[i1][j1][j]+j);
		}
		for (int i1 = 0; i1 <= N; i1 ++)
			for (int j1 = 0; j1 <= N; j1 ++)
				for (int k = 34; k >= 0; k --)
					f[i1][j1][k] = max(f[i1][j1][k], f[i1][j1][k+1]);
	}
	
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n, m;
		cin >> n >> m;
		printf ("Case #%d: %d\n", __, f[n][m][0]-1);
	}
	return 0;
}
