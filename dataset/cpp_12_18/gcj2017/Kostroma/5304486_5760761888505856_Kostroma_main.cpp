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
         cout << "Case #" << testNum++ << ":\n";
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
     int n, m;
     cin >> n >> m;
     vector<string> s(n);
     bool has_first = false;
     int first_id = -1;
     for (int i = 0; i < n; ++i) {
         cin >> s[i];
         char first_val = 0, last_val = 0;
         for (int j = 0; j < m; ++j) {
             if (s[i][j] != '?') {
                 if (!first_val) {
                     first_val = s[i][j];
                 }
                 last_val = s[i][j];
             }
             if (last_val) {
                 s[i][j] = last_val;
             }
         }
         if (first_val) {
             for (int j = 0; j < m; ++j) {
                 if (s[i][j] == '?') {
                     s[i][j] = first_val;
                 }
             }
             if (!has_first) {
                 has_first = true;
                 first_id = i;
             }
         } else {
             if (has_first) {
                 s[i] = s[i - 1];
             }
         }
     }
     for (int i = 0; i < n; ++i) {
         if (s[i][0] == '?') {
             s[i] = s[first_id];
         }
     }
     for (int i = 0; i < n; ++i) {
         cout << s[i] << "\n";
     }
 
 }