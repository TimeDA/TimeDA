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

#define int li
//const int mod = 1000000007;

int get_score(string s) {
    int r = 1;
    int dam = 0;
    for (char c : s) {
        if (c == 'S') {
            dam += r;
        } else {
            r *= 2;
        }
    }
    return dam;
}

void solve(__attribute__((unused)) bool read) {
    int d;
    cin >> d;
    string s;
    cin >> s;
    int res = 0;
    while (true) {
        int score = get_score(s);
        if (score <= d) {
            cout << res << "\n";
            return;
        }
        ++res;  
        auto q = s;
        sort(all(q));
        reverse(all(q));
        if (s == q) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        for (int i = (int)s.length() - 1; i > 0; --i) {
            if (s[i] == 'S' && s[i - 1] == 'C') {
                swap(s[i], s[i - 1]);
                break;
            }
        }
    }
}