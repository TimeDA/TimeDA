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
string s[110];
int g[110][110];
int sn;
int sm;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m >> sn >> sm;
		for (int i = 0; i < n; i++) cin >> s[i];
		memset (g, 0, sizeof (g));
		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--)
				g[i][j] = g[i + 1][j] + g[i][j + 1] - g[i + 1][j + 1] + int (s[i][j] == '@');
		vi wi, wj;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '@') {
					wi.pb (i);
					wj.pb (j);
				}
		sort (all (wi));
		sort (all (wj));
		int cnt = (sn + 1) * (sm + 1);
		int ok = 1;
		if (sz (wi) != 0) {
			if (sz (wi) % cnt != 0) ok = 0; else {
				vi ri, rj;
				int di = sz (wi) / (sn + 1);
				ri.pb (0);
				for (int i = 0; i < sn; i++)
					if (wi[di * (i + 1) - 1] == wi[di * (i + 1)]) {
						ok = 0;
						break;
					} else ri.pb (wi[di * (i + 1) - 1] + 1);
				ri.pb (n);
				int dj = sz (wj) / (sm + 1);
				rj.pb (0);
				for (int i = 0; i < sm; i++)
					if (wj[dj * (i + 1) - 1] == wj[dj * (i + 1)]) {
						ok = 0;
						break;
					} else rj.pb (wj[dj * (i + 1) - 1] + 1);
				rj.pb (m);
				int one = sz (wi) / cnt;
				for (int i = 0; i < sn + 1 && ok; i++)
					for (int j = 0; j < sm + 1 && ok; j++) {
						int cur = g[ri[i]][rj[j]] - g[ri[i + 1]][rj[j]] - g[ri[i]][rj[j + 1]] + g[ri[i + 1]][rj[j + 1]];
//						cout << ri[i] << " " << rj[j] << " " << ri[i + 1] << " " << rj[j + 1] << endl;
//						cout << cur << " " << g[ri[i + 1]][rj[j]] << endl;
						if (cur != one) {
							ok = 0;
							break;
						}
					}
			}
		}
		cout.precision (20);
		cout << "Case #" << it << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE");
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}