#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

void solve_dp(int N, int L) {
    vector<int> C(L);
    REP(i, L) cin >> C[i];
    vector<int> mods(N + 1);
    const int unit = 100 % N;
    for(int i = 1; i <= N; i++) {
        mods[i] = (mods[i-1] + unit);
        if (mods[i] >= N) mods[i] -= N;
    }

    const int MAX_N = 300;
    int dp[MAX_N] = {};
    const int INF = 1e9;
    REP(i, MAX_N) dp[i] = -INF;
    dp[0] = 0;

    auto score = [&](int use) {
        int m = mods[use];
        if (2 * m >= N) {
            return N - m;
        } else {
            return -m;
        }
    };
    for(int i = 0; i <= N; i++) {
        int ndp[MAX_N] = {};
        REP(i, MAX_N) ndp[i] = -INF;
        int init = (i < C.size() ? C[i] : 0);
        for(int c = 0; c <= N; c++) {
            for(int use = init; use + c <= N; use++) {
                ndp[use + c] = max(ndp[use + c], dp[c] + score(use));
            }
        }
        for(int c = 0; c <= N; c++) {
            dp[c] = ndp[c];
        }
    }

    int ans_mod = dp[N];
    #ifdef LOCAL
    assert(abs(ans_mod) % N == 0);
    #endif
    int answer = 100 + ans_mod / N;
    cout << answer << endl;
}


void solve() {
    int N, L;
    cin >> N >> L;
    if (N < 300) {
        solve_dp(N, L);
    } else {
        assert(false);
    }
}

int main(){
    iostream_init();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
