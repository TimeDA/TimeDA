#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
    cin >> t;
    int testNum = 1;
    while (t--) {
        cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

//#define int li
//const int mod = 1000000007;

bool dfs(int v, vector<vector<int>>& g, vector<int>& mt, vector<char>& used) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || dfs(mt[to], g, mt, used)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int get_matching(vector<vector<int>> g) {
    vector<int> mt(g.size(), -1);
    vector<char> used(g.size(), false);
    int ans = 0;
    for (int i = 0; i < g.size(); ++i) {
        used.assign(g.size(), false);
        if (dfs(i, g, mt, used)) {
            ++ans;
        }
    }
    return ans;
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;
    map<int, vector<vector<int>>> graphs;
    map<int, int> deg;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int col;
            cin >> col;
            if (!graphs.count(col)) {
                graphs[col].resize(n);
            }
            ++deg[col];
            graphs[col][i].push_back(j);
        }
    }
    int res = 0;
    for (auto item : graphs) {
        res += deg[item.first] - get_matching(item.second);
    }
    cout << res << "\n";

}