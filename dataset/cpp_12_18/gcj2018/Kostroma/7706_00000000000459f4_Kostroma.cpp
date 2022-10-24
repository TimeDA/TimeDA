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

int n, m;

bool correct(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<int>> cur_matrix;
vector<vector<int>> used;
int TIMER = 0;

int dfs(int x, int y) {
    if (!correct(x, y) || used[x][y] == TIMER || cur_matrix[x][y] != TIMER) {
        return 0;
    }
    used[x][y] = TIMER;
    int res = 1;
    for (int k = 0; k < 4; ++k) {
        res += dfs(x + dx[k], y + dy[k]);
    }
    return res;
}

void solve(__attribute__((unused)) bool read) {
    //read = false;
    if (read) {
        cin >> n >> m;
    } else {
        n = 20;
        m = 20;
    }
    vector<string> matrix(n);
    int MAGIC = 1;
    while (MAGIC <= n || MAGIC <= m) {
        MAGIC *= 2;
    }
    using Matrix = vector<string>;
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> matrix[i];
        } else {
            for (int j = 0; j < m; ++j) {
                matrix[i] += "WB"[rand() % 2];
            }
        }
    }
    set<Matrix> to_check;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Matrix cur = {string(1, matrix[i][j])};
            to_check.insert(cur);
            if (j + 1 < m) {
                cur = {string(1, matrix[i][j]) + matrix[i][j + 1]};
                to_check.insert(cur);
            }
            if (i + 1 < n) {
                cur = {string(1, matrix[i][j]), string(1, matrix[i + 1][j])};
                to_check.insert(cur);
            }
            if (i + 1 < n && j + 1 < m) {
                cur = {string(1, matrix[i][j]) + matrix[i][j + 1], string(1, matrix[i + 1][j]) + matrix[i + 1][j + 1]};
                to_check.insert(cur);
            }
        }
    }
    int res = 0;
    used.assign(n, vector<int>(m, 0));
    cur_matrix.assign(n, vector<int>(m, 0));
    //cout << to_check.size() << "\n";
    for (auto& cur_large : to_check) {
        vector<string> large(MAGIC * cur_large.size(), string(MAGIC * cur_large[0].size(), 0));
        for (int i = 0; i < cur_large.size(); ++i) {
            for (int j = 0; j < cur_large[i].size(); ++j) {
                for (int a = 0; a < MAGIC; ++a) {
                    for (int b = 0; b < MAGIC; ++b) {
                        large[i * MAGIC + a][j * MAGIC + b] = cur_large[i][j];
                    }
                }
            }
        }
        for (int x = 0; x + n <= large.size(); ++x) {
            for (int y = 0; y + m <= large[x].size(); ++y) {
                ++TIMER;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (large[x + i][y + j] == matrix[i][j]) {
                            cur_matrix[i][j] = TIMER;
                        }
                    }
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        res = max(res, dfs(i, j));
                    }
                }
            }
        }
    }
    cout << res << "\n";
}