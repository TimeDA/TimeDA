#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
ii q[400];
string s[20];
int was[20][20];
int g[20][20];
int cool[16];
          
int good (int i, int j, int a, int b, int mask) {
	re int (g[i][j] == ((mask >> (int (i >= a) + 2 * int (j >= b))) & 1));
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++)
				g[i][j] = int (s[i][j] == 'B');
		}
		int ans = 0;
		memset (cool, 0, sizeof (cool));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cool[15 * g[i][j]] = 1;
				if (i + 1 < n) cool[5 * g[i][j] + 10 * g[i + 1][j]] = 1;
				if (j + 1 < m) cool[3 * g[i][j] + 12 * g[i][j + 1]] = 1;
				if (i + 1 < n && j + 1 < m) cool[g[i][j] + 2 * g[i + 1][j] + 4 * g[i][j + 1] + 8 * g[i + 1][j + 1]] = 1;
			}
		for (int mask = 0; mask < 16; mask++) {
			if (!cool[mask]) continue;
			for (int a = 0; a <= n; a++)
				for (int b = 0; b <= m; b++) {
					memset (was, 0, sizeof (was));
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++)
							if (!good (i, j, a, b, mask))
								was[i][j] = 1;
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++)
							if (!was[i][j]) {
								int l = 0, r = 1;
								was[i][j] = 1;
								q[0] = mp (i, j);
								while (l < r) {
									ii p = q[l++];
									for (int t = 0; t < 4; t++) {
										int ni = p.fi - int (t == 0) + int (t == 1);
										int nj = p.se - int (t == 2) + int (t == 3);
										if (ni < 0 || nj < 0 || ni >= n || nj >= m || was[ni][nj]) continue;
										was[ni][nj] = 1;
										q[r++] = mp (ni, nj);
									}
								}
//								printf ("%d %d = %d\n", a, b, r);
								if (r > ans) {
									ans = r;
								}
							}
				}
		}
		cout << "Case #" << it << ": " << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}