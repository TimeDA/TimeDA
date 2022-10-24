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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] == 0 || a[n - 1] == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int border = 0;
    vector<string> res;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        int l = border;
        int r = l + a[i] - 1;
        int uk = 0;
        while (l < i) {
            while (uk >= res.size()) {
                res.push_back(string(n, '.'));
            }
            res[uk][l] = '\\';
            ++uk;
            ++l;
        }
        uk = 0;
        while (r > i) {
            while (uk >= res.size()) {
                res.push_back(string(n, '.'));
            }
            res[uk][r] = '/';
            ++uk;
            --r;
        }
        border += a[i];
    }
    res.push_back(string(n, '.'));
    cout << res.size() << "\n";
    for (auto item : res) {
        cout << item << "\n";
    }

}