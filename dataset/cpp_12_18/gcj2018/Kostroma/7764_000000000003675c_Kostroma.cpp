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

void solve(__attribute__((unused)) bool read) {
    int n;
    vector<vector<int>> g;
    vector<int> cur_sum;
    int ANS = 0;
    //read = false;
    if (read) {
        cin >> n;
    } else {
        n = 8;
    }
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        g[i].resize(2);
        if (read) {
            cin >> g[i][0] >> g[i][1];
            --g[i][0];
            --g[i][1];
        } else {
            g[i][0] = rand() % n;
            g[i][1] = rand() % n;
        }
    }
    cur_sum.resize(n);
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> cur_sum[i];
        } else {
            cur_sum[i] = 8;
        }
    }
    vector<int> cur_q;
    cur_q.push_back(0);
    vector<char> used(n, false);
    used[0] = true;
    for (int i = 0; i < cur_q.size(); ++i) {
        int v = cur_q[i];
        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                cur_q.push_back(to);
            }
        }
    }
    set<vector<int>> reachable;
    queue<vector<int>> q;
    q.push(cur_sum);
    reachable.insert(cur_sum);
    while (!q.empty()) {
        auto vec = q.front();
        q.pop();
        int cur_res = vec[0];
        if (g[0][0] && g[0][1]) {
            cur_res += min(vec[g[0][0]], vec[g[0][1]]);
        }
        ANS = max(ANS, cur_res);
        for (int i = 1; i < vec.size(); ++i) {
            int l = g[i][0], r = g[i][1];
            if (l == i || r == i || !used[i]) {
                continue;
            }
            if (vec[l] > 0 && vec[r] > 0) {
                --vec[l];
                --vec[r];
                ++vec[i];
                if (!reachable.count(vec)) {
                    reachable.insert(vec);
                    q.push(vec);
                }
                ++vec[l];
                ++vec[r];
                --vec[i];
            }
        }
    }
    cout << ANS << "\n";
}