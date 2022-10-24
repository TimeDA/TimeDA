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

const int C = 500;
double dp[2][C];

double frac(double x) {
    return x - floor(x);
}

void solve(__attribute__((unused)) bool read) {
    int n, L;
    cin >> n >> L;
    vector<int> a(n);
    for (int i = 0; i < L; ++i) {
        cin >> a[i];
    }
    while (a.size() < n) {
        a.push_back(0);
    }
    L = n;
    double INF = 1e9;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < C; ++j) {
            dp[i][j] = -INF;
        }
    }
    int par = 0;
    dp[par][0] = 0;
    for (int pref = 0; pref < L; ++pref) {
        for (int j = 0; j < C; ++j) {
            dp[par ^ 1][j] = -INF;
        }
        for (int sum = 0; sum <= n; ++sum) {
            for (int cur = a[pref]; cur + sum <= n; ++cur) {
                if (dp[par][sum] < -INF / 2) {
                    continue;
                }
                int need = cur * 100 / n;
                double score = -frac(cur * 100.0 / n);
                if (cur * 200 >= n * (2 * need + 1)) {
                    score += 1;
                }
                //cout << pref << " " << sum << " " << cur << " " << score << " " << score + dp[par][sum] << "\n";
                dp[par ^ 1][sum + cur] = max(dp[par ^ 1][sum + cur], score + dp[par][sum]);
            }
        }
        par ^= 1;
    }
    int now = (int)round(dp[par][n]);
    now += 100;
    cout << now << "\n";

}