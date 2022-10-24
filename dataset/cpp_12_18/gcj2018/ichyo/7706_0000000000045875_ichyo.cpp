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

struct BipartiteMatching{
    typedef vector<int> Node;
    typedef vector<Node> Graph;

    Graph G;
    vector<int> match;
    vector<bool> used;

    BipartiteMatching(int N) : G(N) {}

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int u){
        used[u] = true;
        for(int v : G[u]){
            int w = match[v];
            if(w < 0 || (!used[w] && dfs(w))){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int matching(){
        int res = 0;
        match.assign(G.size(), -1);
        for(int u = 0; u < G.size(); u++){
            if(match[u] < 0){
                used.assign(G.size(), false);
                if(dfs(u)) res++;
            }
        }
        return res;
    }
};

void solve() {
    int N;
    cin >> N;
    const int MAX_N = 105;
    int A[MAX_N][MAX_N];
    REP(i, N) REP(j, N) cin >> A[i][j];

    map<int, vector<pair<int, int>>> s;
    REP(i, N) REP(j, N) s[A[i][j]].push_back(make_pair(i, j));

    int answer = 0;
    for(auto _ : s) {
        BipartiteMatching bp(2 * N);
        int size = _.second.size();
        for(auto p : _.second) {
            const int r = p.first;
            const int c = p.second;
            bp.add_edge(r, c + N);
        }
        answer += size - bp.matching();
    }
    cout << answer << endl;
}

int main(){
    iostream_init();
    int TC;
    cin >> TC;
    for(int testcase = 1; testcase <= TC; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
