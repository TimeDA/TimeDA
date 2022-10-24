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

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

//#define int li
//const int mod = 1000000007;

const int C = 510;
int res[C][C];

int cur_dp[C][C];
int next_dp[C][C];

void precalc() {
    int pref_a = 0;
    for (int a = 0; a < C; ++a) {
        pref_a += a;
        if (pref_a >= C) {
            break;
        }
        for (int b = 0; b < C; ++b) {
            int used_a = (b + 1) * a, used_b = b * (b + 1) / 2;
            if (used_a >= C || used_b >= C) {
                break;
            }
            for (int have_a = 0; have_a + used_a < C; ++have_a) {
                for (int have_b = 0; have_b + used_b < C; ++have_b) {
                    int& new_dp = next_dp[have_a + used_a][have_b + used_b];
                    new_dp = max(new_dp, cur_dp[have_a][have_b] + b + 1);
                }
            }
        }
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                cur_dp[i][j] = next_dp[i][j];
            }
        }
    }
}

void solve(__attribute__((unused)) bool read) {
    int r, b;
    cin >> r >> b;
    cout << cur_dp[r][b] - 1 << "\n";
}