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

const ll inf = 2e18;

const int N = 1500;
const int M = 2 * (15 + N + 15 * N);

int n;
int m;
int k;

vii v[N];
int was[N];
int prev[N];
int preve[N];
int q[N];
ll ec[M];
ll eco[M];
int o, e;
int x[15];
int y[15];
int d[15];
int red[15];
int cool[32][32];
ll sum;

int addedge (int a, int b, ll c) {
//    printf ("%d %d %lld\n", a, b, c);
    v[a].pb (mp (b, e));
    ec[e] = c;
    eco[e] = c;
    e++;
    v[b].pb (mp (a, e));
    ec[e] = 0;
    eco[e] = 0;
    e++;
    re e - 2;
}

int ct;

int go (int S, int T, ll h) {
    ct++;
    int l = 0, r = 1;
    q[0] = S;
    was[S] = ct;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se;
            if (ec[z] < h || was[y] == ct) continue;
            was[y] = ct;
            prev[y] = x;
            preve[y] = z;
            q[r++] = y;
        }
        if (was[T] == ct) re 1;
    }
    re 0;
}

int can (ll H) {
    for (int i = 0; i < e; i++) ec[i] = eco[i];
    for (int i = 0; i < k; i++) ec[red[i]] = H;
    ll cur = 0;
    for (ll h = (ll)1 << 60; h > 0; h /= 2)
        while (go (o - 2, o - 1, h)) {
            cur += h;
            int j = o - 1;
            while (j != o - 2) {
                int pe = preve[j];
                int pj = prev[j];
                ec[pe] -= h;
                ec[pe ^ 1] += h;
                j = pj;
            }
        }
    if (cur == sum) re 1;
    re 0;    
}

int can (ll H, ll up) {
    for (int i = 0; i < e; i++) ec[i] = eco[i];
    for (int i = 0; i < k; i++) ec[red[i]] = H;
    ll cur = 0;
    for (ll h = (ll)1 << 60; h > 0; h /= 2)
        while (go (o - 2, o - 1, h)) {
            cur += h;
            int j = o - 1;
            while (j != o - 2) {
                int pe = preve[j];
                int pj = prev[j];
                ec[pe] -= h;
                ec[pe ^ 1] += h;
                j = pj;
            }
        }
//    cout << H << " " << up << " " << cur << endl;
//    for (int i = 0; i < k; i++) cout << ec[red[i] ^ 1] << " ";
//    cout << "ec" << endl;
    if (cur % k != 0 || cur / k != H) re 0;
    for (int i = 0; i < k; i++) {
        ec[red[i]] = up - H;
        ec[red[i] ^ 1] = 0;
    }
    for (ll h = (ll)1 << 60; h > 0; h /= 2)
        while (go (o - 2, o - 1, h)) {
            cur += h;
            int j = o - 1;
            while (j != o - 2) {
                int pe = preve[j];
                int pj = prev[j];
                ec[pe] -= h;
                ec[pe ^ 1] += h;
                j = pj;
            }
        }
    if (cur == sum) re 1;
    re 0;    
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
        scanf ("%d%d%d", &n, &m, &k);
        vi vx, vy;
        vx.pb (0);
        vx.pb (n);
        vy.pb (0);
        vy.pb (m);
        for (int i = 0; i < k; i++) {
            scanf ("%d%d%d", &x[i], &y[i], &d[i]); x[i]--; y[i]--;
            vx.pb (max (0, x[i] - d[i]));
            vx.pb (min (n, x[i] + d[i] + 1));
            vy.pb (max (0, y[i] - d[i]));
            vy.pb (min (m, y[i] + d[i] + 1));
        }
        sort (all (vx));
        sort (all (vy));
        vx.resize (unique (all (vx)) - vx.begin ());
        vy.resize (unique (all (vy)) - vy.begin ());
        int rx = sz (vx) - 1;
        int ry = sz (vy) - 1;
        e = 0;
        o = 2 + k + rx * ry;
        for (int i = 0; i < o; i++) v[i].clear ();
        memset (cool, 0, sizeof (cool));
        for (int i = 0; i < k; i++) {
            red[i] = addedge (o - 2, i, inf);
            for (int a = 0; a < rx; a++)
                for (int b = 0; b < ry; b++)
                    if (abs (vx[a] - x[i]) <= d[i] && abs (vy[b] - y[i]) <= d[i]) {
                        addedge (i, k + (a * ry + b), inf);                        
                        cool[a][b] = 1;
                    }
        }
        sum = 0;
        for (int a = 0; a < rx; a++)
            for (int b = 0; b < ry; b++)
                if (cool[a][b]) {
                    ll tmp = (ll)(vx[a + 1] - vx[a]) * (vy[b + 1] - vy[b]);
                    for (int i = 0; i < k; i++)
                        if (x[i] >= vx[a] && x[i] < vx[a + 1] && y[i] >= vy[b] && y[i] < vy[b + 1])
                            tmp--;
                    sum += tmp;
                    addedge (k + (a * ry + b), o - 1, tmp);
                }
        ll l = 0, r = 1e18;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (can (s)) r = s; else l = s;
        }
        if (can (l)) r = l;
        ll up = r;
        l = 0, r = up + 1;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (can (s, up)) l = s; else r = s;
        }
        can (l, up);
        cout.precision (20);
		cout << "Case #" << it << ": " << up - l << endl;
//        for (int i = 0; i < n; i++) cout << ec[red[i] ^ 1] + l << " ";
//		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
