#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

const int maxn = 1000111;
const int NONE = 1000111000;

int n, a[maxn], b[maxn], na[maxn], nb[maxn], pa[maxn], pb[maxn];

struct Solution {
    int len, cnt;
    vector<tuple<int, int, int>> opt;

    Solution() { len = cnt = 0; }

    void update(const Solution& s) {
        update(s.len, s.cnt);
    }

    void update(int nl, int nc) {
        if (nl > len) {
            len = nl;
            cnt = nc;
        } else if (nl == len) {
            cnt += nc;
        }
    }
};

bool eq(int a, int b) {
    return a == NONE || b == NONE || a == b;
}

bool compatible(const tuple<int, int, int>& a,
                const tuple<int, int, int>& b) {
    return eq(get<0>(a), get<0>(b)) && eq(get<1>(a), get<1>(b));
}

Solution solve(int L, int R, bool fromRight) {
    if (L == R) {
        Solution res;
        res.len = 1;
        res.cnt = 1;
        res.opt.emplace_back(a[L], NONE, 1);
        res.opt.emplace_back(NONE, b[L], 1);
        res.opt.emplace_back(a[L], b[L], 1);
        return res;
    }

    int M = (L + R) / 2;
    Solution sl = solve(L, M, 1);
    Solution sr = solve(M + 1, R, 0);

    Solution res;
    res.update(sl);
    res.update(sr);

    int cl = 0;
    set<pair<int, int>> ss;
    for (const auto& opl : sl.opt)
        for (const auto& opr : sr.opt)
            if (compatible(opl, opr)) {
                int leftL = get<2>(opl);
                int rightL = get<2>(opr);
                if (leftL + rightL > cl) {
                    ss.clear();
                    cl = leftL + rightL;
                }
                if (leftL + rightL == cl) {
                    ss.emplace(leftL, rightL);
                }
            }

    res.update(cl, ss.size());

    if (fromRight) {
        res.opt.emplace_back(a[R], NONE, min(R - L + 1, pa[R]));
        res.opt.emplace_back(NONE, b[R], min(R - L + 1, pb[R]));

        if (R - pa[R] >= L) {
            int pr = R - pa[R];
            res.opt.emplace_back(a[R], b[pr], min(R - L + 1, pa[R] + pb[pr]));
        }
        if (R - pb[R] >= L) {
            int pr = R - pb[R];
            res.opt.emplace_back(a[pr], b[R], min(R - L + 1, pb[R] + pa[pr]));
        }
    } else {
        res.opt.emplace_back(a[L], NONE, min(R - L + 1, na[L]));
        res.opt.emplace_back(NONE, b[L], min(R - L + 1, nb[L]));

        if (L + na[L] <= R) {
            int nl = L + na[L];
            res.opt.emplace_back(a[L], b[nl], min(R - L + 1, na[L] + nb[nl]));
        }
        if (L + nb[L] <= R) {
            int nl = L + nb[L];
            res.opt.emplace_back(a[nl], b[L], min(R - L + 1, nb[L] + na[nl]));
        }
    }
/*
    printf("=====================\n");
    printf("Solution for [%d %d], fromRight: %d\n", L, R, fromRight);
    printf("  best in: %d %d\n", res.len, res.cnt);
    printf("  opts:\n");
    for (const auto& o : res.opt)
        printf("    (%d %d): %d\n", get<0>(o), get<1>(o), get<2>(o));
*/
    return res;
}

void solve() {
    int q, w, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &q, &w, &e);
        a[i] = q + w;
        b[i] = q - e;
        //printf("> %d %d\n", a[i], b[i]);
    }

    int ans = 0;
    set<pair<int, int>> ss;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int cur = 0;
            for (int k = 0; k < n; k++) {
                if (a[k] == a[i] || b[k] == b[j]) cur++;
                else cur = 0;
                if (cur > ans) {
                    ans = cur;
                    ss.clear();
                }
                if (cur == ans) ss.emplace(k - cur + 1, k);
            }
            if (cur > ans) {
                ans = cur;
                ss.clear();
            }
            if (cur == ans) ss.emplace(n - 1 - cur + 1, n - 1);
        }

    printf("%d %d\n", ans, (int)ss.size());
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
