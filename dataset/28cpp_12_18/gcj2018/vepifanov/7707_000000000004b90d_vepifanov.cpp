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

const ll base = 1000*1000*1000;

struct lll {
	ll a, b, c;
	lll () {
		a = b = c = 0;
	}
	lll (ll x) {	
		a = 0;
		b = x / base;
		c = x % base;
	}
};

lll operator* (lll x, lll y) {
	lll z;
	z.a = x.a * y.c + x.b * y.b + x.c * y.a;
	z.b = x.b * y.c + x.c * y.b;
	z.c = x.c * y.c;
	z.b += z.c / base;
	z.c %= base;
	z.a += z.b / base;
	z.b %= base;
	re z;
}

bool operator< (lll x, lll y) {
	re x.a < y.a || (x.a == y.a && x.b < y.b) || (x.a == y.a && x.b == y.b && x.c < y.c);
}

int n;
int m;
int x[1000];
int y[1000];
int z[1000];
int used[1000];
int q[1000];
int res[1000];

ll det (ll a11, ll a12, ll a13, ll a21, ll a22, ll a23, ll a31, ll a32, ll a33) {
	re a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 - 
	   a11 * a23 * a32 - a12 * a21 * a33 - a13 * a22 * a31;
}

int below (int a, int b, int c, int d, ll up) {
	ll cur = det (x[b] - x[a], y[b] - y[a], z[b] - z[a], x[c] - x[a], y[c] - y[a], z[c] - z[a], x[d] - x[a], y[d] - y[a], z[d] - z[a]);
	re int ((cur > 0 && up < 0) || (cur < 0 && up > 0));
}

int below (int a, int b, int c, int d) {
	ll up = det (x[b] - x[a], y[b] - y[a], z[b] - z[a], x[c] - x[a], y[c] - y[a], z[c] - z[a], 0, 0, 1);
	ll cur = det (x[b] - x[a], y[b] - y[a], z[b] - z[a], x[c] - x[a], y[c] - y[a], z[c] - z[a], x[d] - x[a], y[d] - y[a], z[d] - z[a]);
	re int ((cur > 0 && up < 0) || (cur < 0 && up > 0));
}

ll dist (ll x1, ll y1, ll x2, ll y2) {
	re (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool ls (pair<ll, ll> a, pair<ll, ll> b) {
	lll c = a.fi;
	c = c * b.se;
	lll d = b.fi;
	d = d * a.se;
	re c < d;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		int top = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d%d%d", &x[i], &y[i], &z[i]);
			if (z[i] > z[top]) top = i;
		}
		int top2 = -1, top3 = -1;
		pair<ll, ll> best (0, 0);
		for (int i = 0; i < n; i++)
			if (top != i) {
				pair<ll, ll> cur ((ll)(z[top] - z[i]) * ((z[top] - z[i])), dist (x[top], y[top], x[i], y[i]));
				if (top2 == -1 || ls (cur, best)) {
					top2 = i;
					best = cur;
				}
			}
		for (int i = 0; i < n; i++)
			if (i != top && i != top2) {
				int ok = 1;
				ll up = det (x[top2] - x[top], y[top2] - y[top], z[top2] - z[top], x[i] - x[top], y[i] - y[top], z[i] - z[top], 0, 0, 1);
				for (int j = 0; j < n && ok; j++) {
					if (j == top || j == top2 || j == i) continue;
					if (!below (top, top2, i, j, up)) {
						ok = 0;
						break;
					}
				}	
				if (ok) {
					top3 = i;
					break;
				}
			}
		assert (top != -1 && top2 != -1 && top3 != -1);
		assert (top != top2 && top != top3 && top2 != top3);
		int a = top, b = top2, c = top3;
		memset (used, 0, sizeof (used));
		int o = 0;
		for (int i = 0; i < n; i++)
			if (i != a && i != b && i != c)
				q[o++] = i;
		for (int i = 0; i < n - 3; i++) {
			res[i] = c;
			used[c] = 1;
			c = b;
			b = a;
			a = -1;
			for (int ii = 0; ii < o; ii++) {
				int i = q[ii];
				int ok = 1;
				ll up = det (x[b] - x[i], y[b] - y[i], z[b] - z[i], x[c] - x[i], y[c] - y[i], z[c] - z[i], 0, 0, 1);
				for (int jj = 0; jj < o && ok; jj++) {
					int j = q[jj];
					if (j == i) continue;
					if (!(below (i, b, c, j, up))) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					a = i;
					swap (q[ii], q[o - 1]);
					o--;
					break;
				}
			}
			assert (a != -1);
		}	
		res[n - 1] = a;
		res[n - 2] = b;
		res[n - 3] = c;
		reverse (res, res + n);
		cout.precision (20);
		cout << "Case #" << it << ": ";
		for (int i = 0; i < n; i++) {
			printf ("%d ", res[i] + 1);
//			for (int j = 0; j <= i - 3; j++)
//				assert (below (res[i], res[i - 1], res[i - 2], res[j]));
		}
		printf ("\n");
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}