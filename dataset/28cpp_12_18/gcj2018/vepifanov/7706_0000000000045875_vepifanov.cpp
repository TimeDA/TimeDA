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
vi v[100];
int p[100];
int g[100][100];
int was[100];

int go (int x) {
	if (x == -1) re 1;
	if (was[x]) re 0;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++)
		if (go (p[v[x][i]])) {
			p[v[x][i]] = x;
			re 1;
		}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &g[i][j]);
		int ans = 0;
		for (int t = -n; t <= n; t++) {
			for (int i = 0; i < n; i++) {
				v[i].clear ();
				p[i] = -1;
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (g[i][j] == t)
						v[i].pb (j);
			for (int i = 0; i < n; i++) {
				memset (was, 0, sizeof (was));
				ans += go (i);
			}
		}
		cout << "Case #" << it << ": " << n * n - ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}