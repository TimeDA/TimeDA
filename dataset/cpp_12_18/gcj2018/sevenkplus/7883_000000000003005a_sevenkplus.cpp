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
int n, m, A, B;
string a[N];
int sx[N], sy[N];
int cx[N], cy[N];
int ss[N][N];

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m >> A >> B;
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		memset(sx, 0, sizeof sx);
		memset(sy, 0, sizeof sy);
		for (int i = 0; i < n; i ++) {
			int s = 0;
			for (int j = 0; j < m; j ++)
				if (a[i][j] == '@') s++;
			sx[i+1] = sx[i] + s;
		}
		for (int j = 0; j < m; j ++) {
			int s = 0;
			for (int i = 0; i < n; i ++)
				if (a[i][j] == '@') s++;
			sy[j+1] = sy[j] + s;
		}
		memset(ss, 0, sizeof ss);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) {
				ss[i+1][j+1] = ss[i+1][j] + ss[i][j+1] - ss[i][j] + (a[i][j] == '@');
			}
		bool F = true;
		if (sx[n]%((A+1)*(B+1)) != 0) F = false;
		if (F && sx[n] != 0) {
			memset(cx, -1, sizeof cx);
			memset(cy, -1, sizeof cy);
			int nn = sx[n]/(A+1);
			for (int i = 1; i <= n; i ++)
				if (sx[i]%nn == 0) cx[sx[i]/nn] = i;
			int mm = sy[m]/(B+1);
			for (int i = 1; i <= m; i ++)
				if (sy[i]%mm == 0) cy[sy[i]/mm] = i;
			cx[0] = cy[0] = 0;
			for (int i = 1; i <= A+1; i ++)
				if (cx[i] == -1) F = false;
			for (int i = 1; i <= B+1; i ++)
				if (cy[i] == -1) F = false;
			if (F) {
				int p = sx[n]/((A+1)*(B+1));
				for (int i = 0; i < A+1; i ++)
					for (int j = 0; j < B+1; j ++) {
						int s = ss[cx[i+1]][cy[j+1]] - ss[cx[i]][cy[j+1]] - ss[cx[i+1]][cy[j]] + ss[cx[i]][cy[j]];
						if (s != p) F = false;
					}
			}
		}
		printf ("Case #%d: ", __);
		if (F) puts ("POSSIBLE");
		else puts ("IMPOSSIBLE");
	}
	return 0;
}
