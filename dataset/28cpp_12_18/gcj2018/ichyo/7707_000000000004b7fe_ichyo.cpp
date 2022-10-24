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

bool is_ok(const vector<pair<LL, LL>>& PS, LL d) {
    LL min_r = INT_MIN;
    LL max_r = INT_MAX;
    LL min_c = INT_MIN;
    LL max_c = INT_MAX;
    for(auto p : PS) {
        min_r = max(min_r, p.first - d);
        max_r = min(max_r, p.first + d);
        min_c = max(min_c, p.second - d);
        max_c = min(max_c, p.second + d);
    }
    return min_r <= max_r && min_c <= max_c;
}

void solve() {
    int N;
    cin >> N;
    vector<pair<LL, LL>> PS(N);
    REP(i, N) cin >> PS[i].first >> PS[i].second;

    LL ok = INT_MAX;
    LL ng = -1;
    while (abs(ok - ng) > 1) {
        LL mid = (ok + ng) / 2;
        if (is_ok(PS, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}

int main(){
    iostream_init();
    int TEST;
    cin >> TEST;
    for(int t = 1; t <= TEST; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
