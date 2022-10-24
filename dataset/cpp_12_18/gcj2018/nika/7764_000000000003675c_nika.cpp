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
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[101], b[101];
ll g[101], d[101][101], c[101], v[101];

int go(int x) {
    if (c[x] >= 0) return 1;
    v[x] = 1;

    if (v[a[x]]) return 0;
    if (v[b[x]]) return 0;

    c[a[x]] += c[x];
    c[b[x]] += c[x];
    c[x] = 0;
    if (!go(a[x])) return 0;
    if (!go(b[x])) return 0;

    v[x] = 0;
    return 1;
}

ll ok(ll x) {
    F1(i, n) c[i] = g[i];
    c[1] -= x;

    CL(0, v);
    return go(1);
}

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> n;
        F1(i, n) cin >> a[i] >> b[i];
        F1(i, n) cin >> g[i];

        ll P = 0, Q = 1e18;
        while (P < Q) {
            ll R = (P + Q + 1) / 2;
            if (ok(R)) P = R; else Q = R - 1;
        }

        printf("Case #%d: ", tt);
        cout << P << endl;
    }
    return 0;
}
