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

int M;
int G[100];
int R[100][2];
int answer;
unordered_set<uint32_t> memo;

void dfs(int M, int g[8]) {
    uint32_t state = 0;
    REP(i, M) state = (state << 4) | (uint32_t)g[i];
    if(memo.count(state)) {
        return;
    }
    memo.insert(state);
    answer = max(answer, g[0]);

    int res = g[0];
    for(int u = 0; u < M; u++) {
        int a = R[u][0];
        int b = R[u][1];
        if (u == a || u == b) continue;
        if(g[a] > 0 && g[b] > 0) {
            int ng[8];
            REP(i, M) ng[i] = g[i];
            ng[a]--;
            ng[b]--;
            ng[u]++;
            dfs(M, ng);
        }
    }
}

void solve() {
    cin >> M;
    REP(i, M) {
        cin >> R[i][0] >> R[i][1];
        R[i][0]--; R[i][1]--;
    }
    REP(i, M) cin >> G[i];
    int max_g = 0;
    REP(i, M) max_g = max(max_g, G[i]);

    if (M <= 8 && max_g <= 8) {
        int g[8];
        REP(i, M) g[i] = G[i];
        memo.clear();
        answer = 0;
        dfs(M, g);
        cout << answer << endl;
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
