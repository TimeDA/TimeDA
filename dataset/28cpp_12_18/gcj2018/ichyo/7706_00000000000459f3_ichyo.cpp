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

const int MAX_N = 505;
const int MAX_S = 50;
int dp[MAX_N][MAX_N];
void init() {
    set<pair<int, int>> cand;
    REP(i, MAX_N) if(i != 0) cand.insert(make_pair(0, i));
    REP(i, MAX_N) if(i != 0) cand.insert(make_pair(i, 0));
    REP(i, MAX_S) REP(j, MAX_S) if(i + j != 0) cand.insert(make_pair(i, j));
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(auto p : cand) {
        const int A = p.first;
        const int B = p.second;
        for(int i = MAX_N - A - 1; i >= 0; i--) {
            for(int j = MAX_N - B - 1; j >= 0; j--) {
                if (dp[i][j] != -1) {
                    dp[i + A][j + B] = max(dp[i + A][j + B], dp[i][j] + 1);
                }
            }
        }
    }
    //REP(i, MAX_N) REP(j, MAX_N) assert(dp[i][j] != -1);
    //long long sum = 0;
    //REP(i, MAX_N) REP(j, MAX_N) sum += (long long)dp[i][j] * i * j;
    //cerr << sum << endl;
}

void solve() {
    int R, B;
    cin >> R >> B;
    cout << dp[R][B] << endl;
}

int main(){
    iostream_init();
    init();
    int TC;
    cin >> TC;
    for(int testcase = 1; testcase <= TC; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
