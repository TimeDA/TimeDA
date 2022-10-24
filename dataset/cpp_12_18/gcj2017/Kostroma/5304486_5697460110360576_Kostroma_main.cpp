#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 //#include "testlib.h"
 #include <bits/stdc++.h>
 using namespace std;
 
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve(bool);
 void precalc();
 clock_t start;
 //int timer = 1;
 
 int testNumber = 1;
 
 bool todo = true;
 
 int main() {
 #ifdef AIM
     freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
     freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
     //freopen("out.txt", "w", stdout);
 #else
     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
 #endif
     start = clock();
     int t = 1;
     cout.sync_with_stdio(0);
     cin.tie(0);
     precalc();
     cout.precision(10);
     cout << fixed;
     cin >> t;
     int testNum = 1;
     while (t--) {
         //cerr << testNum << endl;
         cout << "Case #" << testNum++ << ": ";
         solve(true);
         ++testNumber;
         //++timer;
     }
 #ifdef AIM1
     while (true) {
         solve(false);
     }
 #endif
 
 #ifdef AIM
     cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
     return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 template<typename T>
 T binpow(T q, T w, T mod) {
     if (!w)
         return 1 % mod;
     if (w & 1)
         return q * 1LL * binpow(q, w - 1, mod) % mod;
     return binpow(q * 1LL * q % mod, w / 2, mod);
 }
 
 template<typename T>
 T gcd(T q, T w) {
     while (w) {
         q %= w;
         swap(q, w);
     }
     return q;
 }
 template<typename T>
 T lcm(T q, T w) {
     return q / gcd(q, w) * w;
 }
 
 void precalc() {
 
 }
 
 //#define int li
 
 //const int mod = 1000000007;
 
 struct Point {
     int x, y;
     int id;
     Point() {}
     Point(int x, int y):x(x), y(y) {}
     Point operator - (const Point& other) const {
         return Point(x - other.x, y - other.y);
     }
     int operator * (const Point& other) const {
         return x * other.y - y * other.x;
     }
     void scan() {
         cin >> x >> y;
     }
 };
 
 void solve(bool read) {
     int n, p;
     cin >> n >> p;
     vector<int> r(n);
     for (int i = 0; i < n; ++i) {
         cin >> r[i];
     }
 
     /*cout << n << " " << p << endl;
     for (int x : r) {
         cout << x << " ";
     }
     cout << "\n";*/
 
     vector<vector<pair<int, int>>> have(n);
     vector<int> coords;
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < p; ++j) {
             int cur;
             cin >> cur;
             //cout << cur << " \n"[j + 1 == p];
 
             int min_x = (10 * cur + 11 * r[i] - 1) / (11 * r[i]);
             min_x = max(min_x, 1);
             int max_x = (10 * cur) / (9 * r[i]);
             if (min_x <= max_x) {
                 have[i].push_back({min_x, max_x});
                 coords.push_back(min_x);
                 coords.push_back(max_x);
                 //cerr << min_x << " " << max_x << endl;
             }
         }
     }
 
     for (int i = 0; i < n; ++i) {
         sort(all(have[i]));
         /*for (auto seg : have[i]) {
             cout << i << " " << seg.first << " " << seg.second << "\n";
         }*/
     }
 
     /*if (n == 1) {
         cout << have[0].size() << "\n";
         return;
     }*/
 
     /*if (n == 2) {
         if (have[0].size() > have[1].size()) {
             have[0].swap(have[1]);
         }
         vector<int> perm(have[1].size());
         for (int i = 0; i < have[1].size(); ++i) {
             perm[i] = i;
         }
         int ans = 0;
         do {
             int cur = 0;
             for (int j = 0; j < have[0].size(); ++j) {
                 if (max(have[0][j].first, have[1][perm[j]].first) <= min(have[0][j].second, have[1][perm[j]].second)) {
                     ++cur;
                 }
             }
             ans = max(ans, cur);
         }
         while (next_permutation(perm.begin(), perm.end()));
         cout << ans << "\n";
         return;
     }*/
 
     sort(all(coords));
     //coords.erase(unique(all(coords)), coords.end());
     int ans = 0;
     for (int x : coords) {
         while (true) {
             vector<int> to_erase;
             for (int i = 0; i < n; ++i) {
                 for (int j = 0; j < have[i].size(); ++j) {
                     if (have[i][j].first <= x && x <= have[i][j].second) {
                         to_erase.push_back(j);
                         break;
                     }
                 }
             }
             if (to_erase.size() == n) {
                 //cout << x << endl;
                 ++ans;
                 for (int i = 0; i < n; ++i) {
                     have[i].erase(have[i].begin() + to_erase[i]);
                 }
             } else {
                 break;
             }
         }
     }
 
     cout << ans << "\n";
 
 }