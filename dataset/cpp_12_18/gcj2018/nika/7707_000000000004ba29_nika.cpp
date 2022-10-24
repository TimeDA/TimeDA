#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define P(x) cerr << #x << "=" << x << endl

const ll inf = 1e18;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

const int N = 100000;
int i, j, k, m, n, l, r, c, pw;
int x[N], y[N];

vector< vector<int> > f, g;

int a[55][55], edges, deg[55], d[55][55], e[55][55];

int ok() {
    if (edges != 2 * n) return 0;
    F0(i, n) if (deg[i] != 4) return 0;
    return 1;
}

void change() {
    while (1) {
        int i = rand()%n;
        int j = rand()%n;
        if (i == j) continue;

        if (edges >= 2 * n - 2 && a[i][j]) {
            a[i][j] = 0;
            a[j][i] = 0;
            deg[i]--;
            deg[j]--;
            edges--;
            return;
        } else if (edges < 2 * n && !a[i][j] && deg[i] < 4 && deg[j] < 4) {
            a[i][j] = a[j][i] = 1;
            deg[i]++;
            deg[j]++;
            edges++;
            return;
        }
    }
}

int eval() {
    F0(i, n) F0(j, n) d[i][j] = a[i][j];
    for (pw = 1; pw <= 10; pw++) {
        CL(0, e);
        F0(i, n) F0(j, n) F0(k, n)  {
            e[i][j] += d[i][k] * a[k][j];
        }
        F0(i, n) F0(j, n) d[i][j] = e[i][j];
        f.resize(n);
        F0(i, n) {
            f[i].resize(n);
            F0(j, n) f[i][j] = d[i][j];
            sort(f[i].begin(), f[i].end());
        }
        int anyeq = 0;
        F0(i, n) F0(j, i) if (f[i] == f[j]) anyeq = 1;
        if (!anyeq) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    CL(0, a);
    CL(0, deg);
    edges = 0;

    int its = 0;
    while (1) {
        change();
        while (!ok()) {
            its++;
            change();
        }
        if (eval()) break;
    }

    cout << n << endl;
    F0(i, n) F0(j, n) if (a[i][j] && i < j) {
        cout << i + 1 << " " << j + 1 << endl;
    }

    CL(0, a);
    g = f;
    int savepw = pw;
    cin >> n;
    F0(k, 2 * n) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        a[i][j] = a[j][i] = 1;
    }
    if (!eval()) {
        cerr << "no eval" << endl;
        throw 12;
    }
    if (pw != savepw) throw 12;

    int printed = 0;
    F0(i, n) F0(j, n) {
        if (g[i] == f[j]) {
            printed++;
            cout << j + 1 << " ";
        }
    }
    if (printed != n) throw 12;
    cout << endl;
}

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> m >> n;
        if (m == -1) break;
        n = rand()%(n - m + 1) + m;
        solve();
    }
    return 0;
}
