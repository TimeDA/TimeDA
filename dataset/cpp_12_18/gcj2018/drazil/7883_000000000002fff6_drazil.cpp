#include <bits/stdc++.h>

using namespace std;

long long r, b, c;
long long m[1100], s[1100], p[1100];
long long pick;
long long mt[1100];

bool ok(long long t) {
    for (int i = 0; i < c; ++i) {
        mt[i] = max(0LL, min(m[i], (t - p[i]) / s[i]));
    }
    sort(mt, mt + c);
    long long sb = 0;
    for (int i = 0; i < pick; ++i) {
        sb += mt[c - i - 1];
    }
    return (sb >= b);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%lld%lld%lld", &r, &b, &c);
        long long L = 0, R = 0;
        for (int i = 0; i < c; ++i) {
            scanf("%lld%lld%lld", &m[i], &s[i], &p[i]);
            R = max(R, m[i] * s[i] + p[i]);
        }
        pick = min(r, c);
        while (L + 1 < R) {
            long long m = (L + R) / 2;
            if (ok(m)) R = m;
            else L = m;
        }
        printf("Case #%d: %lld\n", t, R);
    }

    return 0;
}
