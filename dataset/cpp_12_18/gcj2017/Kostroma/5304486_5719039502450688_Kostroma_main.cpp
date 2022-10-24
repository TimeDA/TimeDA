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
 
 int solve(int decreases, int buffs, int hd, int ad, int hk, int ak, int b, int d) {
     int initial_hd = hd;
     int res = decreases + buffs;
     for (int i = 0; i < decreases; ++i) {
         int new_ak = max(0, ak - d);
         if (new_ak >= hd) {
             ++res;
             hd = initial_hd - ak;
             if (hd <= 0) {
                 return -1;
             }
         }
         hd -= new_ak;
         if (hd <= 0) {
             return -1;
         }
         ak = new_ak;
     }
     for (int i = 0; i < buffs; ++i) {
         if (hd <= ak) {
             ++res;
             hd = initial_hd - ak;
             if (hd <= 0) {
                 return -1;
             }
         }
         hd -= ak;
         if (hd <= 0) {
             return -1;
         }
         ad += b;
     }
     int win = (hk + ad - 1) / ad;
     res += win;
     for (int i = 0; i + 1 < win; ++i) {
         if (hd <= ak) {
             ++res;
             hd = initial_hd - ak;
             if (hd <= 0) {
                 return -1;
             }
         }
         hd -= ak;
         if (hd <= 0) {
             return -1;
         }
     }
     return res;
 }
 
 void solve(bool read) {
     int hd, ad, hk, ak, b, d;
     cin >> hd >> ad >> hk >> ak >> b >> d;
     int ans = -1;
     for (int decreases = 0; decreases <= ak; ++decreases) {
         for (int buffs = 0; buffs <= hk; ++buffs) {
             int cur_res = solve(decreases, buffs, hd, ad, hk, ak, b, d);
             if (cur_res == -1) {
                 continue;
             }
             if (ans == -1 || ans > cur_res) {
                 ans = cur_res;
             }
         }
     }
 
     if (ans == -1) {
         cout << "IMPOSSIBLE\n";
     } else {
         cout << ans << "\n";
     }
 
 }