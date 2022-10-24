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

const int N = 1000;

int n;
int m;
int xx[N];
int yy[N];
vector<pair<ii, int> > v[N];
vii w[N];
int o;
map<ii, int> num;
vi res;
int was[N];
int used[N];
int ea[N];
int eb[N];
int ec[N];
int ed[N];
int q[N];

int get (int x, int y) {
	if (num.count (mp (x, y))) re num[mp (x, y)];
	v[o].clear ();
	xx[o] = x;
	yy[o] = y;
	num[mp (x, y)] = o++;
	re o - 1;
}                   

int go (int x, int z) {
	if (was[x]) re 0;
	if (x == z) re 1;
//	printf ("%d %d\n", x, z);
	was[x] = 1;
	for (int i = 0; i < sz (w[x]); i++) {
		ii y = w[x][i];
		if (used[y.se]) continue;
//		printf ("+%d\n", y.se);
		used[y.se] = 1;
		if (go (y.fi, z)) re 1;
//		printf ("-%d\n", y.se);
		used[y.se] = 0;
	}
	re 0;
}

int go2 (int x) {
	if (was[x]) re 0;
	was[x] = 1;
	for (int i = 0; i < sz (w[x]); i++) {
		ii y = w[x][i];
		if (used[y.se]) continue;
		used[y.se] = 2;
		go2 (y.fi);
		res.pb (y.se);
	}
	re 0;
}

int sgn (ii c) {
	if (c.se > 0 || (c.se == 0 && c.fi > 0)) re 1;
	re -1;
}

ll vect (int x1, int y1, int x2, int y2) {
	re (ll)x1 * y2 - (ll)x2 * y1;
}

bool ls (pair<ii, int> a, pair<ii, int> b) {
	if (sgn (a.fi) != sgn (b.fi)) re sgn (a.fi) < sgn (b.fi);
	re vect (a.fi.fi, a.fi.se, b.fi.fi, b.fi.se) >= 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
		o = 0;
		num.clear ();
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
			int a = get (x1, y1);
			int b = get (x2, y2);
//			printf ("%d %d\n", a, b);
			v[a].pb (mp (mp (x2 - x1, y2 - y1), 2 * i));
			v[b].pb (mp (mp (x1 - x2, y1 - y2), 2 * i + 1));
			ea[2 * i] = a;
			eb[2 * i] = b;
			ea[2 * i + 1] = b;
			eb[2 * i + 1] = a;
		}
		for (int i = 0; i < o; i++) {
			sort (all (v[i]), ls);
			v[i].pb (v[i][0]);
			for (int j = 0; j + 1 < sz (v[i]); j++) ec[v[i][j].se ^ 1] = v[i][j + 1].se;
		}
		memset (was, 0, sizeof (was));
		int r = 0;
		for (int i = 0; i < 2 * n; i++)
			if (!was[i]) {
				int j = i;
				while (true) {
					if (was[j]) break;
					was[j] = 1;
					ed[j] = r;
					j = ec[j];
				}
				r++;
			}
		for (int i = 0; i < r; i++) w[i].clear ();
		for (int i = 0; i < 2 * n; i++) {
//			printf ("%d -> %d = %d\n", ed[i], ed[i ^ 1], i / 2);
			w[ed[i]].pb (mp (ed[i ^ 1], i / 2));
		}
		for (int i = 0; i < m; i++) q[i] = i;
		int ok = 1;
		res.clear ();
		for (int a = 0; a < 2 && ok; a++)
			for (int b = 0; b < 2 && ok; b++) {
				memset (was, 0, sizeof (was));
				memset (used, 0, sizeof (used));
				used[q[0]] = used[q[1]] = 1;
				if (go (ed[2 * q[0] + a], ed[2 * q[1] + b])) {
//					printf ("%d - %d\n", ed[2 * q[0] + a], ed[2 * q[0] + (a ^ 1)]);
/*					for (int i = 0; i < n; i++)
						if (used[i])
							printf ("%d\n", i);*/
					used[q[0]] = 0;
					memset (was, 0, sizeof (was));
					go2 (ed[2 * q[0] + a]);
//					printf ("%d\n", sz (res));
					ok = 0;
					for (int i = 0; i < n; i++)
						if (used[i] == 1) {
							used[i] = 0;
//							printf ("%d %d\n", ed[2 * i], ed[2 * i + 1]);
						}
					memset (was, 0, sizeof (was));
					go2 (ed[2 * q[0] + a]);
					break;
				}
			}
//		if (ok) while (true);
		assert (!ok);
		cout.precision (20);
		cout << "Case #" << it << ": ";
		for (int i = 0; i < n; i++) cout << res[i] + 1 << " ";
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}