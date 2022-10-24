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

const ld pi = 2 * asinl (1.0);
const ld eps = 1e-12;

int n;
int m;

ld ang[10000];
ld a1[10000];
ld a2[10000];

ld calc (ld a, ld b) {
    if (a > b + eps) re b - a + 2 * pi;
    re b - a;
}

bool ls (pair<ld, int> a, pair<ld, int> b) {
    re a.fi < b.fi - eps || (abs (a.fi - b.fi) < eps && a.se > b.se);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
            ang[i] = atan2l ((ld)(y2 - y1), (ld)(x2 - x1));
            a1[i] = atan2l ((ld)(0 - y1), (ld)(0 - x1));
            a2[i] = atan2l ((ld)(1000 - y1), (ld)(0 - x1));
//            if (calc (a1[i], a2[i]) > pi) swap (a1[i], a2[i]);
//             printf ("%.15f\n%.15f\n%.15f\n", (double)a1[i], (double)a2[i], (double)ang[i]);
        }
        int cnt = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<pair<ld, int> > v;
            for (int i = 0; i < n; i++)
                if ((mask >> i) & 1) {
                    ld b1 = calc (ang[i], a1[i]);
                    ld b2 = calc (ang[i], a2[i]);
                    if (calc (b1, b2) > pi) swap (b1, b2);
//                    printf ("%.15f %.15f\n", (double)b1, (double)b2);
                    if (abs (b1 - b2) < eps || abs (b1 - b2) > 2 * pi - eps) continue;
                    if (b1 < b2) {
                        v.pb (mp (b1, 1));
                        v.pb (mp (b2, -1));
                    } else {
                        if (b1 < 2 * pi - eps) {
                            v.pb (mp (b1, 1));
                            v.pb (mp (2 * pi, -1));
                        }
                        if (b2 > eps) {
                            v.pb (mp (b2, -1));
                            v.pb (mp (0, 1));
                        }
                    }
                } else {
                    ld b1 = calc (a1[i], ang[i]);
                    ld b2 = calc (a2[i], ang[i]);
                    if (calc (b1, b2) > pi) swap (b1, b2);
//                    printf ("%.10f %.10f\n", (double)b1, (double)b2);
                    if (abs (b1 - b2) < eps || abs (b1 - b2) > 2 * pi - eps) continue;
                    if (b1 < b2) {
                        v.pb (mp (b1, 1));
                        v.pb (mp (b2, -1));
                    } else {
                        if (b1 < 2 * pi - eps) {
                            v.pb (mp (b1, 1));
                            v.pb (mp (2 * pi, -1));
                        }
                        if (b2 > eps) {
                            v.pb (mp (0, 1));
                            v.pb (mp (b2, -1));
                        }
                    }
                }
            v.pb (mp (0, 0));
            v.pb (mp (2 * pi, 0));
//            printf ("%d\n", mask);
            for (int i = 0; i < sz (v); i++) {
                while (v[i].fi < -eps) v[i].fi += 2 * pi;
                while (v[i].fi > 2 * pi + eps) v[i].fi -= 2 * pi;
            }
            sort (all (v), ls);
//            for (int i = 0; i < sz (v); i++) printf ("%.5f %d\n", (double)v[i].fi, v[i].se);
            int cur = 0;
            int ok = 0;
            for (int i = 0; i + 1 < sz (v); i++) {
                cur += v[i].se;
                if (cur == 0) {
                    ok = 1;
                    break;
                }
            }
            cnt += ok;
        }
        cout.precision (20);
		cout << "Case #" << it << ": ";
        printf ("%.10f\n", (double)cnt / (1 << n));
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
