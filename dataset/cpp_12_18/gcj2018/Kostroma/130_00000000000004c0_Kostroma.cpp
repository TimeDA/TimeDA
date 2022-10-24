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
        //cout << "Case #" << testNum++ << ": ";
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
    static int timer = 1;
    cout << "Case #" << timer++ << ": ";
    int n;
    cin >> n;
    set<pair<int, int>, greater<pair<int, int>>> a;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        a.insert({cur, i});
    }
    vector<string> res;
    while (!a.empty()) {
        res.push_back("");
        auto cur_item = *a.begin();
        auto next_item = *(++a.begin());
        if (a.size() == 2 && cur_item.first == next_item.first) {
            res.back() += (char)('A' + cur_item.second);
            res.back() += (char)('A' + next_item.second);
            a.erase(cur_item);
            a.erase(next_item);
            --cur_item.first;
            --next_item.first;
            if (cur_item.first) {
                a.insert(cur_item);
                a.insert(next_item);
            }
        } else {

            // aa
            a.erase(cur_item);
            res.back() += (char)('A' + cur_item.second);
            --cur_item.first;
            if (cur_item.first) {
                a.insert(cur_item);
            }
        }
    }
    for (auto s : res) {
        cout << s << " ";
    }
    cout << "\n";
}