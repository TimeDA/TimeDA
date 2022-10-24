#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define PRINT(x)
 #define PRINT_CONT(x)
 #define PRINT_MSG(x)
 #endif
 
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <string>
 #include <cstring>
 #include <sstream>
 #include <algorithm>
 #include <memory.h>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cassert>
 using namespace std;
 
 
 // Enlarge MSVS stack size
 #pragma comment(linker, "/STACK:16777216")
 
 #define pb push_back
 #define all(c) c.begin(), c.end()
 #define mp(x, y) make_pair(x, y)
 #define sz(x) static_cast<int>(x.size())
 typedef long long int64;
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("0.in", "r", stdin);
     freopen("0.out", "w", stdout);
 }
 
 int solve(const vector<double>& first, const vector<double>& second)
 {
     vector<pair<double, int>> w;
     for (auto x : first) {
         w.pb(mp(x, 1));
     }
     for (auto x : second) {
         w.pb(mp(x, 2));
     }
     sort(all(w));
 
     int res = 0;
     int s = 0;
     for (int i = 0; i < w.size(); ++i) {
         if (w[i].second == 2) {
             s += 1;
         } else {
             s -= 1;
         }
         if (s > res) {
             res = s;
         }
     }
     return res;
 }
 
 int solve2(const vector<double>& first, const vector<double>& second)
 {
     vector<pair<double, int>> w;
     for (auto x : first) {
         w.pb(mp(x, 1));
     }
     for (auto x : second) {
         w.pb(mp(x, 2));
     }
     sort(all(w));
 
     int res = 0;
     int s = 0;
     for (int i = w.size() - 1; i >= 0; --i) {
         if (w[i].second == 2) {
             s += 1;
         } else {
             s -= 1;
         }
         res = max(res, s);
     }
     return first.size() - res;
     
 
     //int n = first.size();
     //int res = n;
 
     //for (auto y : w) {
     //    cerr << y.first << " " << y.second << endl;
     //}
     //
     //int left = 0, right = w.size() - 1;
     //while (left < right) {
     //    cerr << left << " " << right << endl;
     //    while (left < n && w[left].second != 1) {
     //        left += 1;
     //    }
     //    while (right >= 0 && w[right].second != 2) {
     //        right -= 1;
     //    }
     //    if (left < right) {
     //        res -= 1;
     //        left += 1;
     //        right -= 1;
     //    }
     //}
     //return res;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         //cerr << endl;
         int n;
         cin >> n;
         vector<double> first, second;
         for (int i = 0; i < n; ++i) {
             double num;
             cin >> num;
             first.pb(num);
         }
         for (int i = 0; i < n; ++i) {
             double num;
             cin >> num;
             second.pb(num);
         }
         int r1 = solve(first, second);
         int r2 = solve2(first, second);
         printf("Case #%d: %d %d\n", tt, r2, r1);
     }
     
     return 0;
 }
