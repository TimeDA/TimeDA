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
    //read = false;
    if (read) {
        cin >> n;
    } else {
        n = 100000;
    }
    vector<int> d(n), a(n), b(n);
    vector<int> first_vals(n), second_vals(n);
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> d[i] >> a[i] >> b[i];
        } else {
            d[i] = rand() % 100;
            a[i] = rand() % 100;
            b[i] = rand() % 100;
        }
        first_vals[i] = d[i] + a[i];
        second_vals[i] = d[i] - b[i];
    }
    if (!read) {
        sort(all(d));
    }
    vector<int> best_border(n);
    for (int i = 0; i < n; ++i) {
        best_border[i] = i + 1;
    }
    for (int w = 0; w < 2; ++w) {
        set<int> different;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || first_vals[i] != first_vals[i - 1]) {
                different.insert(i);
            }
        }
        different.insert(n);
        map<int, vector<int>> poses_by_second, poses_by_first;
        map<int, map<int, vector<int>>> poses_by_all;
        for (int i = 0; i < n; ++i) {
            poses_by_first[first_vals[i]].push_back(i);
            poses_by_second[second_vals[i]].push_back(i);
            poses_by_all[second_vals[i]][first_vals[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int r = *different.upper_bound(i);
            best_border[i] = max(best_border[i], r);
            if (r == n) {
                continue;
            }
            int fix_second = second_vals[r];
            int L = r, R = n + 1;
            auto& vec_all = poses_by_all[fix_second][first_vals[i]];
            auto& vec_second = poses_by_second[fix_second];
            auto& vec_first = poses_by_first[first_vals[i]];
            while (L + 1 < R) {
                int M = (L + R) / 2;
                int have_all = lower_bound(all(vec_all), M) - lower_bound(all(vec_all), i);
                int have_second = lower_bound(all(vec_second), M) - lower_bound(all(vec_second), i);
                int have_first = lower_bound(all(vec_first), M) - lower_bound(all(vec_first), i);
                if (have_second - have_all + have_first == M - i) {
                    L = M;
                } else {
                    R = M;
                }
            }
            best_border[i] = max(best_border[i], L);
        }
        swap(first_vals, second_vals);
    }

    int best_len = 0, vars = 0;
    for (int i = 0; i < n; ++i) {
        int r = best_border[i];
        if (r - i > best_len) {
            best_len = r - i;
            vars = 0;
        }
        if (r - i == best_len) {
            ++vars;
        }
    }
    cout << best_len << " " << vars << "\n";
}