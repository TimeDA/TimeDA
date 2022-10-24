#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

const int B = 5;
const ll M = (1 << B) - 1;

unordered_map<ll, int> mm;
int n, fa[10], fb[10];

int get(ll v, int i) {
    return (v >> (B * i)) & M;
}

void set(ll& v, int i, int x) {
    v |= M << (B * i);
    v ^= (M ^ x) << (B * i);
}

int get(ll v) {
    if (mm.count(v)) return mm[v];
    int res = v & M;

    for (int i = 0; i < n; i++) {
        if (fa[i] != 0 && fb[i] != 0 && fa[i] != i && fb[i] != i) {
            int qa = get(v, fa[i]);
            int qb = get(v, fb[i]);
            if (qa && qb) {
                ll nv = v;
                set(nv, fa[i], qa - 1);
                set(nv, fb[i], qb - 1);
                set(nv, i, get(v, i) + 1);
                int z = get(nv);
                if (z > res) res = z;
                if (i == 0) break;
            }
        }
    }

    mm[v] = res;
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &fa[i], &fb[i]);
        fa[i]--;
        fb[i]--;
    }
/*
    nr = 0;
    for (int i = 0; i < n; i++) {
        if (fa[i] != 0 && fb[i] != 0 && fa[i] != i && fb[i] != i) {
            fa[nr] = fa[i];
            fb[nr] = fb[i];
            nr++;
        }
    }
*/
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    ll x = 0;
    for (int i = 0; i < n; i++) set(x, i, v[i]);

    mm.clear();
    printf("%d\n", get(x));
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
