#include <cstdio>
#include <algorithm>
using namespace std;


typedef long long llong;
const llong inf = 1e10;

void solve(int cs) {
    int n;
    scanf("%d", &n);
    llong mnx = inf, mxx = -inf, mny = inf, mxy = -inf;
    for (int i = 0; i < n; i++) {
        llong x, y;
        scanf("%lld %lld", &x, &y);
        mxx = max(mxx, x);
        mnx = min(mnx, x);
        mxy = max(mxy, y);
        mny = min(mny, y);
    }
    llong ans = max((mxx - mnx + 1) / 2, (mxy - mny + 1) / 2);
    printf("Case #%d: %lld\n", cs, ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
